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
	// 必要なクリーンアップ処理があればここに書く
}

void GameManager::Awake()
{
	// 初期化処理
}

void GameManager::Start()
{
	// ゲーム開始処理
	_player = std::make_unique<Player>();
	// 動物を作成してコレクションに追加
	_collection.AddAnimal(std::make_unique<AnimalCat>());
}

void GameManager::Update()
{
	// 毎フレームの更新処理
}

void GameManager::Draw()
{
	// 描画処理
}
