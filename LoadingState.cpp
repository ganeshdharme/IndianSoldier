#include"precompiled.h"
#include"LoadingState.h"
#include"LoadResourceEvent.h"
void LoadingState::Update()
{
	if(!future.valid()){
	//	Resourcetracker_INSTANCE->
	}
}

void LoadingState::Render()
{
	if(future.valid()){
		m_font->printf(400, 100, HGETEXT_MIDDLE, "Loading");
	}
	else
	{
		 LoadResourceEvent eve;
	BROADCASTER->onEventHappen(&eve);
	}
}

void LoadingState::handleInput(IEvent *event)
{
}

LoadingState::LoadingState(string path)
{
	 m_font = new hgeFont("font1.fnt");
	 future=promise.get_future();
//	 Resourcetracker_INSTANCE->loadResource(string(path),&promise,&future);
	future.get();

}
string LoadingState::getResourcevector()
{
	return path;
}

void LoadingState::loadResource()
{

}