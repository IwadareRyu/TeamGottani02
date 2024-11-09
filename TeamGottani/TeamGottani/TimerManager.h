#pragma once
namespace TimerSpace
{
	const float DEFAULT_TIME = 300.f;
	const Vec2 TIMER_BACK_SIZE = { 200,100 };
	const Vec2 TIMER_POS = { 630,20 };
}

class TimerManager
{
public:
	float _currentTime;
	TimerManager();
	~TimerManager() {};
	void ElapsedTime();
	void ResetTime();
	void Draw(Font font);
};

