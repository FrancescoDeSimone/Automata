#include "cell.hpp"

cell::cell(std::pair<int,int> position, bool status)
{
	this->position = position;
	std::array<std::tuple<int,int,cell*>,8> neigboursArray {
		std::make_tuple(position.first-1,position.second,nullptr),
		std::make_tuple(position.first-1,position.second-1,nullptr),
		std::make_tuple(position.first,position.second-1,nullptr),
		std::make_tuple(position.first+1,position.second-1,nullptr),
		std::make_tuple(position.first+1,position.second,nullptr),
		std::make_tuple(position.first+1,position.second+1,nullptr),
		std::make_tuple(position.first,position.second+1,nullptr),
		std::make_tuple(position.first-1,position.second+1,nullptr)
		};
	this->neigbours = neigboursArray;
	this->status = status;
}

bool cell::iWillSurvive()
{
	int cont = 0;
	for(auto cellTuple : neigbours){
		auto cell = std::get<2>(cellTuple);
		if(nullptr != cell)
			cont++;
	}
	if(cont == 2)
		return this->getStatus();
	if(cont == 3)
		return true;
	return false;
}

bool cell::setNeigbours(std::tuple<int,int,cell*> newCellTuple)
{
	for(auto& cellTuple:neigbours){
		auto& cell = std::get<2>(cellTuple);
		if(cell == nullptr){
			cellTuple = newCellTuple;
			return true;
		}
	}

	return false;
}
