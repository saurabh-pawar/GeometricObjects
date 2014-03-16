#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <types.h>

namespace TESTAPPLICATION{

class Serializer
{
	public:
		Serializer();
		virtual ~Serializer();
		virtual void WriteToFile(CollectionData)=0;
		virtual void PrintToConsole(CollectionData)=0;
};



}



#endif 
