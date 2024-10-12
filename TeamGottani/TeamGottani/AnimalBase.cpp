#include "stdafx.h"
#include "AnimalBase.h"

int Animal::getScore() const
{
	return score_;
}

float Animal::getSize() const
{
	return size_;
}

Image Animal::getImage() const
{
	return image_;
}

bool Animal::checkCollision(const Animal& other) const
{
	// 簡単な距離ベースの接触判定（例）
	return std::abs(size_ - other.getSize()) < 5.0;
}
