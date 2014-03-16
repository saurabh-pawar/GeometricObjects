#include <Rectangle.h>

namespace TESTAPPLICATION{

Rectangle::Rectangle(const char* name,int x, int y, int width, int height):GeometricObject(name,x,y)
{
	mWidth = width;
	mHeight = height; 
	printf("%s Created \n",mName);
}

Rectangle::~Rectangle()
{
	printf("%s Destroyed\n",mName);
}

void Rectangle::DrawThis()
{
	printf("Drawing Rectangle %s at %d,%d of width-%d and height%d\n",mName,X(),Y(),mWidth,mHeight);
}

ObjectData Rectangle::getObjectData()
{
	ObjectProperty property;

	property.key = "Width";
	property.value = std::to_string(mWidth);
	mObjectData.push_back(property);

	property.key = "Height";
	property.value = std::to_string(mHeight);
	mObjectData.push_back(property);

	/*printf("\n\n%s Data - \n",mName);
	for(ObjectData::iterator it=mObjectData.begin(); it!=mObjectData.end();it++)
	{
		std::cout << "key-" << it->key << "  " << "value-" << it->value << std::endl;
	}
	*/

	return mObjectData;
}

}
