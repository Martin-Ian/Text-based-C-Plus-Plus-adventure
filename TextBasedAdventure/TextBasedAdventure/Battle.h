#pragma once
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Moves.h"

using namespace std;

class Battle
{
public:
	
	void battle(Player* the_player, Enemy* the_enemy)
	{
		cout << "BATTLE START!" << flush << endl;
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
				the_player->reset_counter();
				player_move(the_player, the_enemy);
				cout << the_enemy->get_name() << "\'s HP: " << the_enemy->get_HP() << "/" << the_enemy->get_max_HP() << endl;
			}

			if (the_enemy->get_counter() >= 100 && the_enemy->get_HP() > 0)
			{
				the_enemy->reset_counter();
				vector<Moves> enemy_moves = the_enemy->get_moves();
				cast(enemy_moves[0], the_enemy, the_player);
				cout << the_player->get_name() << "\'s HP: " << the_player->get_HP() << "/" << the_player->get_max_HP() << endl;
			}
		}
		cout << "You have " << the_player->get_HP() << " health left." << endl;
	}
	
	void player_move(Player* the_player, Enemy* the_enemy)
	{
		string move;
		bool confirmed = false;
		vector<Moves> temp = the_player->get_moves();
		while (confirmed == false)
		{
			cout << "What would you like to do?" << endl;
			for (int i = 0; i < temp.size(); i++)
			{
				cout << i << ": " << temp[i].get_name() << endl;
			}
			getline(cin, move);

			int index = stoint(move);

			if (index == -1 || index >= temp.size())
			{
				cout << "Invalid input." << endl;
			}
			else
			{
				confirmed = true;
				cast(temp[index], the_player, the_enemy);
			}
		}
		
	}
	
	int stoint(string value)
	{
		if (value == "0")
		{
			return 0;
		}
		else if (value == "1")
		{
			return 1;
		}
		else if (value == "2")
		{
			return 2;
		}
		else if (value == "3")
		{
			return 3;
		}
		else
		{
			return -1;
		}
	}

	void cast(Moves the_move, Character* user, Character* target)
	{
		if (the_move.get_name() == "Strike")
		{
			int damage = user->get_strength();
			cout << user->get_name() << " strikes " << target->get_name() << " for " << damage << " damage" << endl;
			target->take_damage(damage);
		}
	}

};