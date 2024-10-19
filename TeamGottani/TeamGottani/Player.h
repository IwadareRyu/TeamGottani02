#pragma once

// Stageクラスの前方宣言
class Stage;

#include "Animal/AnimalBase.h"

class Player
{
private:
	Image image_;
	Vec2 pos_ = {};

	std::unique_ptr<Animal> current_animal_;
	Stage* stage_ = nullptr;  // Stageへのポインタ

public:
	// Stageポインタを受け取るコンストラクタ
	Player(Stage* stage) : stage_(stage), pos_(Scene::Center()) {}

	void Start();
	void Update();
	void Draw() const;

	// 動物をドロップする処理
	void DropAnimal();

	// 現在の動物をセット
	void SetAnimal(std::unique_ptr<Animal> animal)
	{
		current_animal_ = std::move(animal);
	}
};
