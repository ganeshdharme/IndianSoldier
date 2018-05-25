#include"precompiled.h"
#include"LevelManager.h"
#include<Windows.h>
void LevelManager::loadFile()
{
	setCharacter();
	int count=0;
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
		{
			if(world[i][j]==1)
			{
				count=count+150;
				IObject *m_tempobj=new Wall(count,550);
				m_tempobj->m_objectid=WorldMnagaer_getinstance->getObjectId();
				WorldMnagaer_getinstance->addToActiveList(m_tempobj);
				count++;
			}
		}

		count =100;
		for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			int temp=rand()*GetProcessId(this)%25;
			if(j%3==0)
			{
				count=count+150;
				IObject *m_tempobj=new Wall(count,350);
				m_tempobj->m_objectid=WorldMnagaer_getinstance->getObjectId();
				WorldMnagaer_getinstance->addToActiveList(m_tempobj);
				
			}
			count++;
		}


}

void LevelManager::setCharacter()
{
	int temp=0;
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
		{
			//temp=rand()*GetProcessId(this)%5;			
			world[i][j]=1;
			//world[i][temp]=0;
		}
}
