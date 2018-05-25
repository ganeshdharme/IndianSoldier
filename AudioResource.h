#pragma once
#include"IResource.h"
#include<string>
using namespace std;

class AudioResource:public IResource
{
public:
	void *audioresourceptr;
	void loadResource(string filename) override;
	void freeResource(string filename) override;
	bool isResourceLoading()override;
	void incrementRefcount()override;
	void decrementRefcount()override;
	void setPath(string)override;
	string getPath()override;
	AudioResource();
	
};