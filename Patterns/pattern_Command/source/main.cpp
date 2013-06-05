#include <iostream>
#include <string>

#include <Order.h>
#include <AbstractCommand.h>
#include <AddProductCommand.h>
#include <RemoveProductCommand.h>
#include <TotalCostCommand.h>
#include <RequestHandler.h>

void main()
{
	Order* order = new Order( 1 );

	RequestHandler handler;

	handler.Do( new AddProductCommand( order, new ProductInOrder( std::string( "cake" ), 100, 2 ) ) );

	handler.Do( new AddProductCommand( order, new ProductInOrder( std::string( "water" ), 200, 3 ) ) );

	handler.Do( new AddProductCommand( order, new ProductInOrder( std::string( "cake" ), 100, 2 ) ) );

	handler.Do( new TotalCostCommand( order ) );

	handler.Do( new RemoveProductCommand( order, new ProductInOrder( 2, 1 ) ) );

	handler.Do( new TotalCostCommand( order ) );

	handler.Undo( 2 );

	handler.Redo( 2 );
}