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
			}

			if (the_enemy->get_counter() >= 100 && the_enemy->get_HP() > 0)
			{
				the_enemy->reset_counter();
				vector<Moves> enemy_moves = the_enemy->get_moves();
				cast(enemy_moves[0], the_enemy, the_player);
			}
		}
		cout << the_player->get_name() << "\'s HP: " << the_player->get_HP() << "/" << the_player->get_max_HP() << endl;
		cout << the_enemy->get_name() << "\'s HP: " << the_enemy->get_HP() << "/" << the_enemy->get_max_HP() << endl;
	}
	
	void player_move(Player* the_player, Enemy* the_enemy)
	{
		string move;
		bool confirmed = false;
		vector<Moves> temp = the_player->get_moves();
		cout << the_player->get_name() << "\'s HP: " << the_player->get_HP() << "/" << the_player->get_max_HP() << endl;
		cout << the_enemy->get_name() << "\'s HP: " << the_enemy->get_HP() << "/" << the_enemy->get_max_HP() << endl;
		while (confirmed == false)
		{
			cout << "What would you like to do?" << endl;
			for (int i = 0; i < temp.size(); i++)
			{
				cout << (i+1) << ": " << temp[i].get_name() << endl;
			}
			getline(cin, move);

			int index = stoint(move);

			if (index == -1 || index >= temp.size())
			{
				cout << "Invalid input." << endl;
			}
			else if (the_player->get_mana() < temp[index].get_cost())
			{
				cout << "Not enough mana." << endl;
			}
			else
			{
				system("CLS");
				confirmed = true;
				cast(temp[index], the_player, the_enemy);
			}
		}
		
	}
	
	int stoint(string value)
	{
		if (value == "1")
		{
			return 0;
		}
		else if (value == "2")
		{
			return 1;
		}
		else if (value == "3")
		{
			return 2;
		}
		else if (value == "4")
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
			int damage;
			if (the_move.is_crit())
			{
				cout << "Critical hit!" << endl;
				float ratio = (1.0 * user->get_strength()) / (1.0 * target->get_defence()) + 1.5;
				damage = floor(((-1 / ((2 * ratio * ratio) + ratio + 1) + 1) * (the_move.get_power() + 1.0)) * user->get_strength());
				damage += rand() % 3 - 1;
				if (damage < 2)
				{
					damage = 2;
				}
			}
			else
			{
				float ratio = (1.0 * user->get_strength()) / (1.0 * target->get_defence());
				damage = floor(((-1 / ((2 * ratio * ratio) + ratio + 1) + 1) * the_move.get_power()) * user->get_strength());
				damage += rand() % 3 - 1;
				if (damage < 1)
				{
					damage = 1;
				}
			}
			cout << user->get_name() << " strikes " << target->get_name() << " for " << damage << " damage" << endl;
			target->take_damage(damage);
		}
		else if (the_move.get_name() == "Magic Bolt")
		{
			user->use_mana(the_move.get_cost());
			int damage;
			if (the_move.is_crit())
			{
				cout << "Critical hit!" << endl;
				float ratio = (1.0 * user->get_magic()) / (1.0 * target->get_magic_defence()) + 1.5;
				damage = floor(((-1 / ((2 * ratio * ratio) + ratio + 1) + 1) * (the_move.get_power() + 1.0)) * user->get_magic());
				damage += rand() % 3 - 1;
				if (damage < 2)
				{
					damage = 2;
				}
			}
			else
			{
				float ratio = (1.0 * user->get_magic()) / (1.0 * target->get_magic_defence());
				damage = floor(((-1 / ((2 * ratio * ratio) + ratio + 1) + 1) * the_move.get_power()) * user->get_magic());
				damage += rand() % 3 - 1;
				if (damage < 1)
				{
					damage = 1;
				}
			}
			cout << user->get_name() << " shoots a Bolt of Magic at " << target->get_name() << " for " << damage << " damage" << endl;
			cout << user->get_name() << " has " << user->get_mana() << " mana left." << endl;
			target->take_damage(damage);
		}
		else if (the_move.get_name() == "Heal" || the_move.get_name() == "Mini Heal")
		{
			user->use_mana(the_move.get_cost());
			float ratio = 1.0;
			int damage = floor(((-1 / ((2 * ratio * ratio) + ratio + 1) + 1) * the_move.get_power()) * ((user->get_magic() * 1.5) + user->get_strength()));
			damage += rand() % 3 - 1;
			if (damage < 1)
			{
				damage = 1;
			}
			cout << user->get_name() << " Heals for " << damage << " health" << endl;
			cout << user->get_name() << " has " << user->get_mana() << " mana left." << endl;
			user->heal(damage);
		}
		else if (the_move.get_name() == "Restore Mana")
		{
			cout << user->get_name() << " regains 1 mana" << endl;
			user->add_mana(1);
			cout << user->get_name() << " has " << user->get_mana() << " mana left." << endl;
		}
	}

};