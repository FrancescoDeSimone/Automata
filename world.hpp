#ifndef WORLD_H
#define WORLD_H

#include <unordered_map>
#include "cell.hpp"
#include <vector>
#include <unordered_set>

class World
{
	public:
		World(int x, int y);
		void play();
		std::unordered_set<Cell> get_map() const{
			return map;
		}
	private:
		std::unordered_set<Cell> map;
};

#endif
