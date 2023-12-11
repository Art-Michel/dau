#pragma once
#include "stdafx.h"
#include "state.h"

class plst_grounded : public state
{
public:
	void Begin();
	void Update();
	void End();
};

class plst_airborne : public state
{
public:
	void Begin();
	void Update();
	void End();
};