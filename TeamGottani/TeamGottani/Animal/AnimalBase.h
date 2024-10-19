#pragma once

// Animal ベースクラス
class Animal
{
protected:
	int score_;
	float size_;
	Image image_;

public:
	virtual ~Animal() = default;

	// スコア、サイズ、画像を設定
	Animal(const int score, const float size, const Image& image)
		: score_(score), size_(size), image_(image)
	{
	}

	// スコアを取得
	int GetScore() const;

	// サイズを取得
	float GetSize() const;

	// 画像を取得
	Image GetImage() const;

	// 接触判定（仮の実装）
	virtual bool CheckCollision(const Animal& other) const;

	// 仮想関数
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};
