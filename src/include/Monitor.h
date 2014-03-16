#ifndef MONITOR_H
#define MONITOR_H

#include<Device.h>

namespace TESTAPPLICATION{

class Monitor : public Device
{
	public:
		Monitor();
		~Monitor();
		void Render(CollectionData);
};


}

#endif
