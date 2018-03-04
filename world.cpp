#include "world.hpp"
#include <ctime>
World::World(int x, int y)
{
	std::srand(std::time(nullptr));
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(std::rand()%2)
				this->map.insert(Cell(std::make_pair(i,j)));
}

void World::play()
{
	std::vector<Cell> to_delete;
	std::unordered_set<Cell> to_add; 
	
	int cont=0;
	for(auto cell:this->map){
		for(auto neigbour_position:cell.get_neigbours()){
			auto find_neigbour = this->map.find(neigbour_position);
			if(find_neigbour != this->map.end()){
				cont++;
			}else{
				to_add.insert(Cell(neigbour_position));
			}
		}
		if(cont != 2 && cont != 3)
			to_delete.push_back(cell);
		cont = 0;
	}

	cont = 0;
	for(auto cell_to_remove:to_add){
		for(auto neigbour_position:cell_to_remove.get_neigbours()){
			auto find_neigbour = this->map.find(neigbour_position);
			if(find_neigbour != this->map.end())
				cont++;
		}
		if(cont != 3){
			to_delete.push_back(cell_to_remove);
		}
		cont = 0;
	}

	for(auto cell_to_add:to_add){
		this->map.insert(cell_to_add);
	}

	for(auto pos_to_delete:to_delete){
		auto find_delete = this->map.find(pos_to_delete);
		if(find_delete != this->map.end())
			this->map.erase(find_delete);
	}
	
}
