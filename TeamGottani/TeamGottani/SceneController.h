﻿#pragma once

enum class SceneState
{
	TitleScene,
	GameScene,
	ResultScene,
};
class SceneController
{
private:
	SceneState m_sceneState;
	SceneState m_tmpNextScene;
	bool m_isFade = false;
	bool m_isFadeIn = false;
	float m_fadeTime = 1.0f;
	float m_currentTime;
	Rect rect;
	void FadeIn(float time);
	void FadeOut(float time);
public:
	SceneController();
	~SceneController();
	/// @brief 現在のシーン参照 
	constexpr SceneState M_Scene() { return m_sceneState; }
	void ChangeScene(SceneState sceneState, bool isFade = true);
	void FadeUpdate();
};

