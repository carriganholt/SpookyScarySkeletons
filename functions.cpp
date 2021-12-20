// Main Function File
// Carrigan Holt

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "functions.h"
#include "map.h"
#include "character.h"

// Input Keys
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// Clear Screen
#define CLEAR_SCREEN if(system("cls")){system("clear");}

using namespace std;

// Gameplay Function
Player play(Map map, Player p) {

	// Creates Enemy
	Enemy enemy;
	enemy.health = 10;
	enemy.attack = 5;

	//Creates Boss
	Enemy boss;
	boss.health = 75;

	// Track Active Level
	static bool gameActive = true;

	// Movement
	printDisplay(map, p);
	int c = 0;
	int damage = 0;

	while (gameActive && p.health > 0) {
		c = 0;
		damage = 0;

		switch ((c = _getch())) {

		// Move Up
		case KEY_UP:
			if (p.locationY > 0 && map.interactments[p.locationX][p.locationY - 1] != WALL) {

					p.locationY--;

				// End Of Level
				if (p.locationX == map.endX && p.locationY == map.endY) {
					CLEAR_SCREEN;
					return p;

				// Potion
				} 
				else if (map.interactments[p.locationX][p.locationY] == 1) {
					p.health += 10;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +10 Health!" << endl;

				// Power Up
				} 
				else if (map.interactments[p.locationX][p.locationY] == 2) {
					p.attack += 1;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Attack!" << endl;

				// Trap
				} 
				else if (map.interactments[p.locationX][p.locationY] == 3) {
					p.health = 0;
					CLEAR_SCREEN
					return p;

				// Enemy Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 4) {
					damage = enemyBattle(p, enemy);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 5;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +5 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					} 
					else {
						CLEAR_SCREEN
						return p;
					}

				// Boss Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 5) {
					damage = bossBattle(p, boss);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 10;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +10 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					} 
					else {
						CLEAR_SCREEN
						return p;
					}

				// Gold
				} 
				else if (map.interactments[p.locationX][p.locationY] == 6) {
					p.gold++;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Gold!" << endl;

				// Empty
				} 
				else {
					printDisplay(map, p);
				}
			} break;

		// Move Down
		case KEY_DOWN:
			if (p.locationY < map.sizeY - 1 && map.interactments[p.locationX][p.locationY + 1] != WALL) {

				p.locationY++;

				// End Of Level
				if (p.locationX == map.endX && p.locationY == map.endY) {
					CLEAR_SCREEN;
					return p;

				// Potion
				} 
				else if (map.interactments[p.locationX][p.locationY] == 1) {
					p.health += 10;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +10 Health!" << endl;

				// Power Up
				} 
				else if (map.interactments[p.locationX][p.locationY] == 2) {
					p.attack += 1;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Attack!" << endl;

				// Trap
				} 
				else if (map.interactments[p.locationX][p.locationY] == 3) {
					p.health = 0;
					CLEAR_SCREEN
					return p;

				// Enemy Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 4) {
					damage = enemyBattle(p, enemy);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 5;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +5 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					} 
					else {
						CLEAR_SCREEN
						return p;
					}

				// Boss Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 5) {
					damage = bossBattle(p, boss);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 10;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +10 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					}
					else {
						CLEAR_SCREEN
							return p;
					}

				// Gold
				} 
				else if (map.interactments[p.locationX][p.locationY] == 6) {
					p.gold++;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Gold!" << endl;

				// Empty
				} 
				else {
					printDisplay(map, p);
				}
			} break;

		// Move Left
		case KEY_LEFT:
			if (p.locationX > 0 && map.interactments[p.locationX - 1][p.locationY] != WALL) {

				p.locationX--;

				// End Of Level
				if (p.locationX == map.endX && p.locationY == map.endY) {
					CLEAR_SCREEN;
					return p;

				// Potion
				} 
				else if (map.interactments[p.locationX][p.locationY] == 1) {
					p.health += 10;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +10 Health!" << endl;
					
				// Power Up
				} 
				else if (map.interactments[p.locationX][p.locationY] == 2) {
					p.attack += 1;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Attack!" << endl;

				// Trap
				} 
				else if (map.interactments[p.locationX][p.locationY] == 3) {
					p.health = 0;
					CLEAR_SCREEN
					return p;

				// Enemy Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 4) {
					damage = enemyBattle(p, enemy);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 5;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +5 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					} 
					else {
						CLEAR_SCREEN
						return p;
					}

				// Boss Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 5) {
					damage = bossBattle(p, boss);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 10;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +10 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					} 
					else {
						CLEAR_SCREEN
						return p;
					}				
				
				// Gold
				} 
				else if (map.interactments[p.locationX][p.locationY] == 6) {
					p.gold++;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Gold!" << endl;

				// Empty
				} 
				else {
					printDisplay(map, p);
				}
			} break;

		// Move Right
		case KEY_RIGHT:
			if (p.locationX < map.sizeX - 1 && map.interactments[p.locationX + 1][p.locationY] != WALL) {

				p.locationX++;

				// End Of Level
				if (p.locationX == map.endX && p.locationY == map.endY) {
					CLEAR_SCREEN;
					return p;

				// Potion
				} 
				else if (map.interactments[p.locationX][p.locationY] == 1) {
					p.health += 10;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +10 Health!" << endl;

				// Power Up
				} 
				else if (map.interactments[p.locationX][p.locationY] == 2) {
					p.attack += 1;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Attack!" << endl;

				// Trap
				} 
				else if (map.interactments[p.locationX][p.locationY] == 3) {
					p.health = 0;
					CLEAR_SCREEN
					return p;

				// Enemy Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 4) {
					damage = enemyBattle(p, enemy);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 5;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +5 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					} 
					else {
						CLEAR_SCREEN
						return p;
					}

				// Boss Battle
				} 
				else if (map.interactments[p.locationX][p.locationY] == 5) {
					damage = bossBattle(p, boss);
					p.health -= damage;
					if (p.health > 0) {
						p.gold += 10;
						map.interactments[p.locationX][p.locationY] = 0;
						printDisplay(map, p);
						cout << endl << "     You won the fight!" << endl << "     +10 Gold!" << endl << "     -" + to_string(damage) + " Health!";
					}
					else {
						CLEAR_SCREEN
							return p;
					}

				// Gold
				} 
				else if (map.interactments[p.locationX][p.locationY] == 6) {
					p.gold++;
					map.interactments[p.locationX][p.locationY] = 0;
					printDisplay(map, p);
					cout << endl << "     +1 Gold!" << endl;

				// Empty
				} 
				else {
					printDisplay(map, p);
				}
			} break;

		// Non-Arrow Key
		default:
			break;
		}
	}
}

// Prints Display
void printDisplay(Map map, Player p) {

	CLEAR_SCREEN
	int width = map.sizeX + 2;

	cout << endl;
	cout << "     Health: " + to_string(p.health) << endl;
	cout << "     Attack: " + to_string(p.attack) << endl;
	cout << "     Gold: " + to_string(p.gold) << endl;

	cout << endl;

	cout << "     Level " + to_string(map.level) << endl << "   ";
	for (int i = 0; i < width; i++) {
		cout << " #";
	} cout << endl;

	for (int i = 0; i < map.sizeY; i++) {
		cout << "    #";
		for (int j = 0; j < map.sizeX; j++) {
			if (j == p.locationX && i == p.locationY) {
				cout << " @"; // Player
			} 
			else if (map.interactments[j][i] == POTION) {
				cout << " +"; // Potion
			} 
			else if (map.interactments[j][i] == POWER_UP) {
				cout << " *"; // Power Up
			} 
			else if (map.interactments[j][i] == TRAP) {
				cout << " ^"; // Trap
			} 
			else if (map.interactments[j][i] == ENEMY) {
				cout << " &"; // Enemy
			} 
			else if (map.interactments[j][i] == BOSS) {
				cout << " ?"; // Boss
			} 
			else if (map.interactments[j][i] == GOLD) {
				cout << " ."; // Gold
			} 
			else if (map.interactments[j][i] == WALL) {
				cout << " #"; // Wall
			} 
			else if (j == map.endX && i == map.endY) {
				cout << " O"; // End Of Level
			} 
			else {
				cout << "  "; // Empty
			}
		} 
		cout << " #" << endl;
	} 
	cout << "   ";

	for (int i = 0; i < width; i++) {
		cout << " #";
	} 
	cout << endl;
}

// Prints High Scores From File
void printHighScores() {

	string scores[3];
	int i = 0;
	ifstream in;
	string line;
	in.open("scores.txt");

	while (getline(in, line)) {
		scores[i] = line;
		i++;
	}

	in.close();

	cout << "                             1st - " + scores[0] << endl;
	cout << "                            2nd --- " + scores[1] << endl;
	cout << "                           3rd ----- " + scores[2] << endl << endl;
}

// Checks For/Sets New High Score
void checkHighScores(int score) {

	string scores[3];
	int i = 0;
	ifstream in;
	string line;
	in.open("scores.txt");

	while (getline(in, line)) {
		scores[i] = line;
		i++;
	}

	in.close();

	int score1 = stoi(scores[0]);
	int score2 = stoi(scores[1]);
	int score3 = stoi(scores[2]);

	if (score < score1 && score < score2 && score > score3) {
		scores[2] = to_string(score);
	}
	else if (score < score1 && score > score2) {
		scores[2] = scores[1];
		scores[1] = to_string(score);
	}
	else if (score > score1) {
		scores[2] = scores[1];
		scores[1] = scores[0];
		scores[0] = to_string(score);
	}

	ofstream myFile("scores.txt");
	myFile << scores[0] << endl << scores[1] << endl << scores[2];
}