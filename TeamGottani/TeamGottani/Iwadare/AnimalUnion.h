#pragma once
#include "UIManager.h"

class AnimalUnion
{
private:
	const Array<String> AnimalID = { U"🐘", U"🐧", U"🐐", U"🐤" };
	const Array<int> ScoreID = { 200,400,600,2000 };

public:
	AnimalUnion();
	~AnimalUnion(){}
	void ChackUnionTest(Array<P2Body>& bodies,
		HashTable<P2BodyID,size_t>& table,P2World* world, Array<MultiPolygon>& polygons,UIManager* score);

	bool ChackUnion(size_t target1, size_t target2);

	P2Body Union(size_t target1ID,P2Body target1Body,size_t target2ID, P2Body target2Body,P2World* world, Array<MultiPolygon>& polygons);

};

