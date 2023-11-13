#include "stdafx.h"
#include "Player.h"
#include "App/app.h"

Player::Player(float x, float y)
{
	posX = x;
	posY = y;
	sprite = nullptr;
}

void Player::Init()
{
	sprite = App::CreateSprite("..\\Sprites\Square.png", 4, 4);
	sprite->SetPosition(posX, posY);
	sprite->SetScale(1.0f);
}

void Player::Update(float delta)
{
	sprite->Update(delta);
}
