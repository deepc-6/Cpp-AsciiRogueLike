#ifndef GAME_H
#define GAME_H

#include "Level.h"
#include "Player.h"
#include <string>

class Game
{
private:
	Level _level;
	Player _player;
public:
	Game(std::string levelFileName);

	void playGame();
	void playerMove();
};

#endif // GAME_H