#include "stdafx.h"
#include "ScoreManager.h"

ScoreManager::ScoreManager() : _score(0)
{

}

void ScoreManager::AddScore(int32 score)
{
	_score += score;
}

void ScoreManager::ResetScore()
{
	_score = 0;
}

void ScoreManager::GameDraw(Font font)
{
	Rect{
		0,
		0,
		(int)ScoreSpace::SCORE_BACK_SIZE.x,
		(int)ScoreSpace::SCORE_BACK_SIZE.y
	}.draw(Palette::Blue);
	font(U"Score: ", _score).draw(
		ScoreSpace::SCORE_POS.x,
		ScoreSpace::SCORE_POS.y,
		Palette::Black
	);
}

void ScoreManager::ResultDraw(Font font)
{
	font(U"RESULT")
		.drawAt(
			Scene::Center().x,
			Scene::Center().y - 150,
			Palette::Red
		).center();
	font(_resultScore)
		.drawAt(
			Scene::Center(),
			Palette::Blue
		).center();
}
