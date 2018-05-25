#include"precompiled.h"
#include"FontResource.h"

FontResource::FontResource()
{

	fnt=NULL;
	 m_future=m_promise.get_future();
}
void FontResource::loadResource(string path)
{
	const char *fname=path.c_str(); 
	fnt=new hgeFont(fname); 
	m_future.share();
	incrementRefcount();
}
void FontResource::freeResource(string path)
{

}
bool FontResource::isResourceLoading()
{
	return m_future.valid();

}
void FontResource::incrementRefcount()
{
}

void FontResource::decrementRefcount()
{

}
hgeFont* FontResource::getFont()
{
	return fnt;
}

void FontResource::setPath(string path)
{
	m_path=path;
}

string FontResource::getPath()
{
	
	return m_path;
}