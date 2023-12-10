#include "stdafx.h"
#include <map>
#include <string>
#include "player.h"

//--------------------------------------------------------------------------------------------
struct state_list
{
	static const int NULLSTATE = 0;
	static const int GROUNDED = 1;
	static const int AIRBORNE = 2;
};

//--------------------------------------------------------------------------------------------
class state
{
public:
	Player* player;
	int Name;

private:

public:
	state() = default;

	virtual void init(int name, Player* plpt)
	{
		Name = name;
		player = plpt;
	}
	virtual ~state() = default;

	virtual void Begin();
	virtual void Update();
	virtual void End();
};

//--------------------------------------------------------------------------------------------
class plst_grounded : state
{
public:
	void init(Player* plpt)
	{
		player = plpt;
		Name = state_list::GROUNDED;
	}

	void Begin()
	{

	}

	void Update()
	{

	}

	void End()
	{

	}
};

//--------------------------------------------------------------------------------------------
class plst_airborne : state
{
public:
	void init(Player* plpt)
	{
		player = plpt;
		Name = state_list::AIRBORNE;
	}

	void Begin() 
	{

	}

	void Update()
	{

	}

	void End()
	{

	}
};

//--------------------------------------------------------------------------------------------
class FSM
{
private:
	std::map<int, state*> states;
	Player* player;

public:
	state Current_State;
	state Previous_State;

private:
	void init(Player* playerpointer)
	{
		player = playerpointer;
		add_state(player, reinterpret_cast<state*>(new plst_grounded()));
	}

public:
	void add_state(Player* playerpointer, state* st)
	{

	}

	void change_state()
	{
		state* next_state = states[state_list::NULLSTATE];
	}
};