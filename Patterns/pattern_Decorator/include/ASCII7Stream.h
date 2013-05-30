#ifndef ASCIISTREAM_H
#define ASCIISTREAM_H

#include <AbstractStreamDecorator.h>

class ASCII7Stream : public AbstractStreamDecorator
{
public:
	ASCII7Stream( AbstractStream& stream );
	virtual			~ASCII7Stream();

	virtual int		PutBytes( unsigned char* bytes, unsigned size );
	virtual int		PutInt( int number );
	virtual void	HandleBufferFull();

private:
	void			Convert();
};

#endif // ASCIISTREAM_H