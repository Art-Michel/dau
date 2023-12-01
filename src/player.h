#pragma once
#include "stdafx.h"
#include "core.h"
#include "inputs.h"
#include "entity.h"

class Player : public Entity
{
public:
	Player() = default;

private:
	Inputs inputs;
	bool colliding;

public:
	void init(const vec2& pos, const char* path) override;
	void update(float delta) override;
	void draw() override;


private:
	void check_collisions();
	bool collided_with(const Entity& entity);
	void resolve_collision(const Entity& entity);
};