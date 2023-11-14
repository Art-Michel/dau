#include "stdafx.h"
#include "entity.h"
#include "App/app.h"

Entity::Entity(float x, float y)
{
	pos_x_ = x;
	pos_y_ = y;
	sprite_ = nullptr;
}

void Entity::init()
{
	sprite_ = App::CreateSprite(".\\Sprites\\Square.png", 1, 1);
	sprite_->SetPosition(pos_x_, pos_y_);
	sprite_->SetScale(1.0f);
}

void Entity::update(const float delta)
{
	sprite_->Update(delta);
}

void Entity::draw()
{
	sprite_->Draw();
}
