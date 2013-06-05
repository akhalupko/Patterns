#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <vector>

#include <AbstractCommand.h>

//////////////////////////////////////////////////////////////////////////
// Invoker
//////////////////////////////////////////////////////////////////////////
class RequestHandler
{
public:
						RequestHandler();
						~RequestHandler();

	bool				Do( AbstractCommand* command, unsigned times = 1 );
	bool				Redo( unsigned size = 1 );
	bool				Undo( unsigned size = 1 );

private:
	typedef	std::vector<AbstractCommand*> CommandVector;
	CommandVector		_commands;

	typedef CommandVector::iterator CommandIterator;
	CommandIterator		_lastMade;
};

#endif // REQUESTHANDLER_H