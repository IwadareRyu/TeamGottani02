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

	void GameStart();
	void GameEnd();
	void GameRestart();
	void GamePause();
	void GameResume();

	void GameStop();
	void GameTitle();


private:
	std::unique_ptr<Player> _player;  // プレイヤー
	AnimalCollection _collection;     // 動物コレクション
	std::unique_ptr<Stage> _stage;    // ステージ
};
