#include <iostream>
#include "cell.hpp"

int main()
{
	cell c(std::make_pair(0,0));
	cell c1(std::make_pair(5,1));
	c.setNeigbours(std::make_tuple(1,1,&c1));

	std::cout<<"Posizione "<<c.getPosition().first<<"\t"<<c.getPosition().second<<"\nStato "<<c.getStatus()<<std::endl;
	for(auto cellTuple:c.getNeigbours()){
		auto cell = std::get<2>(cellTuple);
		if(nullptr != cell)
			std::cout<<cell->getPosition().first<<std::endl;
	}
	return 0;
}
