#include "stdafx.h"
#include "entity.h"

#include "App/app.h"

//Entity::Entity() :
//	sprite_()
//{
//}

void Entity::init(const vec2& pos, const std::string& path)
{
	pos_ = pos;
	sprite_ = App::CreateSprite(path.c_str(), 1, 1);
	sprite_->SetPosition(pos_.x, pos_.y);
	sprite_->SetScale(8.0f);
	speed_ = 0;
}

void Entity::update(const float delta)
{
	pos_ = pos_ + velocity_ * delta * speed_;
	sprite_->SetPosition(pos_.x, pos_.y);
	sprite_->Update(delta);
}

void Entity::draw()
{
	sprite_->Draw();
}
