#ifndef APPLICATION_H
#define APPLICATION_H

#include<status.h>
#include<objects.h>
#include<Collection.h>
#include<stdio.h>
#include<Serializer.h>
#include<Device.h>
#include<JSONSerializer.h>
#include<map>

namespace TESTAPPLICATION{

class Application
{
	public:
		Application();
		~Application();
		StatusCodeType Status();
		void Status(StatusCodeType);
		void Run();
		void RegisterSerializer(const char*,Serializer*);
		void UnRegisterSerializer(const char*);
		void AddOutputDevice(const char*, Device*);
		void RemoveOutputDevice(const char*);
		void Render(CollectionData,const char*);
	private :
		StatusCodeType mStatus;
		void Init();
		void CleanUp();
		Collection<GeometricObject>* mCollection;
		std::map<const char*, Serializer*> serializerMap;
		std::map<const char*, Device*> deviceMap;
};

}
#endif
