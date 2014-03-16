#include <GeometricObject.h>

namespace TESTAPPLICATION{

GeometricObject::GeometricObject(const char* name,int co_ord1, int co_ord2)
{
	mName = name;
	x = co_ord1;
	y = co_ord2;
	populateObjectData();
	//printf("Geometric Object Created\n");
}

GeometricObject::~GeometricObject()
{
	//printf("Geometric Object Destroyed\n");
}

void GeometricObject::populateObjectData()
{
	ObjectProperty property;
	property.key = "Name";
	property.value = mName;
	mObjectData.push_back(property);

	property.key = "X";
	property.value = std::to_string(x);
	mObjectData.push_back(property);

	property.key = "Y";
	property.value = std::to_string(y);
	mObjectData.push_back(property);
}
}
