#pragma once
#include "stdafx.h"
#include "App/SimpleSprite.h"
#include "core.h"

class Entity
{
public:
	virtual ~Entity();
	Entity();
	virtual void init(const vec2& pos);
	virtual void update(float delta);
	virtual void draw();

protected:
	vec2 pos_;
	vec2 velocity_;
	CSimpleSprite* sprite_;
};
