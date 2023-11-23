#pragma once
#include "stdafx.h"

#include <string>

#include "App/SimpleSprite.h"
#include "core.h"

class Entity
{
public:
	Entity() = default;
	virtual void init(const vec2& pos, const char* path);
	virtual void update(float delta);
	virtual void draw();

public:
	vec2 pos_;
	vec2 col_box_ = {32,32};

protected:
	vec2 velocity_;
	CSimpleSprite* sprite_;
	float speed_;
};
