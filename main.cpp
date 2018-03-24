#include "worldRender.hpp"
#include "gol.hpp"
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
	return 0;
}
