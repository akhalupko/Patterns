#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>

class Character
{
public:
	virtual void		print() const = 0;

protected:
	char		_symbol;
	int			_width;
	int			_height;
	int			_pointSize;
};

class ConcreteCharacter : public Character
{
public:
	ConcreteCharacter( char symbol, int pointSize )
	{
		_symbol = symbol;
		_height = 32;
		_width = 18;
		_pointSize = pointSize;
	}

	virtual void		print() const
	{
		std::cout << _symbol << std::endl;
	}
};

#endif // FLYWEIGHT_H