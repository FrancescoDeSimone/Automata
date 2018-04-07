#ifndef ANT_HPP
#define ANT_HPP

#include "cell.hpp"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Ant : public Cell
{
	public:
		Ant(std::pair<int,int> position) : Cell(position,std::make_tuple(rand()%256,rand()%256,rand()%256)){};
		void move(int x, int y){position = std::make_pair(x,y);};
		void move(std::pair<int,int> pos) { move(pos.first,pos.second);};
		void turn_left();
		void turn_right();
		Direction const &get_direction() const{return direction;}
	private:
		Direction direction = UP;
};

#endif
