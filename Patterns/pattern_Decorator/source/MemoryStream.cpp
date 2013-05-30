#include <fstream>

#include <MemoryStream.h>

MemoryStream::MemoryStream()
	: _bufferSize( 256 )
	, _currentPos( 0 )
{
	_buffer = new unsigned char[_bufferSize];
}

MemoryStream::~MemoryStream()
{
	delete[] _buffer;
}

int MemoryStream::PutBytes( unsigned char* bytes, unsigned size )
{
	if( size > _bufferSize )
	{
		return -1;
	}

	if( size > _bufferSize - _currentPos )
	{
		return 0;
	}

	for( unsigned i = 0, j = 0; i < _currentPos + size; ++i )
	{
		_buffer[i] = bytes[j++];
	}

	_currentPos += size;

	return 1;
}

int MemoryStream::PutInt( int number )
{
	return PutBytes( ((unsigned char*)&number), 1 );
}

void MemoryStream::HandleBufferFull()
{
	using namespace std;

	ofstream os( "memory.txt" );

	os.write( (char*)_buffer, _currentPos );

	_currentPos = 0;
}