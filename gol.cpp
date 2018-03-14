#include "gol.hpp"

bool find_neigbour(std::pair<int,int> const &neigbour_position, std::unordered_set<Cell> const &map)
{
	auto find_neigbour = map.find(neigbour_position);
	if(find_neigbour != map.end())
		return true;
	return false;
}

void Gol::play()
{
	std::unordered_set<Cell> to_add;
	std::vector<Cell> to_delete;
	for(const auto cell:map){
		int cont = 0;
		for(auto neigbour_position:cell.get_neigbours()){
			if(find_neigbour(neigbour_position,map)){
				cont++;
			}else{
				Cell add_cell(neigbour_position);
				if(to_add.find(add_cell) == to_add.end()){
					int count_new = 0;
					for(auto neigbour_position:add_cell.get_neigbours()){
						if(find_neigbour(neigbour_position,map))
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

	for(const auto cell_to_add:to_add){
		map.insert(cell_to_add);
	}

	for(const auto pos_to_delete:to_delete){
		auto find_delete = map.find(pos_to_delete);
		if(find_delete != map.end())
			map.erase(find_delete);
	}
}
