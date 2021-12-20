// Main Driver File
// Carrigan Holt
//
// ********************************** Rubric **********************************
//   -Code Quality: Comments/Organization
//   -Multiple Files: Seperated files by main gameplay, character, and map.
//   -Functionality: LOTS of testing to ensure you cannot break it.
//   -Enum: Used to assign spaces a specific characteristic.
//   -Extern: Used for player starting stats.
//   -Static: Used to keep track of active game and active level.
//   -Struct: Used for maps and characters
//   -RNG: Used to randomly place objects on the map
// ****************************************************************************

#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include "functions.h"
#include "character.h"
#include "map.h"

// Clear Screen
#define CLEAR_SCREEN if(system("cls")){system("clear");}

using namespace std;
extern int startHealth = 100;
extern int startAttack = 1;
extern int startGold = 0;

// Driver Function
int main() {

	SetConsoleTitle(L"Spooky Scary Skeletons");
	srand(time(NULL));

	static bool gameActive = true;
	while (gameActive) {

		// Creates Player
		Player p1;
		p1.health = startHealth;
		p1.attack = startAttack;
		p1.gold = startGold;

		//     INTERACTION GUIDE
		// * * * * * * * * * * * * *
		// *   0 - Empty - " "     *
		// *   1 - Potion - "+"    *
		// *   2 - Power Up - "#"  *
		// *   3 - Trap - "^"      *
		// *   4 - Enemy - "&"     *
		// *   5 - Boss - "?"      *
		// *   6 - Gold - "."      *
		// *   7 - Wall - "#"      *
		// * * * * * * * * * * * * *

		// Creates Map 1
		Map map1;
		map1.level = 1;
		map1.sizeX = 21;
		map1.sizeY = 21;
		map1.startX = 10;
		map1.startY = 0;
		map1.endX = 10;
		map1.endY = 19;

		// Sets Map 1 Interactments
		map1.interactments = new int*[map1.sizeX];
		for (int i = 0; i < map1.sizeX; i++) {
			map1.interactments[i] = new int[map1.sizeY];
			for (int j = 0; j < map1.sizeY; j++) {

				if (i == map1.startX && j == map1.startY) {}
				else if (i == map1.endX && j == map1.endY) {} 
				else {
				
					// Random Interactments
					int num = rand() % 100;

					if (num == 1) {
						map1.interactments[i][j] = POTION;
					}
					else if (num == 2) {
						map1.interactments[i][j] = POWER_UP;
					}
					else if (num >= 3 && num <= 5) {
						map1.interactments[i][j] = ENEMY;
					}
					else if (num >= 6 && num <= 20) {
						map1.interactments[i][j] = GOLD;
					}
					else if (num >= 21 && num <= 23) {
						map1.interactments[i][j] = TRAP;
					}
					else {
						map1.interactments[i][j] = EMPTY;
					}
				}
			}
		}
		map1.interactments[6][20] = WALL;
		map1.interactments[6][19] = WALL;
		map1.interactments[6][18] = WALL;
		map1.interactments[6][17] = WALL;
		map1.interactments[7][17] = WALL;
		map1.interactments[8][17] = WALL;
		map1.interactments[12][17] = WALL;
		map1.interactments[13][17] = WALL;
		map1.interactments[14][17] = WALL;
		map1.interactments[14][18] = WALL;
		map1.interactments[14][19] = WALL;
		map1.interactments[14][20] = WALL;

		// Creates Map 2
		Map map2;
		map2.level = 2;
		map2.sizeX = 11;
		map2.sizeY = 11;
		map2.startX = 5;
		map2.startY = 0;
		map2.endX = 5;
		map2.endY = 10;

		// Sets Map 2 Interactments
		map2.interactments = new int* [map2.sizeX];
		for (int i = 0; i < map2.sizeX; i++) {
			map2.interactments[i] = new int[map2.sizeY];
			for (int j = 0; j < map2.sizeY; j++) {

				if (i == map2.startX && j == map2.startY) {}
				else if (i == map2.endX && j == map2.endY) {}
				else {

					// Random Interactments
					int num = rand() % 100;

					if (num == 1) {
						map2.interactments[i][j] = POTION;
					}
					else if (num == 2) {
						map2.interactments[i][j] = POWER_UP;
					}
					else if (num >= 3 && num <= 5) {
						map2.interactments[i][j] = ENEMY;
					}
					else if (num >= 6 && num <= 20) {
						map2.interactments[i][j] = GOLD;
					}
					else if (num >= 21 && num <= 23) {
						map2.interactments[i][j] = TRAP;
					}
					else {
						map2.interactments[i][j] = EMPTY;
					}
				}
			}
		}

		// Creates Map 3
		Map map3;
		map3.level = 3;
		map3.sizeX = 5;
		map3.sizeY = 10;
		map3.startX = 2;
		map3.startY = 0;
		map3.endX = 2;
		map3.endY = 9;

		// Sets Map 3 Interactments
		map3.interactments = new int* [map3.sizeX];
		for (int i = 0; i < map3.sizeX; i++) {
			map3.interactments[i] = new int[map3.sizeY];
			for (int j = 0; j < map3.sizeY; j++) {

				if (i == map3.startX && j == map3.startY) {}
				else if (i == map3.endX && j == map3.endY) {}
				else {

					// Random Interactments
					int num = rand() % 100;

					if (num == 1) {
						map3.interactments[i][j] = POTION;
					}
					else if (num == 2) {
						map3.interactments[i][j] = POWER_UP;
					}
					else if (num >= 3 && num <= 5) {
						map3.interactments[i][j] = ENEMY;
					}
					else if (num >= 6 && num <= 20) {
						map3.interactments[i][j] = GOLD;
					}
					else if (num >= 21 && num <= 23) {
						map3.interactments[i][j] = TRAP;
					}
					else {
						map3.interactments[i][j] = EMPTY;
					}
				}
			}
		}
		map3.interactments[0][0] = TRAP;
		map3.interactments[0][1] = TRAP;
		map3.interactments[0][2] = TRAP;
		map3.interactments[0][3] = TRAP;
		map3.interactments[0][4] = TRAP;
		map3.interactments[0][5] = TRAP;
		map3.interactments[0][6] = TRAP;
		map3.interactments[0][7] = TRAP;
		map3.interactments[0][8] = TRAP;
		map3.interactments[0][9] = TRAP;

		map3.interactments[4][0] = TRAP;
		map3.interactments[4][1] = TRAP;
		map3.interactments[4][2] = TRAP;
		map3.interactments[4][3] = TRAP;
		map3.interactments[4][4] = TRAP;
		map3.interactments[4][5] = TRAP;
		map3.interactments[4][6] = TRAP;
		map3.interactments[4][7] = TRAP;
		map3.interactments[4][8] = TRAP;
		map3.interactments[4][9] = TRAP;

		// Creates Map 4
		Map map4;
		map4.level = 4;
		map4.sizeX = 19;
		map4.sizeY = 11;
		map4.startX = 9;
		map4.startY = 0;
		map4.endX = 9;
		map4.endY = 10;

		// Sets Map 4 Interactments
		map4.interactments = new int* [map4.sizeX];
		for (int i = 0; i < map4.sizeX; i++) {
			map4.interactments[i] = new int[map4.sizeY];
			for (int j = 0; j < map4.sizeY; j++) {

				if (i == map4.startX && j == map4.startY) {}
				else if (i == map4.endX && j == map4.endY) {}
				else {

					// Random Interactments
					int num = rand() % 100;

					if (num == 1) {
						map4.interactments[i][j] = POTION;
					}
					else if (num == 2) {
						map4.interactments[i][j] = POWER_UP;
					}
					else if (num >= 3 && num <= 5) {
						map4.interactments[i][j] = ENEMY;
					}
					else if (num >= 6 && num <= 20) {
						map4.interactments[i][j] = GOLD;
					}
					else if (num >= 21 && num <= 23) {
						map4.interactments[i][j] = TRAP;
					}
					else {
						map4.interactments[i][j] = EMPTY;
					}
				}
			}
		}
		map4.interactments[1][3] = WALL;
		map4.interactments[1][7] = WALL;
		map4.interactments[3][1] = WALL;
		map4.interactments[3][5] = WALL;
		map4.interactments[3][9] = WALL;
		map4.interactments[5][3] = WALL;
		map4.interactments[5][7] = WALL;
		map4.interactments[7][1] = WALL;
		map4.interactments[7][5] = WALL;
		map4.interactments[7][9] = WALL;
		map4.interactments[9][3] = WALL;
		map4.interactments[9][7] = WALL;
		map4.interactments[11][1] = WALL;
		map4.interactments[11][5] = WALL;
		map4.interactments[11][9] = WALL;
		map4.interactments[13][3] = WALL;
		map4.interactments[13][7] = WALL;
		map4.interactments[15][1] = WALL;
		map4.interactments[15][5] = WALL;
		map4.interactments[15][9] = WALL;
		map4.interactments[17][3] = WALL;
		map4.interactments[17][7] = WALL;

		// Creates Map 5
		Map map5;
		map5.level = 5;
		map5.sizeX = 7;
		map5.sizeY = 15;
		map5.startX = 3;
		map5.startY = 0;
		map5.endX = 3;
		map5.endY = 14;

		// Sets Map 5 Interactments
		map5.interactments = new int* [map5.sizeX];
		for (int i = 0; i < map5.sizeX; i++) {
			map5.interactments[i] = new int[map5.sizeY];
			for (int j = 0; j < map5.sizeY; j++) {

				if (i == map5.startX && j == map5.startY) {}
				else if (i == map5.endX && j == map5.endY) {}
				else {

					// Random Interactments
					int num = rand() % 100;

					if (num == 1) {
						map5.interactments[i][j] = POTION;
					}
					else if (num == 2) {
						map5.interactments[i][j] = POWER_UP;
					}
					else if (num >= 3 && num <= 5) {
						map5.interactments[i][j] = ENEMY;
					}
					else if (num >= 6 && num <= 20) {
						map5.interactments[i][j] = GOLD;
					}
					else if (num >= 21 && num <= 23) {
						map5.interactments[i][j] = TRAP;
					}
					else {
						map5.interactments[i][j] = EMPTY;
					}
				}
			}
		}
		map5.interactments[2][14] = TRAP;
		map5.interactments[1][14] = TRAP;
		map5.interactments[0][14] = TRAP;
		map5.interactments[1][13] = TRAP;
		map5.interactments[0][13] = TRAP;
		map5.interactments[0][12] = TRAP;

		map5.interactments[4][14] = TRAP;
		map5.interactments[5][14] = TRAP;
		map5.interactments[6][14] = TRAP;
		map5.interactments[5][13] = TRAP;
		map5.interactments[6][13] = TRAP;
		map5.interactments[6][12] = TRAP;

		map5.interactments[3][13] = BOSS;

		// Array For All Maps
		int levels = 5;
		Map* maps = new Map[levels];

		// Sets Level Order
		maps[0] = map1;
		maps[1] = map2;
		maps[2] = map3;
		maps[3] = map4;
		maps[4] = map5;

		// Title Music
		PlaySoundA("title.wav", NULL, SND_LOOP|SND_ASYNC);
	
		// Title Screen
		cout << endl;
		cout << "            _________                     __ " << endl;
		cout << "           /   _____/_____   ____   ____ |  | _____ __  " << endl;
		cout << "           \\_____  \\\\____ \\ /  _ \\ /  _ \\|  |/ <   |  | " << endl;
		cout << "           /        \\  |_> >  <_> |  <_> )    < \\___  | " << endl;
		cout << "          /_______  /   __/ \\____/ \\____/|__|_ \\/ ____| " << endl;
		cout << "                  \\/|__|                      \\/\\/ " << endl;
		cout << "               _________ " << endl;
		cout << "              /   _____/ ____ _____ _______ ___ __  " << endl;
		cout << "              \\_____  \\_/ ___\\\\__  \\\\_  __ <   |  | " << endl;
		cout << "              /        \\  \\___ / __ \\|  | \\/\\___  | " << endl;
		cout << "             /_______  /\\___  >____  /__|   / ____| " << endl;
		cout << "                     \\/     \\/     \\/       \\/ " << endl;
		cout << "    ___________           __          __ " << endl;
		cout << "   /   _____/  | __ ____ |  |   _____/  |_  ____   ____   ______ " << endl;
		cout << "   \\_____  \\|  |/ // __ \\|  | _/ __ \\   __\\/  _ \\ /    \\ /  ___/ " << endl;
		cout << "   /        \\    <\\  ___/|  |_\\  ___/|  | (  <_> )   |  \\\\___ \\ " << endl;
		cout << "  /_______  /__|_ \\\\___  >____/\\___  >__|  \\____/|___|  /____  > " << endl;
		cout << "          \\/     \\/    \\/          \\/                 \\/     \\/ " << endl;

		cout << endl << "                    Developed by Carrigan Games" << endl << endl << endl << endl;

		printHighScores();
		cout << endl << endl << "                  ";

		system("pause");
		CLEAR_SCREEN

		// Information Screen
		cout << endl << endl << endl;
		cout << "            Player = @" << endl;
		cout << "              Goal = O" << endl;
		cout << "            Potion = +" << endl;
		cout << "          Power-Up = *" << endl;
		cout << "              Gold = ." << endl;
		cout << "              Trap = ^" << endl;
		cout << "             Enemy = &" << endl;
		cout << "              Boss = ?" << endl << endl << endl << "   ";
		system("pause");
		CLEAR_SCREEN

		// Plays Through Levels
		for (int i = 0; i < levels; i++) {

			// Sets Player To Start Location
			p1.locationX = maps[i].startX;
			p1.locationY = maps[i].startY;

			// Gameplay Music
			PlaySoundA("gameplay.wav", NULL, SND_LOOP | SND_ASYNC);

			p1 = play(maps[i], p1);

			// Win Screens
			if (p1.health > 0) {

				if (i == levels - 1) {

					// Game Win Sound
					PlaySoundA("win.wav", NULL, SND_ASYNC);
					cout << endl << endl;

					cout << "          _____ ___                __      __ __       _ " << endl;
					cout << "          \\__  |   | ____  __ __  /  \\    /  \\__| ____| | " << endl;
					cout << "           /   |   |/  _ \\|  |  \\ \\   \\/\\/   /  |/    \\ | " << endl;
					cout << "           \\____   (  <_> )  |  /  \\        /|  |   |  \\| " << endl;
					cout << "           / ______|\\____/|____/    \\__/\\  / |__|___|  /_ " << endl;
					cout << "           \\/                            \\/          \\/\\/ " << endl << endl;
					cout << "                            - Score: " + to_string(p1.gold + p1.health + p1.attack) + " -";
					cout << endl;
					cout << "             /\\                                       /\\ " << endl;
					cout << "   _         )( _________________   _________________ )(         _ " << endl;
					cout << "  (_)///////(**)_________________> <_________________(**)\\\\\\\\\\\\\\(_) " << endl;
					cout << "             )(                                       )( " << endl;
					cout << "             \\/                                       \\/ " << endl << endl << endl << "                   ";

					checkHighScores(p1.gold + p1.health + p1.attack);

					system("pause");
					CLEAR_SCREEN

				} else {

					// Level Complete Sound
					PlaySoundA("levelcomplete.wav", NULL, SND_ASYNC);
					cout << endl << endl;
					cout << "               ____                       __ " << endl;
					cout << "              |    |    _______  __ ____ |  | " << endl;
					cout << "              |    |  _/ __ \\  \\/ // __ \\|  | " << endl;
					cout << "              |    |__\\  ___/\\   /\\  ___/|  |__ " << endl;
					cout << "              |_______ \\___  >\\_/  \\___  >____/ " << endl;
					cout << "     	              \\/   \\/          \\/ " << endl;
					cout << "   _________                        __          __ " << endl;
					cout << "   \\_   ___ \\  ____   _____ ______ |  |   _____/  |_  ____ " << endl;
					cout << "   /    \\  \\/ /  _ \\ /     \\\\____ \\|  | _/ __ \\   __\\/ __ \\ " << endl;
					cout << "   \\     \\___(  <_> )  Y Y  \\  |_> >  |_\\  ___/|  | \\  ___/ " << endl;
					cout << "    \\______  /\\____/|__|_|  /   __/|____/\\___  >__|  \\___  > " << endl;
					cout << "           \\/             \\/|__|             \\/          \\/ " << endl;
					cout << endl << endl << "               ";

					system("pause");
					CLEAR_SCREEN
				}

			// Lose Screen
			} else {

				// Lose Sound
				PlaySoundA("lose.wav", NULL, SND_ASYNC);
				cout << endl << endl;

				cout << "    _____ ___                ____                                    " << endl;
				cout << "    \\__  |   | ____  __ __  |    |    ____  ______ ____              " << endl;
				cout << "     /   |   |/  _ \\|  |  \\ |    |   /  _ \\/  ___// __ \\             " << endl;
				cout << "     \\____   (  <_> )  |  / |    |__(  <_> )___ \\\\  ___/             " << endl;
				cout << "     / ______|\\____/|____/  |_______ \\____/____  >\\___  > /\\ /\\ /\\ " << endl;
				cout << "     \\/                             \\/         \\/     \\/  \\/ \\/ \\/ " << endl << endl;
				
				cout << "                                         ,--. " << endl;
				cout << "                                        {    } " << endl;
				cout << "                                        K,   } " << endl;
				cout << "                                       /  `Y` " << endl;
				cout << "                                  _   /   / " << endl;
				cout << "                                 {_'-K.__/ " << endl;
				cout << "                                   `/-.__L._ " << endl;
				cout << "                                   /  ' /`\\_} " << endl;
				cout << "                           ____   /  ' / " << endl;
				cout << "                    ,-'~~~~    ~~/  ' /_ " << endl;
				cout << "                  ,'             ``~~~%%', " << endl;
				cout << "                 (                     %  Y " << endl;
				cout << "                {                      %% I " << endl;
				cout << "               {      -                 %  `. " << endl;
				cout << "               |       ',                %  ) " << endl;
				cout << "               |        |   ,..__      __. Y " << endl;
				cout << "               |    .,_./  Y ' / ^Y   J   )| " << endl;
				cout << "               \\           |' /   |   |   || " << endl;
				cout << "                \\          L_/    . _ (_,.'( " << endl;
				cout << "                 \\,   ,      ^^""' / |      ) " << endl;
				cout << "                   \\_  \\          /,L]     / " << endl;
				cout << "                     '-_`-,       ` `   ./` " << endl;
				cout << "                        `-(_            ) " << endl;
				cout << "                            ^^\\..___,.--` " << endl << endl << endl << endl << "                  ";

				system("pause");
				CLEAR_SCREEN
				break;
			}
		}
	}
}