#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <istream>
#include "Player.h"

using namespace std;

int main()
{
	cout << "Making new Player" << endl;
	Player* player = new Player();
	cout << player->get_max_HP() << endl;
	return 0;
}