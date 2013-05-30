#include <MemoryStream.h>
#include <CompressedStream.h>
#include <FactoryMethodClasses.h>

void main()
{
	MemoryStream mStream = MemoryStream();

	CompressedStreamFactory csFactory;
	ASCII7StreamFactory asFactory;
	AbstractStream* cStream1 = csFactory.factoryMethod( mStream );
	
	unsigned char bytes[257];

	for( unsigned i = 0; i < 257; ++i )
	{
		bytes[i] = 125;
	}

	cStream1->PutBytes( bytes, 128 );

	AbstractStream* aStream2 = asFactory.factoryMethod( *cStream1 );
	
	aStream2->PutBytes( bytes, 128 );
	aStream2->PutInt( bytes[256] );
	aStream2->HandleBufferFull();

	delete cStream1;
	delete aStream2;
}