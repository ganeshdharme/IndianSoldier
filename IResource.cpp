#include"precompiled.h"
#include"IResource.h"
void IResource::loadResource(string filename)
{
	//m_future.share();
}

void IResource::freeResource(string filename)
{
}
bool IResource::isResourceLoading()
{
	return true;
}
void IResource::incrementRefcount()
{
	++m_referencecount;
}
void IResource::decrementRefcount()
{
	--m_referencecount;
	if(m_referencecount<0)
		freeResource(m_path);
}

void IResource::setPath(string path)
{
	m_path=path;
}

string IResource::getPath()
{
	
	return m_path;
}