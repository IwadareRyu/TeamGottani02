#include "../stdafx.h"
#include "TimerMaanger.h"

TimerMaanger::TimerMaanger() :
	m_currentTime(TimerSpace::DEFAULT_TIME)
{

}

void TimerMaanger::ElapsedTime()
{
	m_currentTime -= Scene::DeltaTime();
	if (m_currentTime < 0)
	{
		m_currentTime = 0;
	}
}

void TimerMaanger::ResetTime()
{
	m_currentTime = TimerSpace::DEFAULT_TIME;
}

void TimerMaanger::Draw(Font font)
{
	Rect(
		Scene::Width() - TimerSpace::TIMER_BACK_SIZE.x,
		0,
		TimerSpace::TIMER_BACK_SIZE.x,
		TimerSpace::TIMER_BACK_SIZE.y
	).draw(Palette::Blue);

	font(U"Time: ", roundf(m_currentTime))
		.draw(
			Scene::Width() - TimerSpace::TIMER_SIZE.x,
			TimerSpace::TIMER_SIZE.y,
			Palette::Black
		);
}
