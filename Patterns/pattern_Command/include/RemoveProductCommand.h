#ifndef REMOVEPRODUCTCOMMAND
#define REMOVEPRODUCTCOMMAND

#include <AbstractCommand.h>

//////////////////////////////////////////////////////////////////////////
// RemoveProductCommand
//////////////////////////////////////////////////////////////////////////
class RemoveProductCommand : public AbstractCommand
{
public:
							RemoveProductCommand( Order* order, ProductInOrder* product );

	virtual					~RemoveProductCommand();

	virtual bool			Execute();
	virtual bool			UnExecute();

	virtual std::string		GetCommandName()
	{
		return "RemoveProduct";
	}

private:
	ProductInOrder*			_product;
};

#endif // REMOVEPRODUCTCOMMAND