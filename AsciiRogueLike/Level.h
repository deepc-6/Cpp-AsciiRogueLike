#ifndef LEVEL_H
#define LEVEL_H

#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

class Level
{
private:
	std::vector<std::string> _levelData;
	std::vector<Enemy> _enemies;
	void processPlayerMove(Player &player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
public:
	Level();

	void setTile(int x, int y, char tile);
	char getTile(int x, int y);
	void load(std::string fileName, Player &player);
	void print();
	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);
};

#endif // LEVEL_H