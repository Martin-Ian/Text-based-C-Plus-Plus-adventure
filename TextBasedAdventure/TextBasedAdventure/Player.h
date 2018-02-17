#pragma once
#include <string>
#include <vector>

using namespace std;

class Player
{
private:
	string _name;
	string _class;
	float _max_HP;
	float _current_HP;
	int _strength;
	int _defence;
	int _magic;
	int _magic_defence;
	int _mana;
	int _exp;
	float _speed;
	vector<string> possible_classes = {"KNIGHT", "RANGER", "MAGE"};

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
	void set_speed(float value)
	{
		_speed = value;
	}
	float get_speed()
	{
		return _speed;
	}
	string get_class()
	{
		return _class;
	}
	void set_class(string _class_)
	{
		_class = _class_;

		if (_class == "KNIGHT")
		{
			set_HP(120);
			set_strength(7);
			set_defence(7);
			set_magic(1);
			set_magic_defence(6);
			set_mana(1);
			set_speed(4);
		}
		else if (_class == "RANGER")
		{
			set_HP(100);
			set_strength(5);
			set_defence(5);
			set_magic(4);
			set_magic_defence(5);
			set_mana(4);
			set_speed(7);
		}
		else if (_class == "MAGE")
		{
			set_HP(70);
			set_strength(3);
			set_defence(4);
			set_magic(8);
			set_magic_defence(7);
			set_mana(10);
			set_speed(4);
		}
	}
	void show_stats()
	{
		cout << "Health: " << _current_HP << " / " << _max_HP << endl;
		cout << "Strength: " << _strength << endl;
		cout << "Defence: " << _defence << endl;
		cout << "Magic: " << _magic << endl;
		cout << "Magic Defence: " << _magic_defence << endl;
		cout << "Mana: " << _mana << endl;
		cout << "Speed: " << _speed << endl;
	}
	vector<string> get_possible_classes()
	{
		return possible_classes;
	}
};