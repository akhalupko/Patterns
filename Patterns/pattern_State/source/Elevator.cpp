#include <iostream>

#include <Elevator.h>

Elevator::Elevator()
	: _currentFloor( 0 )
	, _state( new ElevatorIdle() )
{

}

void Elevator::Call( unsigned floor )
{
	_state->Call( this, floor );
}

void Elevator::Go( unsigned floor )
{
	
	std::cout << "Elevator went to " << floor << " floor." << std::endl;
	
	_currentFloor = floor;

	if( _callsQueue.size() > 0 )
	{
		unsigned nextFloor = _callsQueue.back();
		_callsQueue.pop_back();
		Go( nextFloor );
	}
	else
	{
		SetState( new ElevatorIdle() );
	}
}

void Elevator::SetState( ElevatorState* state )
{
	_state = state;
}

void Elevator::Append( unsigned num )
{
	_callsQueue.push_back( num );
}