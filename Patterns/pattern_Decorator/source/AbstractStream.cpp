#include <AbstractStream.h>

AbstractStream::AbstractStream()
	: _bufferSize( 1000 )
	, _currentPos( 0 )
	, _stream( std::cout )
{
	_buffer = new byte[_bufferSize];
}

AbstractStream::~AbstractStream()
{
	delete[] _buffer;
}

void AbstractStream::SetStream( ostream& stream )
{
	_stream = stream;
}

ostream& AbstractStream::GetStream()
{
	return _stream;
}

void AbstractStream::PutBytes( byte* bytes, unsigned size )
{
	if( size > _bufferSize )
	{
		return;
	}

	if( size > _bufferSize - _currentPos )
	{
		HandleBufferFull();
	}

	for( unsigned i = 0, j = 0; i < _currentPos + size; ++i )
	{
		_buffer[i] = bytes[j++];
	}

	_currentPos += size;
}

void AbstractStream::PutInt( int number )
{
	PutBytes( &((byte)number), 1 );
}

void AbstractStream::HandleBufferFull()
{
	for( unsigned i = 0; i < _currentPos; ++i )
	{
		_stream << _buffer[i];
	}
}