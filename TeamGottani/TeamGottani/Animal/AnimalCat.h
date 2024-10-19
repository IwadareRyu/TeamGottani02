#pragma once
#include "AnimalBase.h"

class AnimalCat : public Animal
{
public:
	AnimalCat(int score, float size, const Image& image)
		: Animal(score, size, image)
	{
	}
};
