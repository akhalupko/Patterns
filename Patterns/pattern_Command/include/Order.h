#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////////////
// ProductInOrder
//////////////////////////////////////////////////////////////////////////
class ProductInOrder
{
public:	
						ProductInOrder( std::string& name, unsigned price, unsigned uid, unsigned count = 1 )
							: _name( name )
							, _price( price )
							, _uid( uid )
							, _count( count )
						{

						}

						ProductInOrder( unsigned uid, unsigned count = 1, unsigned price = 0 )
							: _uid( uid )
							, _count( count )
							, _price( price )
						{
 
						}
					
	void				AddCount( int count = 1 )
						{
							int temp = _count + count; 
							_count = (unsigned)temp;
						}

	unsigned			GetUID()
						{
							return _uid;
						}
	unsigned			GetCount()
						{
							return _count;
						}

	unsigned			GetPrice()
						{
							return _price;
						}
	void 				SetPrice( unsigned price )
						{
							_price = price;
						}

	std::string&		GetName()
						{
							return _name;
						}
	void				SetName( std::string& name )
						{
							_name = name;
						}
	
private:
	std::string			_name;
	unsigned			_price;
	unsigned			_count;
	unsigned			_uid;
};

typedef std::vector<ProductInOrder*> ProductVector;

//////////////////////////////////////////////////////////////////////////
// Order
//////////////////////////////////////////////////////////////////////////
class Order
{
public:
						Order( unsigned guid )
							: _guid( guid )
						{
							_products.reserve( 5 );
						}

						~Order()
						{
							for( unsigned i = 0; i < _products.size(); ++i )
							{
								delete _products[i];
							}
						}

	ProductVector&		GetProductVector()
						{
							return _products;
						}
private:
	ProductVector		_products;

	unsigned			_guid;
};

#endif // ORDER_H