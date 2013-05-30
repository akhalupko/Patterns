#include <iostream>

#include <Flyweight.h>
#include <FlyweightFactory.h>

void main()
{
	std::string document = "AAZZBBZB";

	FlyweightFactory characterFactory;

	for( std::string::const_iterator it = document.begin(); it != document.end(); ++it)
	{
		const Character& character = characterFactory.GetCharacter( *it );
		character.print();
	}
}