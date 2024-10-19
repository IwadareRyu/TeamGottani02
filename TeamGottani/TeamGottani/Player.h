#pragma once

class Player
{
public:
	void Start();
	void Update();
	void Draw() const;

private:
	Image image_;
	Vec2 pos_;
};
