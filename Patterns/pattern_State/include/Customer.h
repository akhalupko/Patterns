#ifndef	CUSTOMER_H 
#define CUSTOMER_H

#include <iostream>

#include <Elevator.h>

//////////////////////////////////////////////////////////////////////////
// Customer
//////////////////////////////////////////////////////////////////////////
class Customer
{
public:
				Customer( Elevator& elevator, unsigned floor )
					: _elevator( elevator )
					, _floor( floor )
				{

				}

	void		CallElevator()
				{
					std::cout << "Customer have been call elevator from " << _floor << " floor" << std::endl;
					_elevator.Call( _floor );
				}

private:
	unsigned	_floor;
	Elevator&	_elevator;
};


#endif // CUSTOMER_H