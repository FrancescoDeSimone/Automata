#include <iostream>
#include "cell.hpp"

int main()
{
	cell c(std::make_pair(0,0));
	cell c1(std::make_pair(1,2));
	c.set_neigbours(&c1);

	std::cout<<"Posizione "<<c.get_position().first<<"\t"<<c.get_position().second<<"\nStato "<<c.get_status()<<std::endl;
	for(auto cellTuple:c.get_neigbours()){
		auto cell = std::get<2>(cellTuple);
		if(nullptr != cell)
			std::cout<<cell->get_position().first<<std::endl;
	}
	return 0;
}
