#include <JSONSerializer.h>

namespace TESTAPPLICATION{


JSONSerializer::JSONSerializer()
{
	printf("\n\nJSON Serializer Created\n\n");
}

JSONSerializer::~JSONSerializer()
{
	printf("\n\nJSON Serializer Destroyed\n\n");
}

void JSONSerializer::PrintToConsole(CollectionData data)
{	
	int ObjectCount = 1;
	std::cout << "{" << std::endl;
	for(CollectionData::iterator cd=data.begin(); cd!=data.end(); cd++)
	{
		std::cout << "\tObject"<<ObjectCount<<" : {" << std::endl;
		for(ObjectData::iterator od=cd->begin(); od!=cd->end(); od++)
		{
			
			std::cout << "\t\t\t" << od->key << " : " << od->value << "," << std::endl;
		}
		std::cout << "\t}," << std::endl;
		ObjectCount++;		
	}
	std::cout << "}" << std::endl;
}

void JSONSerializer::WriteToFile(CollectionData data)
{

}










}
