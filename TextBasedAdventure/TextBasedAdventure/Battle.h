#pragma once
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Battle
{
public:
	void battle(Player* the_player, Enemy* the_enemy)
	{
		cout << "BATTLE START!" << endl << endl;
		cout << the_player->get_name() << "\'s HP: " << the_player->get_HP() << "/" << the_player->get_max_HP() << endl;
		cout << the_enemy->get_name() << "\'s HP: " << the_enemy->get_HP() << "/" << the_enemy->get_max_HP() << endl;
		while (the_player->get_HP() > 0 && the_enemy->get_HP() > 0)
		{
			while (the_player->get_counter() < 100 && the_enemy->get_counter() < 100)
			{
				the_player->add_speed();
				the_enemy->add_speed();
			}

			if (the_player->get_counter() >= 100)
			{
				cout << the_player->get_name() << "\'s HP: " << the_player->get_HP() << "/" << the_player->get_max_HP() << endl;
				cout << the_enemy->get_name() << "\'s HP: " << the_enemy->get_HP() << "/" << the_enemy->get_max_HP() << endl;
				the_player->reset_counter();
				int damage = the_player->get_strength();
				cout << "You hit the enemy for " << damage << " damage." << endl;
				the_enemy->take_damage(damage);
			}

			if (the_enemy->get_counter() >= 100)
			{
				the_enemy->reset_counter();
				int damage = the_enemy->get_strength();
				cout << "You got hit for " << damage << " damage." << endl;
				the_player->take_damage(damage);
			}
		}
		cout << "You have " << the_player->get_HP() << " health left." << endl;
	}
};