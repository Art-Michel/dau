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

public:
	void init(const vec2& pos, const std::string& path) override;
	void update(float delta) override;
	void draw() override;

private:
	void check_collisions();
};