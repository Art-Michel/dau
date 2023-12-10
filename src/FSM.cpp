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
	state(int name, Player* plpt)
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
	plst_grounded(int name, Player* plpt) : state::state(state_list::GROUNDED, plpt) {}

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
	plst_airborne(int name, Player* plpt) : state::state(state_list::AIRBORNE, plpt) {}

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
		plst_grounded* st1 = new plst_grounded(state_list::GROUNDED, playerpointer);
		add_state(player, st1);
	}

public:
	void add_state(Player* playerpointer, state* st)
	{

	}

	void change_state()
	{
		state next_state = states[state_list::NULLSTATE];
	}
};