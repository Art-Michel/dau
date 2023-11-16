#include "stdafx.h"
#include "player.h"

Player::Player() = default;

void Player::init(const vec2& pos)
{
	inputs = Inputs();
	Entity::init(pos);
}

void Player::update(float delta)
{
	inputs.register_inputs();
	velocity_ = inputs.get_inputs();
	Entity::update(delta);
}
