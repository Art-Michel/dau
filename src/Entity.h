#pragma once
#include "App/SimpleSprite.h"

class Entity
{
public:
	Entity(float x, float y);

	void init();
	void update(float delta);
	void draw();

private:
	float pos_x_;
	float pos_y_;
	CSimpleSprite* sprite_;
};
