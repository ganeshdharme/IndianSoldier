#include"precompiled.h"
#include"CollisionDetector.h"
bool CollisionDetector::checkCollision()
{
			Player *p;
			hgeRect *playerRect;
	for(int i=0;i<WorldMnagaer_getinstance->m_activeObjlist.size();i++)
	{
		IObject *obj=WorldMnagaer_getinstance->m_activeObjlist.at(i);
		if(dynamic_cast<Player*>(obj))
			{
		p=dynamic_cast<Player*>(obj);
		playerRect=p->getObjectRect();
		
		continue;
		}
		if(obj->isSolid())
		{
			for(int j=0;j<4;j++)
			{
				if(playerRect[i].Intersect(obj->getObjectRect()))
					return true;
			}
		}
	}
}