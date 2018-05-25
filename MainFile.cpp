#include "precompiled.h"
#include "GameAppFramework.h"
#include <iostream>

using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	GameAppFramework::GetInstance()->init();
	return 0;   
}
