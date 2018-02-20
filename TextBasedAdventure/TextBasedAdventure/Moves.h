#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
//#include "Character.h"
//#include "Player.h"
//#include "Enemy.h"

using namespace std;

class Moves
{
protected:
	string _name;
	int _cost;
	int _type;
	float _power;

public:

	Moves()
	{
		_name = "UNDEFINED (This is a bug, please report if you see this)";
		_cost = 0;
		_type = 0;
		_power = 1;
	}

	void set_name(string name)
	{
		_name = name;
	}

	string get_name()
	{
		return _name;
	}

	int get_cost()
	{
		return _cost;
	}

	int get_type()
	{
		return _type;
	}

	float get_power()
	{
		return _power;
	}

};

class Strike : public Moves
{
public:
	Strike()
	{
		Moves();
		_name = "Strike";
		_cost = 0;
		_type = 0;
		_power = 0.75;
	}
};

class Magic_Bolt : public Moves
{
public:
	Magic_Bolt()
	{
		Moves();
		_name = "Magic Bolt";
		_cost = 1;
		_type = 1;
		_power = 0.75;
	}
};