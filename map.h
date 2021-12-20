// Map Header File
// Carrigan Holt

#ifndef MAP_H
#define MAP_H

struct Map {
	int level;
	int sizeX;
	int sizeY;
	int startX;
	int startY;
	int endX;
	int endY;
	int** interactments;
};

enum items {
	EMPTY,
	POTION,
	POWER_UP,
	TRAP,
	ENEMY,
	BOSS,
	GOLD,
	WALL
};

#endif