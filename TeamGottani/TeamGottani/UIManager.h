#pragma once
#include "ScoreManager.h"
#include "TimerManager.h"

namespace UISpace
{
	const float GAME_UI_FONT_SIZE = 30;
	const float RESULT_UI_FONT_SIZE = 100;
}

class UIManager
{
private:
	ScoreManager _scoreManager;
	TimerManager _timerManager;
	Font _gamefont;
	Font _resultFont;
	void UITitleDraw();
public:
	UIManager();
	~UIManager() {};
	void UITitleUpdate();
	void UIGameUpdate();
	void UIResultInit();
	void UIResultUpdate();
	void AddScoreRef(float score);
	void ResetUI();
	float CurrentTime();
	int32 Score();
};

