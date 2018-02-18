#pragma once
#include "Character.h"
#include "Player.h"
#include "Battle.h"

using namespace std;
class GameState
{
private:
	Player* player;
public:
	GameState()
	{
		//Intentionally blank
		//Look at 'setup' for actual initialazation
	}

	void setup()
	{
		cout << "Welcome to The Adventure!" << endl;

		string responce;
		bool selection_confirmed = false;

		do
		{
			cout << "Would you like to continue or start a new game?" << endl;
			cout << "(\'C\' to continue, \'N\' for a new game) --> ";

			getline(cin, responce);

			if (responce == "C" || responce == "c")
			{
				cout << "This is not implemented..." << endl;
				cout << "No save file detected." << endl;
			}
			else if (responce == "N" || responce == "n")
			{
				cout << "You have selected to start a new game. Is this correct?" << endl;
				cout << "(\'Y\' for yes, \'N\' for no) --> ";

				getline(cin, responce);

				if (responce == "Y" || responce == "y")
				{
					cout << "Selection Confirmed." << endl;
					selection_confirmed = true;
				}

			}
			else
			{
				cout << "Unknown responce \'" << responce << "\'. Try again." << endl;
			}

		} while (selection_confirmed == false);

		if (player == nullptr)
		{
			selection_confirmed = false;
			player = new Player();

			cout << "Welcome to The Adventure!" << endl;

			do
			{
				cout << "Before we start, What is your name?" << endl;
				cout << "Your name: ";

				getline(cin, responce);
				player->set_name(responce);

				cout << "You entered \'" << responce << "\' as your name." << endl;
				cout << "Is this correct? (\'Y\' for yes, \'N\' for no.) --> ";

				getline(cin, responce);

				if (responce == "Y" || responce == "y")
				{
					cout << "Your name is now " << player->get_name() << endl;
					selection_confirmed = true;
				}

			} while (selection_confirmed == false);

			selection_confirmed = false;

			do
			{
				cout << "What class would you like to be?" << endl;
				cout << "Possible classes: ";
				vector<string> temp = player->get_possible_classes();
				for (int i = 0; i < temp.size(); i++)
				{
					cout << temp[i] << " ";
				}
				cout << endl;
				cout << "Class name: ";

				getline(cin, responce);


				for (int i = 0; i < responce.size(); i++)
				{
					responce[i] = toupper(responce[i]);
				}

				if (contains(player->get_possible_classes(), responce))
				{

					player->set_class(responce);

					cout << "You entered \'" << responce << "\' as your class." << endl;
					player->show_stats();
					cout << "Is this correct? (\'Y\' for yes, \'N\' for no.) --> ";

					getline(cin, responce);

					if (responce == "Y" || responce == "y")
					{
						cout << "Your class is now " << player->get_class() << endl;
						selection_confirmed = true;
					}

				}
				else
				{
					cout << "Class not reconized." << endl;
				}

			} while (selection_confirmed == false);

			selection_confirmed = false;
		}
	}

	void startGame()
	{
		Battle battles;
		Enemy* enemy = new Enemy();
		battles.battle(player, enemy);
	}

	bool contains(vector<string> vect, string item)
	{
		for (int i = 0; i < vect.size(); i++)
		{
			if (item == vect[i])
			{
				return true;
			}
		}
		return false;
	}
};