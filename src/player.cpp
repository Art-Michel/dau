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

	Colbox = { 28,32 };
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
	App::Print(Pos.x - 50, Pos.y + 50, mario.c_str());
}

void Player::check_collisions()
{
	std::vector<Entity*> e = EntitiesManager::GetInstance()->entities;

	//std::sort(e.begin(), e.end(), [&playerPos](const Entity* entity1, const Entity* entity2)
	//	{
	//		return (entity1->Pos - playerPos).abs() < (entity1->GetPos() - playerPos).abs();
	//	});

	//std::find_if(entities.begin(), entities.end(), [&entityName](const Entity* entity) {
	//	return entity.Name == entityName;
	//	});

	for (int i = 0; i < e.size(); i++)
	{
		if (e[i] == this)
			continue;
		if (collided_with(*e[i]))
		{
			this->velocity_ = { 0,0 };
			i--;
		}
	}
}

bool Player::collided_with(const Entity& entity)
{
	bool yesh =
		this->velocity_.x + this->Pos.x - this->Colbox.x < entity.Pos.x + entity.Colbox.x &&
		this->velocity_.x + this->Pos.x + this->Colbox.x > entity.Pos.x - entity.Colbox.x;
	bool yesv =
		this->velocity_.y + this->Pos.y - this->Colbox.y < entity.Pos.y + entity.Colbox.y &&
		this->velocity_.y + this->Pos.y + this->Colbox.y > entity.Pos.y - entity.Colbox.y;

	colliding = (yesh && yesv);
	return colliding;
}