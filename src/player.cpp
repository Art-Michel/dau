#include "stdafx.h"
#include <string>
#include "app\app.h"
#include "player.h"

#include <algorithm>

#include "EntitiesManager.h"


void Player::init(const vec2& pos, const char* path)
{
	inputs = Inputs();
	Entity::init(pos, path);
	speed_ = 0.3f;

	col_box_ = { 28,32 };
}

void Player::update(float delta)
{
	inputs.register_inputs();
	velocity_ = inputs.get_inputs();

	colliding = false;
	check_collisions();
	Entity::update(delta);
}

void Player::draw()
{
	App::Print(100, 100, ("Thumbstick X= " + std::to_string(velocity_.x)).c_str());
	App::Print(100, 80, ("Thumbstick Y= " + std::to_string(velocity_.y)).c_str());
	Entity::draw();

	std::string mario = "Colliding: ";
	mario += std::to_string(colliding);
	App::Print(pos_.x - 50, pos_.y + 50, mario.c_str());
}

void Player::check_collisions()
{
	std::vector<Entity*> e = EntitiesManager::GetInstance()->entities;

	for (int i = 0; i < e.size(); i++)
	{
		if (e[i] == this)
			continue;
		if (collided_with(*e[i]))
		{
			this->velocity_ = {0,0};
			i--;
		}
	}
}

bool Player::collided_with(const Entity& entity)
{
	bool yesh =
		this->velocity_.x + this->pos_.x - this->col_box_.x < entity.pos_.x + entity.col_box_.x &&
		this->velocity_.x + this->pos_.x + this->col_box_.x > entity.pos_.x - entity.col_box_.x;
	bool yesv =
		this->velocity_.y + this->pos_.y - this->col_box_.y < entity.pos_.y + entity.col_box_.y &&
		this->velocity_.y + this->pos_.y + this->col_box_.y > entity.pos_.y - entity.col_box_.y;

	colliding = (yesh && yesv);
	return colliding;
}