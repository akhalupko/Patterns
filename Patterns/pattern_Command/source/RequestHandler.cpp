#include <RequestHandler.h>

#include <iostream>

using std::cout;
using std::endl;

RequestHandler::RequestHandler()
{
	_commands.reserve( 10 );
	_lastMade = _commands.begin();
}

RequestHandler::~RequestHandler()
{
	for( unsigned i = 0, n = _commands.size(); i < n; ++i )
	{
		delete _commands[i];
	}
}

bool RequestHandler::Do( AbstractCommand* command, unsigned times )
{
	if( _commands.size() > 0 && _lastMade != _commands.end() - 1 )
	{
		unsigned i = _commands.size() - 1;
		for( CommandIterator j = _lastMade + 1, n = _commands.end(); j != n; ++j )
		{
			delete _commands[i--];		
		}
		_commands.erase( _lastMade + 1, _commands.end() );
	}

	for( unsigned i = 0; i < times; ++i )
	{
		cout << "Performing command " << command->GetCommandName() << endl;
		_commands.push_back( command );
		_lastMade = _commands.end() - 1;
		if( !(*_lastMade)->Execute() )
		{
			_lastMade = _commands.end() - 2;
			cout << "Command " << command->GetCommandName() << " execution failed." << endl;
			delete _commands.back();
			return false;
		}
	}
	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	return true;
}

bool RequestHandler::Redo( unsigned size )
{
	if( _lastMade + size >= _commands.end() )
	{
		size = _commands.end() - _lastMade - 1;
	}

	while( size > 0 )
	{
		++_lastMade;
		--size;
		cout << "Redoing command " << (*_lastMade)->GetCommandName() << endl;
		if( !(*_lastMade)->Execute() )
		{
			cout << "Command " << (*_lastMade)->GetCommandName() << " execution failed." << endl;
			return false;
		}
	}
	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	return true;
}

bool RequestHandler::Undo( unsigned size )
{
	if( _lastMade < _commands.begin() + size )
	{
		size = _lastMade < _commands.begin();
	}

	while( size > 0 )
	{
		--size;
		cout << "Undoing command " << (*_lastMade)->GetCommandName() << endl;
		if( !(*_lastMade)->UnExecute() )
		{
			cout << "Command " << (*_lastMade)->GetCommandName() << " unexecution failed." << endl;
			return false;
		}
		_lastMade--;
	}
	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	return true;
}

