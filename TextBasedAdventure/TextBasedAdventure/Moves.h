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

public:

	Moves()
	{
		_name = "UNDEFINED (This is a bug, please report if you see this)";
		_cost = 0;
		_type = 0;
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
	}
};