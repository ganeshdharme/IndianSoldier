#include "precompiled.h"
#include"GameAppFramework.h"
GameAppFramework* GameAppFramework::m_instance = 0;

GameAppFramework::GameAppFramework(void){

}


void GameAppFramework::init(){
	 m_hge = hgeCreate(HGE_VERSION);

	 m_hge->System_SetState(HGE_FRAMEFUNC, HGEUpdateCallback);
	 m_hge->System_SetState(HGE_RENDERFUNC, HGERenderCallback);
	 m_hge->System_SetState(HGE_FPS, 100);

	 m_hge->System_SetState(HGE_WINDOWED, true);
	 m_hge->System_SetState(HGE_TITLE, "Indian Army");

	 m_hge->System_SetState(HGE_SCREENWIDTH, 1280);
	 m_hge->System_SetState(HGE_SCREENHEIGHT, 720);
	m_hge->System_SetState(HGE_SCREENBPP, 32);
	m_hge->System_SetState(HGE_LOGFILE,"Gamelog.txt");

	if(m_hge->System_Initiate()){
		Resourcetracker_INSTANCE->StartThread();
		//Sleep(100);
		m_hge->System_Start();
		m_hge->System_Log("Resource Thread Started...");
	}
	else{	
		MessageBox(NULL, "train", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}
}

bool GameAppFramework::Update()
{

	INPUT_INSTANCE->Update();
	GameStateManager::GetInstance()->Update();
	char *s=m_hge-> System_GetErrorMessage();
	m_hge->System_Log(s);
	return true;
}

bool GameAppFramework::Render(){
	m_hge->Gfx_BeginScene();
	m_hge->Gfx_Clear(0);
	GameStateManager::GetInstance()->Render();
	m_hge->Gfx_EndScene();
	return false;
}

bool GameAppFramework::HGEUpdateCallback(){
	//If true : HGE exits the game loop
	return !GameAppFramework::GetInstance()->Update();
}

bool GameAppFramework::HGERenderCallback(){
	return GameAppFramework::GetInstance()->Render();
}

HGE* GameAppFramework::getHGE(){ return m_hge; }

GameAppFramework* GameAppFramework::GetInstance(){
	if(m_instance == NULL) 
		m_instance = new GameAppFramework();
	return m_instance;
}

GameAppFramework::~GameAppFramework(void){
}
