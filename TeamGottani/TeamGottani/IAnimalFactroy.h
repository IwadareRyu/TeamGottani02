#pragma once
#include "AnimalBase.h"

// IAnimalFactoryインターフェース
class IAnimalFactory {
public:
	virtual ~IAnimalFactory() = default;
	virtual std::unique_ptr<Animal> CreateAnimal() const = 0;
};
