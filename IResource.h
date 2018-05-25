#pragma once
#include<future>
#include"GameAppFramework.h"
class IResource
{
public:
	int m_referencecount;
	string m_path;
	future<bool> m_future;
	promise<bool> m_promise;
	virtual void loadResource(string filename);
	virtual void freeResource(string filename);
	virtual bool isResourceLoading();
	virtual void incrementRefcount();
	virtual void decrementRefcount();
	virtual void setPath(string);
	virtual string getPath();
	//virtual ~IResource();
};