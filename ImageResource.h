#pragma once
#include<future>
#include<string>
using namespace std;
#include"IResource.h"

class ImageResource:public IResource
{
private:
	
	//string m_path;
public:
	HTEXTURE *m_bgtexture;
	void loadResource(string filename)override;
	void freeResource(string filename)override;
	void incrementRefcount()override;
	void decrementRefcount()override;
	HTEXTURE* getTexture();
	ImageResource();
	void setPath(string)override;
	string getPath()override;
	bool isResourceLoading()override;
	
};