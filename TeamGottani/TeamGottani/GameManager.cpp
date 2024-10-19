#include "stdafx.h"
#include "GameManager.h"

#include "Stage.h"
#include "Animal/AnimalCat.h"
#include "Animal/AnimalCollection.h"

// GameManagerのコンストラクタ
GameManager::GameManager()
	: _player(nullptr),  // プレイヤーをnullptrで初期化
	  _stage(nullptr)    // ステージをnullptrで初期化
{
}

// GameManagerのデストラクタ
GameManager::~GameManager()
{
}

void GameManager::Awake()
{
	// 初期化処理
	_collection.StartAnimals();
}

void GameManager::Start()
{
	// ステージの生成
	_stage = std::make_unique<Stage>();

	// プレイヤーの初期化、ステージを渡す
	_player = std::make_unique<Player>(_stage.get());

	// 動物を作成してコレクションに追加
	_collection.AddAnimal(std::make_unique<AnimalCat>(Vec3(100, 100, 0), Image(U"cat.png"), 10, 10.0f));
	_collection.AddAnimal(std::make_unique<AnimalCat>(Vec3(200, 100, 0), Image(U"cat.png"), 100, 15.0f));
	_collection.AddAnimal(std::make_unique<AnimalCat>(Vec3(300, 100, 0), Image(U"cat.png"), 1000, 20.0f));
	_collection.AddAnimal(std::make_unique<AnimalCat>(Vec3(400, 100, 0), Image(U"cat.png"), 10000, 25.0f));

	// ステージの初期化
	_stage->Initialize();
}

void GameManager::Update()
{
	// プレイヤーの更新
	_player->Update();

	// 毎フレームの動物の更新処理
	_collection.UpdateAnimals();

	// ステージの更新処理
	_stage->Update();
}

void GameManager::Draw()
{
	// 描画処理
	_collection.DrawAnimals();
	_player->Draw();

	// ステージの描画処理
	_stage->Draw();
}

void GameManager::GameStart()
{
}

void GameManager::GameEnd()
{
}

void GameManager::GameRestart()
{
}

void GameManager::GamePause()
{
}

void GameManager::GameResume()
{
}

void GameManager::GameStop()
{
}

void GameManager::GameTitle()
{
}
