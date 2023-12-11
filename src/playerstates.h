#pragma once
#include "stdafx.h"
#include "state.h"

class plst_grounded : state
{
public:
	void Begin();
	void Update();
	void End();
};

class plst_airborne : state
{
public:
	void Begin();
	void Update();
	void End();
};