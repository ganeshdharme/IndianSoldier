#include"precompiled.h"
#include"AudioResource.h"

void AudioResource::loadResource(string file)
{
	const char *fname=file.c_str(); 
	audioresourceptr=HGE_INSTANCE->Resource_Load(fname);
	incrementRefcount();
}
void AudioResource::freeResource(string file)
{
	
}
bool AudioResource::isResourceLoading()
{
	return m_future.valid();
}
AudioResource::AudioResource()
{
	 m_future=m_promise.get_future();
}
void AudioResource::incrementRefcount()
{
	++m_referencecount;
}

void AudioResource::decrementRefcount()
{
--m_referencecount;
	if(m_referencecount<0)
		freeResource(m_path);
}
void AudioResource::setPath(string path)
{
	m_path=path;
}

string AudioResource::getPath()
{
	
	return m_path;
}