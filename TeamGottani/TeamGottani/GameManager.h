#pragma once

class GameManager
{
public:
	void start();
	void update();
	void draw();
	private:
	GameManager();
	~GameManager();
	std::unique_ptr<AnimalFactroy> _factory;
	std::unique_ptr<GameObject> _player;

};
