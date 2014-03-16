#include <iostream>
#include <stdlib.h>

#include <Application.h>
#include <JSONSerializer.h>
#include <Monitor.h>

using namespace std;

int main(int argc, char *argv[])
{
	StatusCodeType status = STATUS_OK;

	TESTAPPLICATION::Application* gApplication = new TESTAPPLICATION::Application();
	TESTAPPLICATION::Serializer* jsonSerializer = new TESTAPPLICATION::JSONSerializer();	
	TESTAPPLICATION::Device* monitor = new TESTAPPLICATION::Monitor();
	if(!gApplication)
	{
		cout << "Error : File : "<<__FILE__<<"	Line : " << __LINE__ << "	 Unable create  gApplication object\n";
		status = STATUS_ERROR;
		goto done;
	}

	if ( gApplication->Status() != STATUS_OK )
	{
		status = STATUS_ERROR;
		goto done;
	}
	
	if(!jsonSerializer)
	{
		cout << "Error : File : "<<__FILE__<<"	Line : " << __LINE__ << "	 Unable create  Serializer object\n";
		status = STATUS_ERROR;
		goto done;
	}

	gApplication->RegisterSerializer("JSON",jsonSerializer);

	gApplication->AddOutputDevice("Monitor",monitor);
	
	gApplication->Run();


done:

	if(gApplication)
	{
 		delete gApplication;
		gApplication = NULL;
 	}

	cout << "\n\nFile : "<< __FILE__ <<"	Line : "<< __LINE__ <<"       Exit Application\n\n";

	return(status); 
}

