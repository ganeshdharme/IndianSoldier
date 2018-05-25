#pragma once


#include"IGameState.h"
#include"GameStateManager.h"
#include"IResource.h"
#include"ImageResource.h"
using namespace std;
class LoadingState:public IGameState
{
public:
	hgeFont *m_font;
		ImageResource* imager;
	std::future<IResource*> future;
	std::promise<IResource*> promise;
	IResource *ir;

	string  path;
void Update() override;
	void Render() override;
	void handleInput(IEvent*) override;
	LoadingState(string path);
	string getResourcevector()override;
	void loadResource()override;

};