#ifndef ABSTRACTSTREAM_H
#define ABSTRACTSTREAM_H

class AbstractStream
{
public:
	virtual			~AbstractStream() {};

	virtual int		PutBytes( unsigned char* bytes, unsigned size ) = 0;

	virtual int		PutInt( int number ) = 0;

	virtual void	HandleBufferFull() = 0;
};

#endif // ABSTRACTSTREAM_H