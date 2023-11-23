#include "stdafx.h"
#include <string>
#include "app\app.h"
#include "player.h"
#include "EntitiesManager.h"


void Player::init(const vec2& pos, const std::string& path)
{
	inputs = Inputs();
	Entity::init(pos, path);
	speed_ = 0.3f;
}

void Player::update(float delta)
{
	inputs.register_inputs();
	velocity_ = inputs.get_inputs();

	check_collisions();
	Entity::update(delta);
}

void Player::draw()
{
	App::Print(100, 100, ("Thumbstick X= " + std::to_string(velocity_.x)).c_str());
	App::Print(100, 80, ("Thumbstick Y= " + std::to_string(velocity_.y)).c_str());
	Entity::draw();
	App::Print(pos_.x - 50, pos_.y + 50, "Colliding: ");
}

void Player::check_collisions()
{
	for (int i = 0; i < EntitiesManager::GetInstance()->entities.size(); i++)
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
}
