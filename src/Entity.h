#pragma once
#include "App/SimpleSprite.h"

class Entity
{
public:
	Entity(float x, float y);

	void Init();
	void Update(const float delta);
	void Draw();

private:
	float _posX;
	float _posY;
	CSimpleSprite* _sprite;
};
