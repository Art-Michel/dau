#include "stdafx.h"
#include "entity.h"
#include "App/app.h"

Entity::Entity() :
	pos_(),
	velocity_(),
	sprite_()
{
}

void Entity::init(const vec2& pos)
{
	pos_ = pos;
	sprite_ = App::CreateSprite(".\\Sprites\\char.png", 1, 1);
	sprite_->SetPosition(pos_.x, pos_.y);
	sprite_->SetScale(8.0f);
}

void Entity::update(const float delta)
{
	pos_ = pos_ + velocity_ * delta;
	sprite_->SetPosition(pos_.x, pos_.y);
	sprite_->Update(delta);
}

void Entity::draw()
{
	sprite_->Draw();
}
