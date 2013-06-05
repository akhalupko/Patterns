#include <iostream>

#include <string>

using namespace std;

class Player
{
public:
					Player()
						: _health( 100 )
						, _shield( 100 )
						, _ammo( 50 )
					{

					}

	void			GotHit( unsigned damage )
					{
						if( (int)_health - (int)damage < 0 )
						{
							_health = 0;
							if( (int)damage - (int)_health - (int)_shield > 0 )
							{
								_shield = 0;
								cout << "Player killed." << endl << *this; 
								LoadCheckpoint();
							}
							else
							{
								_shield -= ( (int)damage - (int)_health );
							}
						}
					}

	void			Shoot()
					{
						_ammo--;
					}

	void			PassCheckpoint()
					{
						_lastCheckpoint = Checkpoint( *this );
					}

	void			LoadCheckpoint()
					{
						_lastCheckpoint.RestorePlayer( *this );
					}
private:
	unsigned		_health;
	unsigned		_shield;
	unsigned		_ammo;

	// Memento
	class Checkpoint
	{
	public:
					Checkpoint()
					{

					}

					Checkpoint( Player& player )
						: _health( player._health )
						, _shield( player._shield )
						, _ammo( player._ammo )
					{

					}

		void		RestorePlayer( Player& player )
					{
						player._health = _health;
						player._shield = _shield;
						player._ammo = _ammo;
					}
	
		unsigned	GetHealth()
					{
						return _health;
					}
		unsigned	GetShield()
					{
						return _shield;
					}
		unsigned	GetAmmo()
					{
						return _ammo;
					}

	private:
		unsigned	_health;
		unsigned	_shield;
		unsigned	_ammo;
	};

	Checkpoint		_lastCheckpoint;

	friend ostream& operator<<( ostream& os, const Player& player );
};

ostream& operator<<( ostream& os, const Player& player )
{
	os << "Player status: \n\tHealth - " << player._health << "\n\tShield - " << player._shield << "\n\tAmmo - " << player._ammo << endl;
	return os;
}

void main()
{
	Player player;

	cout << player;
	player.PassCheckpoint();

	player.GotHit( 10 );
	player.Shoot();
	cout << player;

	player.GotHit( 195 );

	player.Shoot();
	cout << player;
}