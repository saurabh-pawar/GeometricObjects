#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

#include <stdio.h>
#include <iostream>

#include <types.h>

namespace TESTAPPLICATION{

class GeometricObject
{
	public:
		GeometricObject(const char* name,int x, int y);
		virtual ~GeometricObject();
		virtual void DrawThis()=0;
		virtual ObjectData getObjectData()=0;
		int X(){ return x; };
		int Y(){ return y; };
	protected:
		int x;
		int y;
		const char* mName;
		ObjectData mObjectData;
	private:
		void populateObjectData();

};
}
#endif
