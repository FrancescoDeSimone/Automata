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
		virtual void play() = 0;
		void random_init(int x,int  y);
		std::unordered_set<Cell> const &get_map() const{
			return map;
		}
		std::unordered_set<Cell> const &get_new() const{
			return to_add;
		}
		std::vector<Cell> const &get_dead() const{
			return to_delete;
		}
	protected:
		std::unordered_set<Cell> map;
		std::unordered_set<Cell> to_add;
		std::vector<Cell> to_delete;
};

#endif
