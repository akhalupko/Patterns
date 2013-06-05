#include <iostream>

#include <TotalCostCommand.h>

using std::cout;
using std::endl;

TotalCostCommand::TotalCostCommand( Order* order )
	: AbstractCommand( order )
{

}

bool TotalCostCommand::Execute()
{
	ProductVector& products = GetOrder()->GetProductVector();

	if( products.size() == 0 )
	{
		cout << "Order is empty" << endl;
		return false;
	}

	unsigned cost = 0;
	for( unsigned i = 0, n = products.size(); i < n; ++i )
	{
		cost += products[i]->GetPrice() * products[i]->GetCount();
	}

	cout << "Total cost = " << cost << endl;

	return true;
}

bool TotalCostCommand::UnExecute()
{
	return true;
}