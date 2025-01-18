#include "../stdafx.h"
#include "AnimalUnion.h"

AnimalUnion::AnimalUnion()
{

}

void AnimalUnion::ChackUnionTest(Array<P2Body>& bodies,
		HashTable<P2BodyID, size_t>& table, P2World* world, Array<MultiPolygon>& polygons, UIManager* score)
{
	if (bodies.size() < 2) return;
	for (auto it_i = bodies.begin(); it_i != bodies.end() - 1;)
	{
		for (auto it_j = it_i + 1; it_j != bodies.end();)
		{
			auto i_table = table.find(it_i->id());
			auto j_table = table.find(it_j->id());
			if (i_table != table.end() && j_table != table.end())
			{
				/// 当たり判定の際に使う場所(return以外)
				bool isUnion = ChackUnion(i_table->second, j_table->second);
				if (isUnion)
				{
					score->AddScoreRef(ScoreID[i_table->second]);
					auto unionObject = Union(i_table->second, *it_i, j_table->second, *it_j, world, polygons);
					//it_iとit_jのオブジェクトの削除
					table.erase(j_table->first);
					it_j = bodies.erase(it_j);
					table.erase(i_table->first);
					it_i = bodies.erase(it_i);
					if (unionObject.getBodyType() == P2BodyType::Dynamic)
					{
						bodies << unionObject;
						table.emplace(
							bodies.back().id(),
							i_table->second + 1);
					}
					return;
				}
				else
				{
					it_j++;
				}
				///
			}
			else
			{
				it_j++;
			}
		}
		it_i++;
	}
}

bool AnimalUnion::ChackUnion(size_t target1, size_t target2)
{
	if (target1 == target2)
	{
		return true;
	}
	return false;
}

P2Body AnimalUnion::Union(
	size_t target1ID, P2Body target1Body,
	size_t target2ID, P2Body target2Body,
	P2World* world, Array<MultiPolygon>& polygons)
{

	size_t index = target1ID + 1;
	if (index >= polygons.size())
	{
		auto body = world->createPolygons(P2Kinematic,target1Body.getPos(), polygons[index - 1], P2Material{0.1, 0.0, 1.0});
		return body;
	}
	else
	{
		return world->createPolygons(P2Dynamic, target1Body.getPos(), polygons[index], P2Material{0.1, 0.0, 1.0});
	}
}
