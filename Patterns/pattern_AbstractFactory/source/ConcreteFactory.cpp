#include <iostream>

#include <ConcreteFactory.h>

using std::cout;
using std::endl;

// PointGuard
PointGuard::~PointGuard()
{

}

void PointGuard::PrintPosition()
{
	cout << "This is a point guard." << endl;
}

// PointGuardFactory
IPlayer* PointGuardFactory::CreatePlayer()
{
	return new PointGuard;
}

// ShootigGuard
ShootingGuard::~ShootingGuard()
{

}

void ShootingGuard::PrintPosition()
{
	cout << "This is a shooting guard." << endl;
}

// ShootingGuardFactory
IPlayer* ShootingGuardFactory::CreatePlayer()
{
	return new ShootingGuard;
}


