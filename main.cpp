#include "worldRender.hpp"
#include "gol.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
	if(argc == 5){
		WorldRender<Gol> wr(std::atoi(argv[1]),std::atoi(argv[2]),std::atoi(argv[3]),std::atoi(argv[4]));
		wr.run();
	}else if(argc == 3){
		WorldRender<Gol> wr(std::atoi(argv[1]),std::atoi(argv[2]));
		wr.run();
	}else{
		WorldRender<Gol> wr;
		wr.run();
	}
	
	/*
	Gol g;
	std::cout<<g.get_map().size()<<std::endl;
	g.add_cell(10,10);
	std::cout<<g.get_map().size()<<std::endl;
	g.add_cell(11,10);
	std::cout<<g.get_map().size()<<std::endl;
	g.add_cell(12,10);
	std::cout<<g.get_map().size()<<std::endl;
	*/
	return 0;
}
