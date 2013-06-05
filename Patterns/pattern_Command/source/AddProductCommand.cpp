#include <Order.h>
#include <AddProductCommand.h>

AddProductCommand::AddProductCommand( Order* order, ProductInOrder* product )
	: AbstractCommand( order )
	, _product( product )
{

}

AddProductCommand::~AddProductCommand()
{
	delete _product;
}

bool AddProductCommand::Execute()
{
	ProductVector& products = GetOrder()->GetProductVector();

	bool existing = false;

	for( unsigned i = 0, n = products.size(); i < n; ++i )
	{
		if( products[i]->GetUID() == _product->GetUID() )
		{
			products[i]->AddCount( _product->GetCount() );
			
			existing = true;

			break;
		}
	}

	if( !existing )
	{
		products.push_back( _product );
	}

	return true;
}

bool AddProductCommand::UnExecute()
{
	ProductVector& products = GetOrder()->GetProductVector();

	for( unsigned i = 0, n = products.size(); i < n; ++i )
	{
		if( products[i]->GetUID() == _product->GetUID() )
		{
			if( products[i]->GetCount() == _product->GetCount() )
			{
				for( unsigned j = i, n = products.size()-1; j < n; ++j )
				{
					products[j] = products[j+1];
				}
				products.pop_back();
			}
			else
			{
				products[i]->AddCount( -(int)_product->GetCount() );
			}

			break;
		}
	}

	return true;
}