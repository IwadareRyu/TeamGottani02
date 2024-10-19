#pragma once
#include "Player.h"
#include "Singleton.h"
#include "Animal/AnimalCollection.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager();

	void Awake();
	void Start();
	void Update();
	void Draw();



private:
	std::unique_ptr<Player> _player;
	AnimalCollection _collection;
};
