#pragma once
#include "IAnimalFactroy.h"

class GameManager
{
public:
	void start();
	void update();
	void draw();
	private:
	GameManager();
	~GameManager();
	std::unique_ptr<IAnimalFactory> _factory;
	std::unique_ptr<Player> _player;

};
