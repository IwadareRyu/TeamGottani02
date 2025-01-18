#pragma once
#include "ScoreManager.h"
#include "TimerMaanger.h"
#include "Button.h"

namespace UISpace
{
	const float GAME_UI_FONT_SIZE = 30;
	const float RESULT_UI_FONT_SIZE = 100;
	const float BUTTON_UI_FONT_SIZE = 60;
	const Vec2 DAFAULT_BUTTON_SIZE = { 500.f,100.f };
}

class UIManager
{
private:
	ScoreManager m_scoreManager;
	TimerMaanger m_timerManager;
	Font m_gamefont;
	Font m_resultFont;
	Font m_ButtanFont;
	void UITitleDraw();
public:
	UIManager();
	~UIManager() {};
	Button m_titleStartButton;
	Button m_returnTitleButton;
	void UITitleUpdate();
	void UIGameUpdate();
	void UIResultInit();
	void UIResultUpdate();
	bool ChackTime();
	void AddScoreRef(float score);
	void ResetUI();
	float CurrentTime();
	int32 Score();
};

