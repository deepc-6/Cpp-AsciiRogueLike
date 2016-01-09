#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	int _x, _y, _z, _level, _health, _attack, _defense, _experience;
public:
	Player();

	void init(int level, int health, int attack, int defense, int experience);
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);
	void addExperience(int experience);
	int attack();
	int takeDamage(int attack);
};

#endif // PLAYER_H