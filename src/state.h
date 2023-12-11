#pragma once
#include "stdafx.h"
#include "player.h"

struct state_list
{
	static const int GROUNDED = 0;
	static const int AIRBORNE = 1;
};

class state
{
	public:
		Player* player;
		int Name;

	private:

	public:
		state() = default;

		virtual void init(int name, Player* plpt);
		virtual ~state() = default;

		virtual void Begin(){}
		virtual void Update(){}
		virtual void End(){}
};

