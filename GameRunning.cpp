#include "precompiled.h"
#include"GameRunning.h"
#include"StatechangeEvent.h"
#include"LoadResourceEvent.h"
GameRunning::GameRunning(void){
	m_font = new hgeFont("font1.fnt");
	//m_pathvector="background.png walk1.png walk2.png walk3.png walk4.png walk5.png walk6.png walk7.png walk8.png ";
	m_keyboardinstance=NULL;
	m_mouseinstance=NULL;
	m_backgroundImg = NULL;
	
	/*m_receivedresources=Resourcetracker_INSTANCE->requestResource(m_pathvector,0);
	m_receivedir=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
	string removefilename="walk8.png";*/
	//Resourcetracker_INSTANCE->requestResource(removefilename,1);
	loadResource();
}
void GameRunning::loadResource()
{/*
	if(m_backgroundImg==NULL)
	{ 
		
		
		m_backgroundImg=new BackgroundImage(m_pathvector);
		m_playerInstance=new Player();
	}*/

	WorldMnagaer_getinstance->init();
}
void GameRunning::Update(){

	WorldMnagaer_getinstance->update();	
	/*if(!m_receivedir->isResourceLoading())
	{
		if(m_backgroundImg==NULL)
			loadResource();
	}*/
}

string GameRunning::getResourcevector()
{
	return m_pathvector;
}

void GameRunning::Render()
{
	WorldMnagaer_getinstance->render();

	
}

void GameRunning::handleInput(IEvent *event)
{
	WorldMnagaer_getinstance->handleInput(event);
}
GameRunning::~GameRunning(void)
{
	Resourcetracker_INSTANCE->requestResource(m_pathvector,1);
}

