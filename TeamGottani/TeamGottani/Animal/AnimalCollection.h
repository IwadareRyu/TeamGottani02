#pragma once
#include <vector>
#include <memory>
#include "AnimalBase.h"

// AnimalCollectionクラス
class AnimalCollection
{
private:
	std::vector<std::unique_ptr<Animal>> animals_;

public:
	AnimalCollection() = default;
	~AnimalCollection() = default;

	// 動物をコレクションに追加
	void AddAnimal(std::unique_ptr<Animal> animal);

	// コレクション内の動物を全て取得
	const std::vector<std::unique_ptr<Animal>>& GetAnimals() const;


	void StartAnimals();

	// コレクション内の動物を更新
	void UpdateAnimals();

	// コレクション内の動物を描画
	void DrawAnimals() const;
};
