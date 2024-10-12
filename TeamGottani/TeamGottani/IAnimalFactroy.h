#pragma once

// IAnimalFactoryインターフェース
class IAnimalFactory {
public:
	virtual ~IAnimalFactory() = default;
	virtual std::unique_ptr<Animal> createAnimal() const = 0;
};
