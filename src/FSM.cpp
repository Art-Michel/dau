#include "stdafx.h"
#include <map>
#include <string>
#include "player.h"
#include "FSM.h"
#include "playerstates.h"

void FSM::init(Player* playerpointer)
{
	player = playerpointer;
	add_state(player, reinterpret_cast<state*>(new plst_grounded()));
	add_state(player, reinterpret_cast<state*>(new plst_airborne()));
}

void FSM::add_state(Player* playerpointer, state* st)
{

}

void FSM::change_state()
{
	state* next_state = nullptr;
}
