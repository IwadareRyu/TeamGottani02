#pragma once

namespace Physics {
	constexpr double stepTime = (1.0 / 200);
	constexpr double gravity = 980;
}
class Animal;

class PhysicsManager
{
private:
	P2World world{ Physics::gravity };

public:
	void HandleCollisions();

	void CreateBall(Animal* animal);
	void Draw();

	Array<P2Body> bodys;
	P2Body ground = world.createLine(P2Static, Vec2{ 0, 0 }, Line{ -300, 0, 300, 0 });
	std::vector<Animal*> balls;
	double accumulatedTime = 0.0;

};
