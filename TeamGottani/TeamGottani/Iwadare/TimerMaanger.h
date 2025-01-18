#pragma once
namespace TimerSpace
{
	const float DEFAULT_TIME = 100.f;
	const Vec2 TIMER_BACK_SIZE = { 200,100 };
	const Vec2 TIMER_SIZE = { 150,20 };
}

class TimerMaanger
{
public:
	float m_currentTime;
	TimerMaanger();
	~TimerMaanger() {};
	void ElapsedTime();
	void ResetTime();
	void Draw(Font font);
};

