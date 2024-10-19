#include "stdafx.h"
#include "Player.h"

#include "Stage.h"

void Player::Start()
{
	pos_ = Scene::Center();  // プレイヤーの初期位置を中央に設定
}

void Player::Update()
{
	const double delta = (Scene::DeltaTime() * 200);

	// 上下左右キーで移動
	if (KeyLeft.pressed())
	{
		pos_.x -= delta;
	}

	if (KeyRight.pressed())
	{
		pos_.x += delta;
	}

	if (KeyUp.pressed())
	{
		pos_.y -= delta;
	}

	if (KeyDown.pressed())
	{
		pos_.y += delta;
	}

	// [C] キーが押されたら中央に戻る
	if (KeyC.down())
	{
		pos_ = Scene::Center();
	}

	// [スペース] キーが押されたら動物をドロップする
	if (KeySpace.down())
	{
		DropAnimal();  // 動物を落とす処理
	}

	// プレイヤーの描画
	Circle{ pos_, 50 }.draw();
}

void Player::Draw() const
{
	if (current_animal_)
	{
		// 動物を描画
		current_animal_->Draw();
	}
}

void Player::DropAnimal()
{
	if (current_animal_)
	{
		// ステージに動物を追加して、プレイヤーの動物をクリアする
		stage_->AddAnimalToStage(std::move(current_animal_));
	}
}
