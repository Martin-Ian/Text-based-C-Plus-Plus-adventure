#pragma once
#include <string>
#include <vector>
#include "Character.h"
#include "Moves.h"

using namespace std;

class Player : public Character
{
private:
	string _class;
	int _exp;
	vector<string> possible_classes = {"KNIGHT", "RANGER", "MAGE"};

public:
	Player()
	{
		Character();
		_exp = 0;
	}
	
	int get_exp()
	{
		return _exp;
	}

	int add_exp(int value)
	{
		_exp += value;
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
			//add_move(Strike());
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
			//add_move(Strike());
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
			//add_move(Strike());
		}
	}

	void show_stats()
	{
		cout << "Health: " << get_HP() << " / " << get_max_HP() << endl;
		cout << "Strength: " << get_strength() << endl;
		cout << "Defence: " << get_defence() << endl;
		cout << "Magic: " << get_magic() << endl;
		cout << "Magic Defence: " << get_magic_defence() << endl;
		cout << "Mana: " << get_mana() << endl;
		cout << "Speed: " << get_speed() << endl;
	}

	vector<string> get_possible_classes()
	{
		return possible_classes;
	}

};