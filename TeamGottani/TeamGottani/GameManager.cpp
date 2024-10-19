#include "stdafx.h"
#include "GameManager.h"

#include "Animal/AnimalCat.h"
#include "Animal/AnimalCollection.h"
// GameManagerのコンストラクタ
GameManager::GameManager()
	: _factory(nullptr), _player(nullptr) // 初期化リストでメンバ変数を初期化
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
	// ゲーム開始処理
	_player = std::make_unique<Player>();
	// 動物を作成してコレクションに追加
	_collection.AddAnimal(std::make_unique<AnimalCat>(10, 10, Image(U"cat.png")));
	_collection.AddAnimal(std::make_unique<AnimalCat>(100, 15, Image(U"cat.png")));
	_collection.AddAnimal(std::make_unique<AnimalCat>(1000, 20, Image(U"cat.png")));
	_collection.AddAnimal(std::make_unique<AnimalCat>(10000, 25, Image(U"cat.png")));
}

void GameManager::Update()
{
	// 毎フレームの更新処理
	_collection.UpdateAnimals();
}

void GameManager::Draw()
{
	// 描画処理
	_collection.DrawAnimals();
}
