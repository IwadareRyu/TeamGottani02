#pragma once
#include <memory>
#include "Player.h"
#include "Animal/AnimalCollection.h"

class Stage
{
private:
	AnimalCollection animalContainer_;  // 動物を格納するコンテナ
	RectF dropZone_;                    // プレイヤーが動物を落とせる場所
	Line borderLine_;                   // ボーダーライン（動物が落ちる判定のためのライン）
	std::unique_ptr<Animal> nextAnimal_; // 次の動物
	Player player_;                     // プレイヤー

public:
	Stage();

	// ステージの初期化
	void Initialize();

	// ステージの更新
	void Update();

	// ステージの描画
	void Draw() const;

	// 動物を落とす処理
	void DropAnimal();

	// 動物がボーダーラインを超えたか確認
	bool IsAnimalBeyondBorder(const Animal& animal) const;

	// 次の動物を生成
	void GenerateNextAnimal();
};
