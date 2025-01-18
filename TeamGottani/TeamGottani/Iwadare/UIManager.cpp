#include "../stdafx.h"
#include "UIManager.h"

UIManager::UIManager() :
	m_gamefont(UISpace::GAME_UI_FONT_SIZE),
	m_resultFont(UISpace::RESULT_UI_FONT_SIZE),
	m_ButtanFont(UISpace::BUTTON_UI_FONT_SIZE),
	m_titleStartButton(
		Rect{
			Scene::Width() / 2 -
			(int)UISpace::DAFAULT_BUTTON_SIZE.x / 2,
			Scene::Height() / 4 * 3,
			(int)UISpace::DAFAULT_BUTTON_SIZE.x,
			(int)UISpace::DAFAULT_BUTTON_SIZE.y
		},
		Palette::Aqua,
		U"Start"
	),
	m_returnTitleButton(
				Rect{
			Scene::Width() / 2 -
			(int)UISpace::DAFAULT_BUTTON_SIZE.x / 2,
			Scene::Height() / 4 * 3,
			(int)UISpace::DAFAULT_BUTTON_SIZE.x,
			(int)UISpace::DAFAULT_BUTTON_SIZE.y
		},
		Palette::Aqua,
		U"ReturnTitle"
	)
{
}

/// @brief タイトルシーンのUpdate
void UIManager::UITitleUpdate()
{
	UITitleDraw();
}

/// @brief ゲームシーンのUpdate
void UIManager::UIGameUpdate()
{
	if (KeySpace.pressed())
	{
		AddScoreRef(1000000);
	}
	if (KeyShift.pressed())
	{
		AddScoreRef(-1000000);
	}
	m_timerManager.ElapsedTime();
	m_scoreManager.GameDraw(m_gamefont);
	m_timerManager.Draw(m_gamefont);
}

/// @brief ゲームシーンからリザルトシーンに移行するときに呼んでください。
void UIManager::UIResultInit()
{
	m_scoreManager._resultScore = m_scoreManager._score;
}

/// @brief リザルトシーンのUpdate
void UIManager::UIResultUpdate()
{
	m_scoreManager.ResultDraw(m_resultFont);
	m_returnTitleButton .Draw(m_ButtanFont);
}

/// @brief 制限時間の確認
/// @return 制限時間を超えたらtrueを返す。
bool UIManager::ChackTime()
{
	if (m_timerManager.m_currentTime <= 0) return true;
	else return false;
}

/// @brief Score追加の際呼ぶメソッド
/// @param score 加算するスコアの値
void UIManager::AddScoreRef(float score)
{
	m_scoreManager.AddScore(score);
}

void UIManager::ResetUI()
{
	m_scoreManager.ResetScore();
	m_timerManager.ResetTime();
}

void UIManager::UITitleDraw()
{
	m_resultFont(U"墾田永年私財法").drawAt(Scene::Center(), Palette::Black);
	m_titleStartButton.Draw(m_ButtanFont);
}

float UIManager::CurrentTime()
{
	return m_timerManager.m_currentTime;
}

int32 UIManager::Score()
{
	return m_scoreManager._score;
}


