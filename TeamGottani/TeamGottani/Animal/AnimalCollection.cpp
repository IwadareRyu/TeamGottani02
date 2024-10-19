#include "AnimalCollection.h"

// 動物をコレクションに追加
void AnimalCollection::AddAnimal(std::unique_ptr<Animal> animal)
{
	animals_.push_back(std::move(animal));
}

// コレクション内の動物を全て取得
const std::vector<std::unique_ptr<Animal>>& AnimalCollection::GetAnimals() const
{
	return animals_;
}

// コレクション内の動物を更新
void AnimalCollection::UpdateAnimals()
{
	for (auto& animal : animals_)
	{
		// 各動物に対して、更新処理を追加
		animal->Update();
	}
}

// コレクション内の動物を描画
void AnimalCollection::DrawAnimals() const
{
	for (const auto& animal : animals_)
	{
		animal->Draw();
	}
}
