#include "Enemy.h"
#include <random>
#include <ctime>

Enemy::Enemy(std::string name, char tile, int level, int attack, int defense, int health, int xp)
{
	_x = _y = 0;
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;
}

void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Enemy::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

int Enemy::attack()
{
	static std::default_random_engine randomEngine(time(0));
	std::uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack)
{
	attack -= _defense;
	//Check if the attack does damage
	if (attack > 0) {
		_health -= attack;
		//Check if he died
		if (_health <= 0)
			return _experienceValue;
	}
	return 0;
}

char Enemy::getMove(int playerX, int playerY)
{
	static std::default_random_engine randomEngine(time(0));
	std::uniform_int_distribution<int> moveRoll(0, 6);

	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	int distanceFromPlayer = adx + ady;

	if (distanceFromPlayer <= 5) {
		//Moving along X-axis
		if (adx > ady) {
			if (dx > 0)
				return 'a';
			else
				return 'd';
		}
		//Moving along Y-axis
		else {
			if (dy > 0)
				return 'w';
			else
				return 's';
		}
	}
	int randomMove = moveRoll(randomEngine);
	switch (randomMove)
	{
	case 0:
		return 'w';
	case 1:
		return 's';
	case 2:
		return 'a';
	case 3:
		return 'd';
	default:
		return '.';
	}
}