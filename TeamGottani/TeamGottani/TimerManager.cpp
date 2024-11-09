#include "stdafx.h"
#include "TimerManager.h"

TimerManager::TimerManager() :
	_currentTime(TimerSpace::DEFAULT_TIME)
{

}

void TimerManager::ElapsedTime()
{
	_currentTime -= Scene::DeltaTime();
	if (_currentTime < 0)
	{
		_currentTime = 0;
	}
}

void TimerManager::ResetTime()
{
	_currentTime = TimerSpace::DEFAULT_TIME;
}

void TimerManager::Draw(Font font)
{
	Rect(
		Scene::Width() - TimerSpace::TIMER_BACK_SIZE.x,
		0,
		TimerSpace::TIMER_BACK_SIZE.x,
		TimerSpace::TIMER_BACK_SIZE.y
	).draw(Palette::Blue);

	font(U"Time: ", roundf(_currentTime))
		.draw(
			TimerSpace::TIMER_POS.x,
			TimerSpace::TIMER_POS.y,
			Palette::Black
		);
}
