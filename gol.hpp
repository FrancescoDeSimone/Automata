#ifndef GOL_H
#define GOL_H

#include "world.hpp"
#include "gol_cell.hpp"
#include <ctime>

class Gol : public World<Gol_cell>
{
    public:
	Gol(){}
	Gol(int x, int y) : map(x*y)
        {
            random_init(x,y);
        }
	void play() override;
	void random_init(int x,int  y) override {random_init(0,0,x,y);}
	void random_init(int width_screen, int height_screen, int x, int  y) override;
	void add_cell(int x, int y) override;
	void remove_cell(int x, int y) override;
	std::unordered_set<Gol_cell> const &get_map() const override{
		return map;
	}
	std::unordered_set<Gol_cell> const &get_new() const override{
		return to_add;
	}
	std::vector<Gol_cell> const &get_dead() const override{
		return to_delete;
	}
    private:
	std::unordered_set<Gol_cell> map;
	std::unordered_set<Gol_cell> to_add;
	std::vector<Gol_cell> to_delete;
};

void Gol::random_init(int width_screen, int height_screen, int x, int y){
    srand(std::time(nullptr));
    int offset_X = (width_screen/2)-(x/2);
    int offset_Y = (height_screen/2)-(y/2);
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            if(rand()%2)
                this->map.emplace(std::make_pair(offset_X+i,offset_Y+j));
}   

void Gol::remove_cell(int x, int y)
{
	to_add.clear();
	to_delete.clear();
	auto find_del = map.find(std::make_pair(x,y));
	if(find_del != map.end())
		map.erase(find_del);
	to_delete.push_back(std::make_pair(x,y));
}

void Gol::add_cell(int x, int y)
{
	to_add.clear();
	to_delete.clear();
	map.insert(std::make_pair(x,y));
	to_add.insert(std::make_pair(x,y));
}


bool find_neigbour(std::pair<int,int> const &neigbour_position, std::unordered_set<Gol_cell> const &map)
{
	auto find_neigbour = map.find(neigbour_position);
	if(find_neigbour != map.end())
		return true;
	return false;
}

void Gol::play()
{
	to_add.clear();
	to_delete.clear();
	#pragma omp parallel
	#pragma omp for
	for(const auto cell:map){
		int cont = 0;
		#pragma omp parallel
		#pragma omp for
		for(auto neigbour_position:cell.get_neighbours()){
			if(find_neigbour(neigbour_position,map)){
				cont++;
			}else{
				Gol_cell add_cell(neigbour_position);
				if(to_add.find(add_cell) == to_add.end()){
					int count_new = 0;
					for(auto neigbour_position:add_cell.get_neighbours()){
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

	#pragma omp parallel 
	#pragma omp for
	for(const auto cell_to_add:to_add){
		map.insert(cell_to_add);
	}

	#pragma omp parallel 
	#pragma omp for
	for(const auto pos_to_delete:to_delete){
		auto find_delete = map.find(pos_to_delete);
		if(find_delete != map.end())
			map.erase(find_delete);
	}
}


#endif
