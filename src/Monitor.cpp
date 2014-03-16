#include <Monitor.h>

namespace TESTAPPLICATION{

Monitor::Monitor()
{

}

Monitor::~Monitor()
{

}

void Monitor::Render(CollectionData data)
{
	printf("\n\nRendering on Monitor\n\n");
	int ObjectCount = 1;
	for(CollectionData::iterator cd=data.begin(); cd!=data.end(); cd++)
	{
		printf("Rendering Object%d on Monitor\n",ObjectCount++);
	}

}

}
