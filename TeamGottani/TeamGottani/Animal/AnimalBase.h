#pragma once

// Animal ベースクラス
class Animal
{
protected:
	Vec3 position_;
	Image image_;
	int score_;
	float size_;

public:
	virtual ~Animal() = default;

	// スコア、サイズ、画像を設定
	Animal(const Vec3& position, const Image& image, const int score, const float size)
		: position_(position), image_(image), score_(score), size_(size)
	{
	}

	// 位置を取得する関数
	Vec3 GetPosition() const;

	// 位置を設定する関数
	void SetPosition(const Vec3& position);

	// 画像を取得
	Image GetImage() const;

	// スコアを取得
	int GetScore() const;

	// サイズを取得
	float GetSize() const;


	// 接触判定（仮の実装）
	virtual bool CheckCollision(const Animal& other) const;

	// 仮想関数
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};
