#ifndef DEVICE_H
#define DEVICE_H

#include <types.h>


namespace TESTAPPLICATION{


class Device
{
	public:
		Device();
		virtual ~Device();
		virtual void Render(CollectionData)=0;
};

}

#endif
