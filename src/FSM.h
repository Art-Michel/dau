#pragma once
#include "stdafx.h"
#include "state.h"
#include "player.h"

class FSM
{
private:
	std::map<int, state*> states;
	Player* player;

public:
	state Current_State;
	state Previous_State;

private:
	void init(Player* playerpointer);

public:
	void add_state(Player* playerpointer, state* st);

	void change_state();
};