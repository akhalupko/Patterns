#ifndef ABSTRACTCOMMAND_H 
#define ABSTRACTCOMMAND_H

#include <string>

#include <Order.h>

//////////////////////////////////////////////////////////////////////////
// AbstractCommand
//////////////////////////////////////////////////////////////////////////
class AbstractCommand
{
public:
							AbstractCommand( Order* order )
								: _order( order )
							{

							}

	virtual					~AbstractCommand() {}

	virtual bool			Execute() = 0;
	virtual bool			UnExecute() = 0;

	virtual std::string		GetCommandName() = 0;

	Order*					GetOrder()
							{
								return _order;
							}
private:
	Order*					_order;
};

#endif // ABSTRACTCOMMAND_H