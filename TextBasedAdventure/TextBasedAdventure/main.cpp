//Includes
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "GameState.h"
#include "Battle.h"
#include "Moves.h"

using namespace std;

int main()
{
	srand(time(NULL));

	//GameState comtrols the game making main nice and clean
	GameState* game = new GameState();

	//This sets up the game if no save file is detected
	game->setup(); 
	game->startGame();
}