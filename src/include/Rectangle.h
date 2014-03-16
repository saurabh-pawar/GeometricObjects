#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <GeometricObject.h>

namespace TESTAPPLICATION{

class Rectangle : public GeometricObject
{
	public:
		Rectangle(const char*,int,int,int,int);
		~Rectangle();
		void DrawThis();
		ObjectData getObjectData();
		int W(){ return mWidth; };
		int H(){ return mHeight; };

	private:
		int mWidth;
		int mHeight;
};
}
#endif
