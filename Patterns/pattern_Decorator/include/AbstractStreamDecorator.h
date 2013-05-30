#ifndef ISTREAMDECORATOR_H
#define ISTREAMDECORATOR_H

#include <AbstractStream.h>

class AbstractStreamDecorator : public AbstractStream
{
public:
						AbstractStreamDecorator( AbstractStream& stream )
							: _stream( stream )
						{

						};

	virtual				~AbstractStreamDecorator() {}

	virtual int	PutBytes( unsigned char* bytes, unsigned size )
	{
		return _stream.PutBytes( bytes, size );
	}

	virtual int	PutInt( int number )
	{
		return _stream.PutInt( number );
	}

	virtual void HandleBufferFull()
	{
		_stream.HandleBufferFull();
	}

protected:
	AbstractStream&		_stream;
};

#endif // ISTREAMDECORATOR_H