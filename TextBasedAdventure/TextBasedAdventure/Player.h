#pragma once
#include <string>

using namespace std;

class Player
{
private:
	string _name;
	string _class;
	int _max_HP;
	int _current_HP;
	int _strength;
	int _defence;
	int _magic;
	int _magic_defence;
	int _mana;
	int _exp;

public:
	Player()
	{
		_max_HP = 100;
		_current_HP = _max_HP;
		_strength = 6;
		_defence = 6;
		_magic = 6;
		_magic_defence = 6;
		_mana = 5;
		_exp = 0;
	}
	int get_max_HP()
	{
		return _max_HP;
	}
	int get_HP()
	{
		return _current_HP;
	}
	int get_strength()
	{
		return _strength;
	}
	int get_defence()
	{
		return _defence;
	}
	int get_magic()
	{
		return _magic;
	}
	int get_magic_defence()
	{
		return _magic_defence;
	}
	int get_mana()
	{
		return _mana;
	}
	int get_exp()
	{
		return _exp;
	}
	void set_name(string name)
	{
		_name = name;
	}
	string get_name()
	{
		return _name;
	}
	string get_class()
	{
		return _class;
	}
	void set_class(string _class_)
	{
		_class = _class_;
	}
};