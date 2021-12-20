// Main Header File
// Carrigan Holt

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "character.h"
#include "map.h"

Player play(Map map, Player p);
void printDisplay(Map map, Player p);
void printHighScores();
void checkHighScores(int score);

#endif