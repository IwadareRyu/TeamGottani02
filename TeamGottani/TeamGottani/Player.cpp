#include "stdafx.h"
#include "Player.h"

void Player::Start()
{
	pos_ = Scene::Center();
}

void Player::Update()
{
	const double delta = (Scene::DeltaTime() * 200);

	// 上下左右キーで移動
	if (KeyLeft.pressed() && KeyA.down())
	{
		pos_.x -= delta;
	}

	if (KeyRight.pressed() && KeyD.down())
	{
		pos_.x += delta;
	}

	if (KeyUp.pressed() && KeyW.down())
	{
		pos_.y -= delta;
	}

	if (KeyDown.pressed() && KeyS.down())
	{
		pos_.y += delta;
	}

	// [C] キーが押されたら中央に戻る
	if (KeyC.down())
	{
		pos_ = Scene::Center();
	}

	Circle{pos_, 50}.draw();
}

void Player::Draw() const
{
}
