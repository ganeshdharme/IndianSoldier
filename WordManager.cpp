#include"precompiled.h"
#include"WorldManager.h"

WorldManager* WorldManager::m_wordinstance=NULL;
void WorldManager::init()
{

	
	m_tempobj=new BackgroundImage();
	m_tempobj->m_objectid=getObjectId();
	addToActiveList(m_tempobj);
	m_tempobj=new Player();
	m_tempobj->m_objectid=getObjectId();
	addToActiveList(m_tempobj);
	//m_tempobj=new Rock();
	//m_tempobj->m_objectid=getObjectId();
	//addToActiveList(m_tempobj);
	m_tempobj=new Bullet();
	m_tempobj->m_objectid=getObjectId();
	addToActiveList(m_tempobj);
	LevelManager *l=new LevelManager();
	l->loadFile();
	for(int i=0;i< m_activeObjlist.size();i++)
	{
		m_activeObjlist.at(i)->init();

	}
	f=new hgeFont("font1.fnt");
	 


}

WorldManager* WorldManager::GetInstance()
{
	if(m_wordinstance==NULL)
		m_wordinstance=new WorldManager();
	return m_wordinstance;
}
void WorldManager::render()
{
	if(isAllObjectLoaded()&&statusfetched)
	{
		for( i=0;i< m_activeObjlist.size();i++)
		{
			
			m_tempobj=m_activeObjlist.at(i);
				m_tempobj->loadResource();
		}
	
		flag=true;
	
	}
	else if(flag==false)
		{
			f->Render(100,200,HGETEXT_MIDDLE,"Loading");
			return;
		}
	else
	for(int i=0;i< m_activeObjlist.size();i++)
		{
			
			m_tempobj=m_activeObjlist.at(i);
 				m_tempobj->render();
				detectCollision();
			
		}
	
}

void WorldManager::addToActiveList(IObject *obj)
{
	m_activeObjlist.push_back(obj);
}
void WorldManager::handleInput(IEvent *event)
{
		if( dynamic_cast<KeyEvent*>(event))
	{
			 m_keyboardinstance=dynamic_cast<KeyEvent*>(event);
		 
			 if(m_keyboardinstance->isKeyPressed(BUTTON_RIGHT)||m_keyboardinstance->isKeyPressed(BUTTON_LEFT)||m_keyboardinstance->isKeyPressed(BUTTON_UP)||m_keyboardinstance->isKeyPressed(BUTTON_SPACE))
			 {
				 for(int i=0;i< m_activeObjlist.size();i++)
					{
						m_activeObjlist.at(i)->handleInput(event);

					}
			 }
		
			 if(m_keyboardinstance->isKeyPressed(BUTTON_ESCAPE))
			{
				StateChangeEvent eve;
				eve.mcurrentstate=eve.MENU;BROADCASTER->onEventHappen(&eve);}
			}
}
bool WorldManager::isAllObjectLoaded()
{
	bool flag=false;
	if(!statusfetched)
	{	
	for(int i=0;i<m_activeObjlist.size();i++)
	{
		if(m_activeObjlist.at(i)->isAllResourceLoaded()){
			flag= true;
		}
		else
		{	flag=false;
		break;
		}		
	}
	if(flag==true)
		statusfetched=true;
	}

	return flag;
}
void WorldManager::update()
{

	for(int i=0;i< m_activeObjlist.size();i++)
		{
			m_tempobj=m_activeObjlist.at(i);
			m_tempobj->update();
			
			
		}
}

void WorldManager::detectCollision()
{

Player *p;
		hgeRect *upplayerRect=new hgeRect[4];
		hgeRect *downplayerRect=new hgeRect[4];
		hgeRect *leftplayerRect=new hgeRect[4];
		hgeRect *rightplayerRect=new hgeRect[4];
	IObject *obj=WorldMnagaer_getinstance->m_activeObjlist.at(1);
	if(dynamic_cast<Player*>(obj))
			{
		p=dynamic_cast<Player*>(obj);
		upplayerRect=p->up;
		downplayerRect=p->down;
		leftplayerRect=p->left;
		rightplayerRect=p->right;
		}

	int flag=false;
		
	for(int i=0;i<WorldMnagaer_getinstance->m_activeObjlist.size();i++)
	{
		IObject *obj=WorldMnagaer_getinstance->m_activeObjlist.at(i);
		if(!(dynamic_cast<Player*>(obj))&&!(dynamic_cast<Bullet*>(obj)))
		if(obj->isSolid())
		{
			for(int j=0;j<4;j++)
			{
				hgeRect *temp;
				
				
					switch(j)
					{
					case 0:
						temp=upplayerRect;
						break;
					case 1:
					temp=downplayerRect;
						break;
					case 2:
						temp=leftplayerRect;
						break;
					case 3:
						temp=rightplayerRect;
						break;
		
					}

				if(temp->Intersect(obj->getObjectRect()))
				{
					flag=true;
					p->setCollision(true);
					switch(j)
					{
					case 0:
						f->Render(200,100,HGETEXT_MIDDLE,"up collision");
						break;
					case 1:
						f->Render(300,200,HGETEXT_MIDDLE,"down collision");
						break;
					case 2:
						f->Render(400,300,HGETEXT_MIDDLE,"left collision");
						break;
					case 3:
						f->Render(500,400,HGETEXT_MIDDLE,"right collision");
						break;
						
					}
				}
			}
		}
	}


	if(flag)
			{
		

			}
			else
			{
				f->Render(600,600,HGETEXT_MIDDLE,"not collision");
				
			}


}
void WorldManager::removeFromActiveList(IObject *obj)
{
	for(int i=0;i< m_activeObjlist.size();i++)
	{
		if((m_activeObjlist.at(i)->m_objectid) == (obj->m_objectid))
		{
			IObject *obj=m_activeObjlist.at(i);
			delete obj;
			m_activeObjlist.erase(m_activeObjlist.begin()+i);

		}
	}

}

int WorldManager::getObjectId()
{
	m_objectid++;
	return m_objectid;
}

void WorldManager::destroy()
{

}

WorldManager::WorldManager()
{
	m_objectid=0;
	flag=false;
	i=0;
	statusfetched=false;
}