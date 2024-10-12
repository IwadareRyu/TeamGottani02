#pragma once
#include "IAnimalFactroy.h"
#include "Player.h"
#include "Singleton.h"

class GameManager :public Singleton<GameManager>
{
public:
	void Awake();
	void Start();
	void Update();
	void Draw();
	private:
	GameManager();
	~GameManager();
	std::unique_ptr<IAnimalFactory> _factory;
	std::unique_ptr<Player> _player;

};
