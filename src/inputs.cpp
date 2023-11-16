#include "stdafx.h"
#include "inputs.h"
#include "app/app.h"
#include "math.h"

Inputs::Inputs()
= default;

void Inputs::register_inputs()
{
	inputs_.x = App::GetController().GetLeftThumbStickX();
	inputs_.y = App::GetController().GetLeftThumbStickY();
}

vec2 Inputs::get_inputs()
{
	vec2 new_inputs = inputs_.normalized();
	new_inputs = new_inputs * ((abs(inputs_.x) + abs(inputs_.y)));
	new_inputs = new_inputs.normalized() * clamp01(new_inputs.magnitude());
	return new_inputs;
}
