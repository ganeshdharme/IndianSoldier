#pragma once
#include"IObject.h"
#include"Player.h"
#include"Bullet.h"
#include"Rock.h"
#include"wall.h"
#include"GameBackground.h"
#include"StatechangeEvent.h"
#include"LevelManager.h"
#include"Bird.h"
#define WorldMnagaer_getinstance WorldManager::GetInstance()

class WorldManager
{
private:
	//vector<IObject*> m_activeObjlist;
	IObject *m_tempobj;
	vector<IResource*> m_receivedIResource;
	string m_resourcepath;
	KeyEvent* m_keyboardinstance;
	MouseEvent* m_mouseinstance;
	int m_objectid;
	Player *m_player;
	hgeFont *f;
	int i;
	bool flag;
	float bulletx,bullety;
	bool *xb,*yb;
	bool statusfetched;
	WorldManager();
	static WorldManager *m_wordinstance;
	
public:
	void init();
	void update();
	void render();
	void destroy();
	void addToActiveList(IObject*);
	void removeFromActiveList(IObject*);
	void handleInput(IEvent *eve);
	bool isAllObjectLoaded();
	void detectCollision();
	static WorldManager *GetInstance();
	vector<IObject*> m_activeObjlist;
	~WorldManager();
	int getObjectId();
};