#include "stdafx.h"
#include <map>
#include <string>
#include "player.h"

class State
{
public:
	std::string Name;

public:
	void Begin();
	void Update();
	void End();
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
