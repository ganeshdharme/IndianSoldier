#pragma once
#include"WorldManager.h"

class LevelManager
{
public:
	FILE *m_levelfile;
	vector<vector<int>> walls;
	int world[10][10];
	void loadFile();
	void setCharacter();

};