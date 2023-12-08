#include "stdafx.h"
#include <map>
#include <string>
#include "player.h"

class State
{
public:
	Player player;
	std::string Name;

private:

public:
	State(std::string name)
	{
		this->Name = name;
	}
	virtual void Begin();
	virtual void Update();
	virtual void End();
};

class FSM
{
private:
	std::map<std::string, State> states;
	Player player;

public:
	State Current_State;
	State Previous_State;
};

class plst_grounded : State
{
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

class plst_airborne : State
{
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