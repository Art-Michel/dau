#include "stdafx.h"
#include "player.h"
#include <string>

#include "app\app.h"


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

void Player::draw()
{
	App::Print(100, 100, (std::to_string( (vec2{-1, 0} * 1).x) ).c_str());
	//App::Print(100, 80, ("Thumbstick X= " + std::to_string(velocity_.x)).c_str());
	//App::Print(100, 80, ("Thumbstick Y= " + std::to_string(velocity_.y)).c_str());
	Entity::draw();
}

