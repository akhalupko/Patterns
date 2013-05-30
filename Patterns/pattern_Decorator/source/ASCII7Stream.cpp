#include <iostream>
#include <Windows.h>

#include <ASCII7Stream.h>

ASCII7Stream::ASCII7Stream( AbstractStream& stream )
	: AbstractStreamDecorator( stream )
{

}

ASCII7Stream::~ASCII7Stream()
{

}

int ASCII7Stream::PutBytes( unsigned char* bytes, unsigned size )
{
	if( AbstractStreamDecorator::PutBytes( bytes, size ) == 0 )
	{
		HandleBufferFull();
		AbstractStreamDecorator::PutBytes( bytes, size );
	}

	return 1;
}

int ASCII7Stream::PutInt( int number )
{
	if( AbstractStreamDecorator::PutInt( number ) == 0 )
	{
		HandleBufferFull();
		AbstractStreamDecorator::PutInt( number );
	}

	return 1;
}

void ASCII7Stream::HandleBufferFull()
{
	Convert();
	AbstractStreamDecorator::HandleBufferFull();
}

void ASCII7Stream::Convert()
{
	std::cout << "Converting... ";
	Sleep( rand() % 500 + 500 );
	std::cout << "Succeed." << std::endl;
}