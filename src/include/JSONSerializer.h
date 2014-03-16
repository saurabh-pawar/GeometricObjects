#ifndef JSONSERILAIZER_H
#define JSONSERILAIZER_H

#include <Serializer.h>
#include <iostream>

namespace TESTAPPLICATION{

class JSONSerializer:public Serializer
{
	public:
		JSONSerializer();
		~JSONSerializer();
		void WriteToFile(CollectionData);
		void PrintToConsole(CollectionData);
};


}

#endif
