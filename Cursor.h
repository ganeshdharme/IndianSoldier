#pragma once
#include "Input.h"
#include "Entity.h"

class Cursor : public Entity
{
private:
	Input* m_input;

public:
	Cursor(double, double, Input*);
	void update(HGE*);
	void render(HGE*);

	~Cursor(void);
};

