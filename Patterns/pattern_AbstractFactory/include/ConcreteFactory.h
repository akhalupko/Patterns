#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H

#include <AbstractFactory.h>

using std::cout;
using std::endl;

// concrete product
class PointGuard : public IPlayer
{
public:
	virtual				~PointGuard();

	virtual	void		PrintPosition();
};

// concrete factory
class PointGuardFactory : public IPlayerFactory
{
public:
	virtual	IPlayer*	CreatePlayer();
};

// concrete product
class ShootingGuard : public IPlayer
{
public:
	virtual				~ShootingGuard();
	
	virtual	void		PrintPosition();
};

// concrete factory
class ShootingGuardFactory : public IPlayerFactory
{
public:
	virtual	IPlayer*	CreatePlayer();
};

#endif // CONCRETEFACTORY_H