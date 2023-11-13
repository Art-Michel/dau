#include "stdafx.h"
#include "Entity.h"
#include "App/app.h"

Entity::Entity(float x, float y)
{
	_posX = x;
	_posY = y;
	_sprite = nullptr;
}

void Entity::Init()
{
	_sprite = App::CreateSprite(".\\Sprites\\Square.png", 1, 1);
	_sprite->SetPosition(_posX, _posY);
	_sprite->SetScale(1.0f);
}

void Entity::Update(float delta)
{
	_sprite->Update(delta);
}

void Entity::Draw()
{
	_sprite->Draw();
}
