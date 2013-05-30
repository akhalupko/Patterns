#include <ConcreteFactory.h>

void UseGuards( IPlayerFactory* f )
{
	IPlayer*  guard		=  f->CreatePlayer();

	guard->PrintPosition();

	delete guard;
}

void main()
{
	IPlayerFactory* pgFactory = new PointGuardFactory;
	IPlayerFactory* sgFactory = new ShootingGuardFactory;

	UseGuards( pgFactory );
	UseGuards( sgFactory );

	delete pgFactory;
	delete sgFactory;
}