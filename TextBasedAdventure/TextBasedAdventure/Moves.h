#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Moves
{
protected:
	string _name;
	int _cost;
	int _type;
	float _power;
	int _crit;

public:

	Moves()
	{
		_name = "UNDEFINED (This is a bug, please report if you see this)";
		_cost = 0;
		_type = 0;
		_power = 1;
		_crit = 1;
	}

	int get_crit()
	{
		return _crit;
	}

	void set_name(string name)
	{
		_name = name;
	}

	bool is_crit()
	{
		return (rand() % 100) < _crit;
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
		_crit = 10;
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
		_crit = 10;
	}
};

class Heal : public Moves
{
public:
	Heal()
	{
		Moves();
		_name = "Heal";
		_cost = 2;
		_type = 1;
		_power = 2;
		_crit = 0;
	}
};

class Mini_Heal : public Moves
{
public:
	Mini_Heal()
	{
		Moves();
		_name = "Mini Heal";
		_cost = 2;
		_type = 1;
		_power = 1.5;
		_crit = 0;
	}
};

class Restore : public Moves
{
public:
	Restore()
	{
		Moves();
		_name = "Restore Mana";
		_cost = 0;
		_type = 1;
		_power = 1;
		_crit = 0;
	}
};