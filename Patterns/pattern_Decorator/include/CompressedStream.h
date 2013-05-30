#ifndef COMPRESSEDSTREAM_H
#define COMPRESSEDSTREAM_H

#include <AbstractStreamDecorator.h>

class CompressedStream : public AbstractStreamDecorator
{
public:
						CompressedStream( AbstractStream& stream );
		virtual			~CompressedStream();
		
		virtual int		PutBytes( unsigned char* bytes, unsigned size );
		virtual int		PutInt( int number );
		virtual void	HandleBufferFull();

private:
		void			Compress();
};

#endif // COMPRESSEDSTREAM_H