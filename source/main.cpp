#include "../header/worldRender.hpp"
#include "../header/gol.hpp"
#include "../header/langton_ant.hpp"
int main(int argc, char* argv[])
{
	if(argc == 5){
		WorldRender<Gol> wr(std::atoi(argv[1]),std::atoi(argv[2]),std::atoi(argv[3]),std::atoi(argv[4]));
		wr.run();
	}else if(argc == 3){
		WorldRender<Langton_ant> wr(std::atoi(argv[1]),std::atoi(argv[2]));
		wr.run();
	}else{
		WorldRender<Langton_ant> wr;
		wr.run();
	}
	return 0;
}
