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
	Entity::draw();
	App::Print(100, 100, ("Thumbstick X= " + std::to_string(velocity_.x)).c_str());
	App::Print(100, 80, ("Thumbstick Y= " + std::to_string(velocity_.y)).c_str());

	std::string mario = "Colliding: ";
	mario += std::to_string(colliding);
	App::Print(Pos.x - 50, Pos.y + 50, mario.c_str());
	App::Print(Pos.x - 50, Pos.y + 100, (std::to_string((int)Pos.x) + " " + std::to_string((int)Pos.y)).c_str());

	//debug
	std::vector<Entity*> e = EntitiesManager::GetInstance()->entities;

	App::Print(10, 300, (std::to_string((int)e[0]->Pos.x) + " | " + std::to_string((int)e[1]->Pos.x) + " | " + std::to_string((int)e[2]->Pos.x) + " | " + std::to_string((int)e[3]->Pos.x)).c_str());

	std::sort(e.begin(), e.end(), [this](const Entity* a, const Entity* b)
		{
			return a->Dist_to_player() > b->Dist_to_player();
		});

	App::Print(30, 400, (std::to_string((int)e[0]->Pos.x) + " | " + std::to_string((int)e[1]->Pos.x) + " | " + std::to_string((int)e[2]->Pos.x) + " | " + std::to_string((int)e[3]->Pos.x)).c_str());
}

void Player::check_collisions()
{
	std::vector<Entity*> e = EntitiesManager::GetInstance()->entities;

	std::sort(e.begin(), e.end(), [this](const Entity* a, const Entity* b)
		{
			return a->Dist_to_player() > b->Dist_to_player();
		});

	for (int i = 0; i < e.size(); i++)
	{
		if (e[i] == this)
			continue;
		if (collided_with(*e[i]))
		{
			resolve_collision(*e[i]);
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

void Player::resolve_collision(const Entity& entity)
{
	vec2 diff = (this->Pos - entity.Pos);
	vec2 dir = diff.normalized();
	vec2 dir2;
	if (abs(dir.x) > abs(dir.y))
	{
		dir2 = { dir.x, 0 };
		this->velocity_ = this->velocity_ + dir2.normalized() * this->velocity_.magnitude();
	}
	else
	{
		dir2 = { 0, dir.y };
		this->velocity_ = this->velocity_ + dir2.normalized() * this->velocity_.magnitude();
	}
}