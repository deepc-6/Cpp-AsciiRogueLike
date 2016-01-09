#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy
{
private:
	std::string _name;
	char _tile;
	int _x, _y, _level, _attack, _defense, _health, _experienceValue;
public:
	Enemy(std::string name, char tile, int level, int attack, int defense, int health, int xp);
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);
	std::string getName() { return _name; }
	char getTile() { return _tile; }
	int attack();
	int takeDamage(int attack);
	char getMove(int playerX, int playerY);
};

#endif // ENEMY_H