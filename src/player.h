#pragma once
#include "core.h";
#include "inputs.h"
#include "entity.h"

class Player : public Entity
{
public:
	Player();
	Inputs inputs;

	void init(const vec2& pos);
	void update(float delta);
};