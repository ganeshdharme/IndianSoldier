#include"precompiled.h"
#include"IObject.h"
void IObject::init()
{

}
void IObject::render()
{

}
void IObject::update()
{

}
void IObject::destroy()
{

}
void IObject::handleInput(IEvent *event)
{

}
bool IObject::isAllResourceLoaded()
{
	bool flag=false;
	for(int i=0;i<m_receivedresources.size();i++)
	{
		if(m_receivedresources.at(i)->isResourceLoading()){
			flag= false;
			break;
		}
		else
			flag=true;
	}
	return flag;
}
void IObject::loadResource()
{

}
hgeRect* IObject::getObjectRect()
{
	return m_objectrect;
}
bool IObject::isSolid()
{
	return solid;
}