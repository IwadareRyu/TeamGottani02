#include "Stage.h"
#include "GameManager.h"
#include "Animal/AnimalCat.h"
#include "Player.h"  // Playerクラスをインクルード

Stage::Stage()
	: drop_zone_(RectF(300, 500, 200, 50)),  // 仮の位置とサイズ
	  border_line_(Line(0, 600, 800, 600))
{
	// Player を make_unique を使って生成し、Stage のポインタを渡す
	player_ = std::make_unique<Player>(this);
}

void Stage::Initialize()
{
	GenerateNextAnimal();
	player_->SetAnimal(std::move(next_animal_));
}

void Stage::Update()
{
	player_->Update();  // プレイヤーの更新

	// 他の動物の更新処理
	animal_container_.UpdateAnimals();

	// ボーダーラインを超えた動物をチェック
	for (const auto& animal : animal_container_.GetAnimals())
	{
		if (IsAnimalBeyondBorder(*animal))
		{
			GameManager::GetInstance()->GameEnd();
		}
	}
}

void Stage::Draw() const
{
	drop_zone_.draw(ColorF(0.2, 0.8, 0.2, 0.5));
	border_line_.draw(ColorF(0.8, 0.1, 0.1));

	animal_container_.DrawAnimals();

	if (next_animal_)
	{
		next_animal_->Draw();
	}

	player_->Draw();
}

void Stage::AddAnimalToStage(std::unique_ptr<Animal> animal)
{
	animal_container_.AddAnimal(std::move(animal));
	GenerateNextAnimal();  // 次の動物を生成
	player_->SetAnimal(std::move(next_animal_));
}

bool Stage::IsAnimalBeyondBorder(const Animal& animal) const
{
	// 動物がボーダーラインより下に落ちたかを判定
	return animal.GetSize() + animal.GetPosition().y > border_line_.begin.y;
}

void Stage::GenerateNextAnimal()
{
	// サンプルとして猫を生成
	Vec3 position = { drop_zone_.x + drop_zone_.w / 2, drop_zone_.y - 50, 0 };  // 箱の上に配置
	Image image = Image(U"cat.png");
	int score = 10;
	float size = 20.0f;

	next_animal_ = std::make_unique<AnimalCat>(position, image, score, size);
}
