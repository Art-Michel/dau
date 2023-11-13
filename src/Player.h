#pragma once
#include "App/SimpleSprite.h"

class Player
{
public:
	Player(float x, float y);

	void Init();
	void Update(float delta);

private:
	float posX;
	float posY;
	CSimpleSprite *sprite;
};
