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
	
	for(auto cell:this->map){
		int cont = 0;
		for(auto neigbour_position:cell.get_neigbours()){
			auto find_neigbour = this->map.find(neigbour_position);
			if(find_neigbour != this->map.end()){
				cont++;
			}else{
				Cell add_cell(neigbour_position);
				if(to_add.find(add_cell) == to_add.end()){
					int count_new = 0;
					for(auto neigbour_position:add_cell.get_neigbours()){
						auto find_neigbour = this->map.find(neigbour_position);
						if(find_neigbour != this->map.end())
							count_new++;
					}
					if(count_new == 3)
						to_add.insert(add_cell);
				}
			}
		}
		if(cont != 2 && cont != 3)
			to_delete.push_back(cell);
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
