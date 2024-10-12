# include <Siv3D.hpp> // Siv3D v0.6.15

#include "GameManager.h"

void Main()
{

	GameManager::GetInstance()->Start();
	while (System::Update())
	{
		GameManager::GetInstance()->Update();
		GameManager::GetInstance()->Draw();
	}

}
