#include "world.hpp"

world::world(int x, int y)
{
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(std::rand()%2)
				this->map.emplace(std::make_pair(i,j),cell(std::make_pair(i,j)));
}

struct hash{
  size_t operator()(const cell& x)const{
    return std::hash<long long>()(((long long)x.get_position().first)^(((long long)x.get_position().second)<<32));
  }
};

void world::play()
{
	std::vector<std::pair<int,int>> to_delete;
	std::unordered_set<cell,hash> to_add; 
	
	int cont=0;
	for(auto cell_pair:this->map){
		for(auto neigbour_position:cell_pair.second.get_neigbours()){
			auto find_neigbour = this->map.find(neigbour_position);
			if(find_neigbour != this->map.end()){
				cont++;
			}else{
				to_add.insert(cell(neigbour_position));
			}
		}
		if(cont != 2 && cont != 3)
			to_delete.push_back(cell_pair.first);
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
			to_delete.push_back(cell_to_remove.get_position());
		}
		cont = 0;
	}

	for(auto cell_to_add:to_add){
		this->map.emplace(cell_to_add.get_position(),cell_to_add);
	}

	for(auto pos_to_delete:to_delete){
		auto find_delete = this->map.find(pos_to_delete);
		if(find_delete != this->map.end())
			this->map.erase(find_delete);
	}
	
}
