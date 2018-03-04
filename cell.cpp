#include "cell.hpp"

Cell::Cell(std::pair<int,int> position, bool status)
{
	this->position = position;
	std::array<std::pair<int,int>,8> neigbours_array {
		std::make_pair(position.first-1,position.second),
		std::make_pair(position.first-1,position.second-1),
		std::make_pair(position.first,position.second-1),
		std::make_pair(position.first+1,position.second-1),
		std::make_pair(position.first+1,position.second),
		std::make_pair(position.first+1,position.second+1),
		std::make_pair(position.first,position.second+1),
		std::make_pair(position.first-1,position.second+1)
		};
	this->neigbours = neigbours_array;
}

