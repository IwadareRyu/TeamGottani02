#include "stdafx.h"
#include "SceneController.h"

SceneController::SceneController() : m_sceneState(SceneState::TitleScene), rect({ 0,0,1920,1080 }), m_currentTime(0.f)
{
};

SceneController::~SceneController()
{

}

void SceneController::FadeIn(float time)
{
	m_currentTime += Scene::DeltaTime();
	rect.draw(ColorF(0, 0, 0, m_currentTime / time));
	if (m_currentTime > time)
	{
		m_sceneState = m_tmpNextScene;
		m_isFadeIn = true;
		m_currentTime = 0.f;
	}
}

void SceneController::FadeOut(float time)
{
	m_currentTime += Scene::DeltaTime();
	rect.draw(ColorF(0, 0, 0, time - m_currentTime / time));

	if (m_currentTime > time)
	{
		m_isFade = false;
		m_isFadeIn = false;
		m_currentTime = 0.f;
	}
	return;
}

void SceneController::ChangeScene(SceneState sceneState, bool isFade)
{
	if (m_isFade) return;

	if (!isFade)
	{
		m_sceneState = sceneState;
	}
	else
	{
		m_tmpNextScene = sceneState;

		m_isFade = isFade;
	}
};

void SceneController::FadeUpdate()
{
	if (m_isFade)
	{
		if (!m_isFadeIn)
		{
			FadeIn(m_fadeTime);
		}
		else
		{
			FadeOut(m_fadeTime);
		}
	}
}



