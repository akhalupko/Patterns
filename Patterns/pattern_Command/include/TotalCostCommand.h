#ifndef TOTALCOSTCOMMAND_H
#define TOTALCOSTCOMMAND_H

#include <AbstractCommand.h>

//////////////////////////////////////////////////////////////////////////
// TotalCostCommand
//////////////////////////////////////////////////////////////////////////
class TotalCostCommand : public AbstractCommand
{
public:
							TotalCostCommand( Order* order );

	virtual					~TotalCostCommand() {}

	virtual bool			Execute();
	virtual bool			UnExecute();

	virtual std::string		GetCommandName()
	{
		return "TotalCost";
	}

private:

};

#endif // TOTALCOSTCOMMAND_H