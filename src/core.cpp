#include "stdafx.h"
#include "core.h"

float dot(vec2 a, vec2 b)
{
	return 1;
}

float clamp(float min, float max, float i)
{
	if (i > max)
		return max;
	else if (i < min)
		return min;
	else
		return i;
}

float clamp01(float i)
{
	return clamp(0, 1, i);
}
