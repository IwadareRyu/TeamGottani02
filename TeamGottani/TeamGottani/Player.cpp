#include "stdafx.h"
#include "Player.h"

void Player::update()
{
	Vec2 pos = Scene::Center();

	while (System::Update())
	{
		const double delta = (Scene::DeltaTime() * 200);

		// 上下左右キーで移動
		if (KeyLeft.pressed() && KeyA.down())
		{
			pos.x -= delta;
		}

		if (KeyRight.pressed() && KeyD.down())
		{
			pos.x += delta;
		}

		if (KeyUp.pressed() && KeyW.down())
		{
			pos.y -= delta;
		}

		if (KeyDown.pressed() && KeyS.down())
		{
			pos.y += delta;
		}

		// [C] キーが押されたら中央に戻る
		if (KeyC.down())
		{
			pos = Scene::Center();
		}

		Circle{pos, 50}.draw();
	}
}
