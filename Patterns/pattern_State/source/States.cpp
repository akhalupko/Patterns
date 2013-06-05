#include <States.h>

void ElevatorIdle::Call( Elevator* elevator, unsigned floor )
{
	elevator->SetState( new ElevatorBusy );
	elevator->Go( floor );
}

void ElevatorBusy::Call( Elevator* elevator, unsigned floor )
{
	elevator->Append( floor );
}