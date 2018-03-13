#ifndef WORLD_H
#define WORLD_H

#include "cell.hpp"
#include <vector>
#include <unordered_set>

class World
{
	public:
		World(){};
		World(int x, int y);
		void play();
		void random_init(int x,int  y);
		std::unordered_set<Cell> const &get_map() const{
			return map;
		}
	protected:
		std::unordered_set<Cell> map;
};

#endif
