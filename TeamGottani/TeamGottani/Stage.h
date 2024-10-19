#pragma once
#include <memory>
#include "Player.h"
#include "Animal/AnimalCollection.h"

class Stage
{
private:
	AnimalCollection animal_container_;  // 動物を格納するコンテナ
	RectF drop_zone_;                    // プレイヤーが動物を落とせる場所
	Line border_line_;                   // ボーダーライン
	std::unique_ptr<Animal> next_animal_; // 次の動物
	Player player_;                     // プレイヤー

public:
	Stage();

	void Initialize();
	void Update();
	void Draw() const;

	// プレイヤーが動物をステージに追加するための関数
	void AddAnimalToStage(std::unique_ptr<Animal> animal);

	bool IsAnimalBeyondBorder(const Animal& animal) const;
	void GenerateNextAnimal();
};
