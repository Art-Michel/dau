#include "stdafx.h"
#include "entity.h"
#include "App/app.h"

entity::entity(float x, float y)
{
	pos_x_ = x;
	pos_y_ = y;
	sprite_ = nullptr;
}

void entity::init()
{
	sprite_ = App::CreateSprite(".\\Sprites\\Square.png", 1, 1);
	sprite_->SetPosition(pos_x_, pos_y_);
	sprite_->SetScale(1.0f);
}

void entity::update(const float delta)
{
	sprite_->Update(delta);
}

void entity::draw()
{
	sprite_->Draw();
}
