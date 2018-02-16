//Includes
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include "Player.h"
#include "GameState.h"

using namespace std;

int main()
{
	//GameState comtrols the game making main nice and clean
	GameState* game = new GameState();

	//This sets up the game if no save file is detected
	game->setup(); 
	game->startGame();
}