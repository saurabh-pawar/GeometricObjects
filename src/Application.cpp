#include <Application.h>

namespace TESTAPPLICATION{

Application::Application()
{
	Init();
}

Application::~Application()
{
	CleanUp();
}

void Application::Init()
{
	if(!mCollection)
	{
		mCollection = new Collection<GeometricObject>;
		if(!mCollection)
		{
			printf("File : %s	Line : %d      Couldn't create a Collection",__FILE__,__LINE__);
			Status(STATUS_ERROR);
		}
	}
}

void Application::CleanUp()
{
	delete mCollection;
	mCollection = NULL;

	for(std::map<const char*, Serializer*>::iterator it=serializerMap.begin(); it!=serializerMap.end(); it++)
	{
		delete  it->second;
		it->second = NULL;
	}

	for(std::map<const char*, Device*>::iterator it=deviceMap.begin(); it!=deviceMap.end(); it++)
	{
		delete  it->second;
		it->second = NULL;
	}
}

StatusCodeType Application::Status()
{
	return mStatus;
}

void Application::Status(StatusCodeType status)
{
	mStatus = status;
}

void Application::RegisterSerializer(const char* name,Serializer* serializer)
{
	serializerMap.insert(std::pair<const char*,Serializer*>(name,serializer));
}

void Application::UnRegisterSerializer(const char* name)
{
	serializerMap.erase(name);
}

void Application::AddOutputDevice(const char* name, Device* device)
{
	deviceMap.insert(std::pair<const char*,Device*>(name,device));
}

void Application::RemoveOutputDevice(const char* name)
{
	deviceMap.erase(name);
}

void Application::Render(CollectionData data, const char* name)
{
	Device* device = deviceMap.at(name);
	device->Render(data);
}


void Application::Run()
{
	printf("\n\nApplication Running\n\n");
		
	Rectangle* rect = NULL;

	rect = new Rectangle("Rectangle1",0,0,100,20);
	mCollection->Push(rect);

	rect = new Rectangle("Rectangle2",10,10,200,50);
	mCollection->Push(rect);

	rect = new Rectangle("Rectangle3",100,100,300,55);
	mCollection->Push(rect);

	rect = NULL;

	mCollection->SetSerializer(serializerMap.at("JSON"));	
	mCollection->Serialize();

	
	Render(mCollection->SerializableData(),"Monitor");

	
}


}



