#ifndef WORLD_H
#define WORLD_H

#include "cell.hpp"
#include <vector>
#include <unordered_set>

template<typename T>
class World
{
	static_assert(std::is_base_of<Cell, T>::value, "T must inherit from Cell");
	public:
		virtual void play() = 0;
		virtual void random_init(int x,int  y) = 0;
		virtual void random_init(int width_screen, int height_screen, int x,int  y) = 0;
		virtual void add_cell(int x, int y) = 0;
		virtual void remove_cell(int x, int y) = 0;
		//ty iron-man
		virtual std::unordered_set<T> const &get_map() const = 0;
		virtual std::unordered_set<T> const &get_new() const = 0;
		virtual std::vector<T> const &get_dead() const = 0;
};

#endif
