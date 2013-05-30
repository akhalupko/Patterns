#ifndef FFACTORY_H
#define FFACTORY_H

#include <map>

#include <Flyweight.h>

class FlyweightFactory
{
public:
	const Character& GetCharacter( char key )
	{
		const Characters::iterator it = _Characters.find( key );
		if ( _Characters.end() == it )
		{
			const Character* character = new ConcreteCharacter(key, 12);
			_Characters[key] = character;
			return *character;
		}
		else
		{
			return *it->second;
		}
	}

	virtual ~FlyweightFactory()
	{
		for( Characters::const_iterator it = _Characters.begin(); it != _Characters.end(); ++it )
		{
			delete it->second;
		}
	}

private:
	typedef std::map< char, const Character* > Characters;   
	Characters _Characters;
};

#endif // FFACTORY_H