#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <States.h>
#include <vector>

class ElevatorState;

//////////////////////////////////////////////////////////////////////////
// Elevator
//////////////////////////////////////////////////////////////////////////
class Elevator
{
public:
							Elevator();

	void					Call( unsigned floor );

	void					Go( unsigned floor );

	void					SetState( ElevatorState* state );

	void					Append( unsigned num );
private:
	ElevatorState*			_state;
	std::vector<unsigned>	_callsQueue;
	unsigned				_currentFloor;
};

#endif // ELEVATOR_H