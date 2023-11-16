#pragma once
#include "core.h"
#include "inputs.h"
#include "entity.h"

class Player : public Entity
{
public:
	Player() = default;
	Inputs inputs;

	void init(const vec2& pos) override;
	void update(float delta) override;
	void draw() override;
};