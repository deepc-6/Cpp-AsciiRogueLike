#include "Game.h"
#include <iostream>
#include <conio.h>

Game::Game(std::string levelFileName)
{
	_player.init(1, 100, 10, 10, 0);
	_level.load("level1.txt", _player);
}

void Game::playGame()
{
	bool isDone = false;
	while (!isDone) {
		_level.print();
		playerMove();
		_level.updateEnemies(_player);
	}
}

void Game::playerMove()
{
	char input;
	std::cout << "Enter a move command" << std::endl;
	input = _getch();
	_level.movePlayer(input, _player);
}