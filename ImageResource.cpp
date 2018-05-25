#include"precompiled.h"
#include"ImageResource.h"
#include"IObject.h"
void ImageResource::loadResource(string filename)
{
	const char *fname=filename.c_str(); 
	m_bgtexture=new HTEXTURE(); 
	*m_bgtexture=HGE_INSTANCE->Texture_Load(fname);
	m_future.share();
	incrementRefcount();
}
void ImageResource::freeResource(string filename)
{

}

HTEXTURE * ImageResource::getTexture()
{
	return m_bgtexture;
}
ImageResource::ImageResource()
{
	m_bgtexture=NULL;
	 m_future=m_promise.get_future();
}
void ImageResource::setPath(string path)
{
	m_path=path;
}

void ImageResource::incrementRefcount()
{
	++m_referencecount;
}
void ImageResource::decrementRefcount()
{
--m_referencecount;
	if(m_referencecount<0)
		freeResource(m_path);
}
string ImageResource::getPath()
{
	
	return m_path;
}

bool ImageResource::isResourceLoading()
{
	return m_future.valid();
}
