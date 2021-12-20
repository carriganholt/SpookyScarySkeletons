// Character Header File
// Carrigan Holt

#ifndef CHARACTER_H
#define CHARACTER_H

struct character {
	int locationX;
	int locationY;
	int health;
	int attack;
	int gold;
};

typedef character Player;
typedef character Enemy;
typedef character Boss;

int enemyBattle(Player p, Enemy e);
int bossBattle(Player p, Boss b);

#endif