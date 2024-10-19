#include "Stage.h"

#include "GameManager.h"
#include "Animal/AnimalCat.h"

Stage::Stage()
	: dropZone_(RectF(300, 500, 200, 50)) // 仮の位置とサイズ
	  , borderLine_(Line(0, 600, 800, 600)), player_()
// ボーダーラインの定義
{
}

void Stage::Initialize()
{
	// 初期化処理
	GenerateNextAnimal(); // 次の動物を生成
}

void Stage::Update()
{
	player_.Update(); // プレイヤーの更新

	// 動物の更新
	animalContainer_.UpdateAnimals();

	// 動物をドロップできる場所の判定
	// if (/* プレイヤーが動物を落とすアクション */)
	// {
	// 	DropAnimal();
	// }

	// ボーダーラインを超えた動物をチェック
	for (const auto& animal : animalContainer_.GetAnimals())
	{
		if (IsAnimalBeyondBorder(*animal))
		{
			// ボーダーラインを超えた動物がいた場合の処理
			GameManager::GetInstance()->GameEnd();
		}
	}
}

void Stage::Draw() const
{
	// ステージの要素を描画
	dropZone_.draw(ColorF(0.2, 0.8, 0.2, 0.5)); // 動物を落とせる場所
	borderLine_.draw(ColorF(0.8, 0.1, 0.1)); // ボーダーライン

	// 動物の描画
	animalContainer_.DrawAnimals();

	// 次の動物の描画
	if (nextAnimal_)
	{
		nextAnimal_->Draw();
	}

	// プレイヤーの描画
	player_.Draw();
}

void Stage::DropAnimal()
{
	// 次の動物をコンテナに追加
	if (nextAnimal_)
	{
		animalContainer_.AddAnimal(std::move(nextAnimal_));
		GenerateNextAnimal(); // 次の動物を生成
	}
}

bool Stage::IsAnimalBeyondBorder(const Animal& animal) const
{
	// 動物がボーダーラインより下に落ちたかを判定
	return animal.GetSize() + animal.GetPosition().y > borderLine_.begin.y;
}

void Stage::GenerateNextAnimal()
{
	// サンプルとして猫を生成
	nextAnimal_ = std::make_unique<AnimalCat>(10, 10, Image(U"cat.png"));
}
