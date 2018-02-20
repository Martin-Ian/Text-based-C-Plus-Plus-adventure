#pragma once

#include "Character.h"
#include "Moves.h"

using namespace std;

class Enemy : public Character
{
public:
	Enemy()
	{
		Character();
	}
};

class Snail : public Enemy
{
public:
	Snail()
	{
		Enemy();
		set_name("Snail");
		set_HP(50);
		set_strength(3);
		set_defence(4);
		set_magic(1);
		set_magic_defence(2);
		set_mana(1);
		set_speed(2);
	}
};