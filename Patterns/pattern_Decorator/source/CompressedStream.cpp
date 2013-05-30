#include <iostream>
#include <Windows.h>

#include <CompressedStream.h>

CompressedStream::CompressedStream( AbstractStream& stream )
	: AbstractStreamDecorator( stream )
{

}

CompressedStream::~CompressedStream()
{

}

int CompressedStream::PutBytes( unsigned char* bytes, unsigned size )
{
	if( AbstractStreamDecorator::PutBytes( bytes, size ) == 0 )
	{
		HandleBufferFull();
		AbstractStreamDecorator::PutBytes( bytes, size );
	}

	return 1;
}

int CompressedStream::PutInt( int number )
{
	if( AbstractStreamDecorator::PutInt( number ) == 0 )
	{
		HandleBufferFull();
		AbstractStreamDecorator::PutInt( number );
		return 0;
	}

	return 1;
}

void CompressedStream::HandleBufferFull()
{
	Compress();
	AbstractStreamDecorator::HandleBufferFull();
}

void CompressedStream::Compress()
{
	std::cout << "Compressing... ";
	Sleep( rand() % 500 + 500 );
	std::cout << "Succeed." << std::endl;
}