#pragma once
#include <corecrt_math.h>
#include "Entity.h"

struct vec2
{
	float x;
	float y;

	vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float magnitude() const
	{
		return sqrtf((x * x) + (y * y));
	}

	vec2 normalized() const
	{
		float mag = magnitude();
		return {x/mag,y/mag};
	}

	vec2 operator *(const float& f) const
	{
		return multiply(f, *this);
	}

	vec2 multiply(const float& f, const vec2& v) const
	{
		return { v.x * f, v.y * f };
	}
};

float dot(const vec2& a, const vec2& b);

float clamp(float min, float max, float i);
float clamp01(float i);