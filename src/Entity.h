#pragma once
#include "stdafx.h"

#include <string>

#include "App/SimpleSprite.h"
#include "core.h"

class Entity
{
public:
	Entity() = default;
	virtual void init(const vec2& pos, const std::string& path);
	virtual void update(float delta);
	virtual void draw();

protected:
	vec2 pos_;
	vec2 velocity_;
	CSimpleSprite* sprite_;
	vec2 col_box_;
	vec2 col_box_offset;
	float speed_;
};
