#pragma once
#include "AnimalBase.h"

class AnimalCat : public Animal
{
public:
	AnimalCat(int score, float size, const Image& image)
		: Animal(score, size, image)
	{
	}

	void Start() override
	{
	}

	void Update() override
	{
	}

	void Draw() const override
	{
		Circle{Scene::Center(), size_}.draw();
	}
};
