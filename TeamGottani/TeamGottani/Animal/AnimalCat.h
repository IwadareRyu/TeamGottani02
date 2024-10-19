#pragma once
#include "AnimalBase.h"

class AnimalCat : public Animal
{
private:
	Vec3 velocity_;  // 動物の速度（重力を適用するために使用）

public:
	AnimalCat(const Vec3& position, const Image& image, const int score, const float size)
		: Animal(position, image, score, size), velocity_(0, 0, 0)  // 初期速度を0に設定
	{
	}

	void Start() override
	{
	}

	void Update() override
	{
		// 重力の適用（例：毎フレーム Y 軸方向に 0.98 増加）
		velocity_.y += 0.98;

		// 現在の位置に速度を加算（落下）
		position_.y += velocity_.y;

		// 箱の底に到達したら落下を停止（仮の箱の底の Y 座標を 500 として設定）
		if (position_.y >= 500.0f)
		{
			position_.y = 500.0f;  // 箱の底に固定
			velocity_.y = 0.0f;    // 落下を止める
		}
	}

	void Draw() const override
	{
		Circle{ position_.xy(), size_ }.draw();
	}
};
