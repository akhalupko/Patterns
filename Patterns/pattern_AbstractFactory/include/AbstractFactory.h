#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

// abstract product
class IPlayer
{
public:
	virtual				~IPlayer() {};
	virtual	void		PrintPosition() = 0;
};

// abstract factory
class IPlayerFactory
{
public:
	virtual	IPlayer*	CreatePlayer() = 0;
};

#endif // CONCRETEFACTORY_H