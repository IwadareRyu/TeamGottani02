#include "stdafx.h"
#include "UIManager.h"

UIManager::UIManager() :
	_gamefont(UISpace::GAME_UI_FONT_SIZE),
	_resultFont(UISpace::RESULT_UI_FONT_SIZE)
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
		AddScoreRef(30);
	}
	_timerManager.ElapsedTime();
	_scoreManager.GameDraw(_gamefont);
	_timerManager.Draw(_gamefont);
}

/// @brief ゲームシーンからリザルトシーンに移行するときに呼んでください。
void UIManager::UIResultInit()
{
	_scoreManager._resultScore = _scoreManager._score;
}

/// @brief リザルトシーンのUpdate
void UIManager::UIResultUpdate()
{
	_scoreManager.ResultDraw(_resultFont);
}


void UIManager::AddScoreRef(float score)
{
	_scoreManager.AddScore(score);
}

void UIManager::ResetUI()
{
	_scoreManager.ResetScore();
	_timerManager.ResetTime();
}

void UIManager::UITitleDraw()
{
	_resultFont(U"タイトル").drawAt(Scene::Center(), Palette::Black);
}

float UIManager::CurrentTime()
{
	return _timerManager._currentTime;
}

int32 UIManager::Score()
{
	return _scoreManager._score;
}
