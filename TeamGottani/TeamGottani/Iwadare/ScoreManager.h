#pragma once

namespace ScoreSpace
{
	const Vec2 SCORE_BACK_SIZE = { 300,100 };
	const Vec2 SCORE_POS = { 20,20 };
	const float MAX_SCORE = 99999999;
}

class ScoreManager
{
public:
	int _score;
	int _resultScore;
	ScoreManager();
	~ScoreManager() {};
	void AddScore(int32 score);
	void ResetScore();
	void GameDraw(Font fontSize);
	void ResultDraw(Font font);
};

