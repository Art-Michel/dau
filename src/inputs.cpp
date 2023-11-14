#include "stdafx.h"
#include "inputs.h"
#include "app/app.h"

Inputs::Inputs()
= default;

void Inputs::register_inputs()
{
	inputs_.x = App::GetController().GetLeftThumbStickX();
	inputs_.y = App::GetController().GetLeftThumbStickY();
}

vec2 Inputs::get_inputs()
{
	return inputs_;
}
