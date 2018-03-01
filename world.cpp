#include "world.hpp"

world::world(int x, int y)
{
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(std::rand()%2)
				this->map.emplace(std::make_pair(i,j),cell(i,j));
}

void world::play()
{

}
