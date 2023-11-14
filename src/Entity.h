#pragma once
#include "App/SimpleSprite.h"

class entity
{
public:
	entity(float x, float y);

	void init();
	void update(float delta);
	void draw();

private:
	float pos_x_;
	float pos_y_;
	CSimpleSprite* sprite_;
};
