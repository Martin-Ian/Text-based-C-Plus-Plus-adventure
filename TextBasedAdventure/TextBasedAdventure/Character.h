#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Moves.h"

using namespace std;

class Character
{
private:
	string _name;
	float _max_HP;
	float _current_HP;
	int _strength;
	int _defence;
	int _magic;
	int _magic_defence;
	int _mana;
	float _speed;
	float _counter;
	vector<string> status;
	vector<Moves> _moves = { Strike(), Magic_Bolt() };

public:
	Character()
	{
		_max_HP = 100;
		_current_HP = _max_HP;
		_strength = 1;
		_defence = 1;
		_magic = 1;
		_magic_defence = 1;
		_mana = 1;
		_name = "Unknown";
		_speed = 1;
		_counter = 0;
	}

	void set_name(string name)
	{
		_name = name;
	}

	string get_name()
	{
		return _name;
	}

	float get_max_HP()
	{
		return _max_HP;
	}

	void set_HP(float value)
	{
		_max_HP = value;
		_current_HP = value;
	}

	float get_HP()
	{
		return _current_HP;
	}

	int get_strength()
	{
		return _strength;
	}

	void set_strength(int value)
	{
		_strength = value;
	}

	int get_defence()
	{
		return _defence;
	}

	void set_defence(int value)
	{
		_defence = value;
	}

	int get_magic()
	{
		return _magic;
	}

	void set_magic(int value)
	{
		_magic = value;
	}

	int get_magic_defence()
	{
		return _magic_defence;
	}

	void set_magic_defence(int value)
	{
		_magic_defence = value;
	}

	int get_mana()
	{
		return _mana;
	}

	void set_mana(int value)
	{
		_mana = value;
	}

	void use_mana(int amount)
	{
		_mana = _mana - amount;
	}

	void set_speed(float value)
	{
		_speed = value;
	}

	float get_speed()
	{
		return _speed;
	}

	void add_speed()
	{
		_counter += _speed;
	}

	float get_counter()
	{
		return _counter;
	}

	void reset_counter()
	{
		_counter = 0;
	}

	void take_damage(int value)
	{
		_current_HP -= value;
	}

	vector<Moves> get_moves()
	{
		return _moves;
	}

};