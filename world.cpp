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
