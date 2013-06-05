#ifndef ADDPRODUCTCOMMAND_H
#define ADDPRODUCTCOMMAND_H

#include <AbstractCommand.h>

//////////////////////////////////////////////////////////////////////////
// AddProductCommand
//////////////////////////////////////////////////////////////////////////
class AddProductCommand : public AbstractCommand
{
public:
							AddProductCommand( Order* order, ProductInOrder* product );
					
	virtual					~AddProductCommand();

	virtual bool			Execute();
	virtual bool			UnExecute();

	virtual std::string		GetCommandName()
							{
								return "AddProduct";
							}

private:
	ProductInOrder*			_product;
};

#endif // ADDPRODUCTCOMMAND_H