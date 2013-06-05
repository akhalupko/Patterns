#include <process.h>
#include <Windows.h>

#include <Customer.h>
#include <Elevator.h>

const unsigned N = 10;

Elevator* elevator;

HANDLE hHandles[N];

unsigned k = 0;

DWORD WINAPI CustomerThread( _In_ LPVOID pParams )
{
	Customer customer( *elevator, rand() % 25 + 1 );

	Sleep( rand() % 300 + 100 );

	customer.CallElevator();
	
	return S_OK;
}

void main()
{
	DWORD threadID;

	elevator = new Elevator;
	srand( GetTickCount() );
	for( unsigned i = 0; i < N; ++i )
	{
		hHandles[i] = ::CreateThread( NULL, 0, &CustomerThread, NULL, 0, &threadID );	
	}

	WaitForMultipleObjects( N, hHandles, TRUE, INFINITE );

	delete elevator;
}