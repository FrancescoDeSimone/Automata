#include "world.hpp"
#include <ctime>

void World::random_init(int x, int y)
{
	std::srand(std::time(nullptr));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(std::rand()%2)
				this->map.insert(std::make_pair(i,j));
}

World::World(int x, int y) : map(x*y)
{
	random_init(x,y);
}


void World::removeCell(int x, int y)
{
	to_add.clear();
	to_delete.clear();
	auto find_del = map.find(std::make_pair(x,y));
	if(find_del != map.end())
		map.erase(find_del);
	to_delete.push_back(std::make_pair(x,y));
}

void World::addCell(int x, int y)
{
	to_add.clear();
	to_delete.clear();
	map.insert(std::make_pair(x,y));
	to_add.insert(std::make_pair(x,y));
}
