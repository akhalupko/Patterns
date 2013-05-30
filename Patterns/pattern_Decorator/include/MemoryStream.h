#ifndef MEMORYSTREAM_H
#define MEMORYSTREAM_H

#include <AbstractStream.h>

class MemoryStream : public AbstractStream
{
public:
					MemoryStream();
	virtual			~MemoryStream();

	virtual int		PutBytes( unsigned char* bytes, unsigned size );
	virtual int		PutInt( int number );
	virtual void	HandleBufferFull();

private:
	unsigned			_currentPos;
	const unsigned	int	_bufferSize;
	unsigned char*		_buffer;
};

#endif // MEMORYSTREAM_H