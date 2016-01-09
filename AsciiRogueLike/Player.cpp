#include "Player.h"
#include <random>
#include <ctime>
#include <iostream>

Player::Player()
{
	_x = 0;
	_y = 0;
}

void Player::init(int level, int health, int attack, int defense, int experience)
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}

void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Player::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

void Player::addExperience(int experience)
{
	_experience += experience;
	while (_experience > 50) {
		std::cout << "LEVELED UP" << std::endl;
		system("PAUSE");
		_level++;
		_attack += 10;
		_defense += 5;
		_health += 10;
		_experience -= 50;
	}
}

int Player::attack()
{
	static std::default_random_engine randomEngine(time(0));
	std::uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Player::takeDamage(int attack)
{
	attack -= _defense;
	//Check if the attack does damage
	if (attack > 0) {
		_health -= attack;
		//Check if he died
		if (_health <= 0)
			return 1;
	}
	return 0;
}