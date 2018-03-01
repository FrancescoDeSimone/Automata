#include "cell.hpp"

cell::cell(std::pair<int,int> position, bool status)
{
	this->position = position;
	std::array<std::tuple<int,int,cell*>,8> neigbours_array {
		std::make_tuple(position.first-1,position.second,nullptr),
		std::make_tuple(position.first-1,position.second-1,nullptr),
		std::make_tuple(position.first,position.second-1,nullptr),
		std::make_tuple(position.first+1,position.second-1,nullptr),
		std::make_tuple(position.first+1,position.second,nullptr),
		std::make_tuple(position.first+1,position.second+1,nullptr),
		std::make_tuple(position.first,position.second+1,nullptr),
		std::make_tuple(position.first-1,position.second+1,nullptr)
		};
	this->neigbours = neigbours_array;
	this->status = status;
}

bool cell::i_will_survive()
{
	int cont = 0;
	for(auto cellTuple : neigbours){
		auto cell = std::get<2>(cellTuple);
		if(nullptr != cell)
			cont++;
	}
	if(cont == 2)
		return this->get_status();
	if(cont == 3)
		return true;
	return false;
}

bool cell::set_neigbours(cell* new_cell)
{
	for(auto& cell_tuple:neigbours){
		auto first = std::get<0>(cell_tuple);
		auto second = std::get<1>(cell_tuple);
		auto& cell = std::get<2>(cell_tuple);
		if(first == new_cell->get_position().first && second == new_cell->get_position().second){
			std::get<2>(cell_tuple) = new_cell;
			return true;
		}
	}
	return false;
}
