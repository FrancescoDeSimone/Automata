#include "worldRender.hpp"
#include "gol.hpp"
int main(int argc, char* argv[])
{
	if(argc != 5)
		exit(1);
	WorldRender<Gol> wr(std::atoi(argv[1]),std::atoi(argv[2]),std::atoi(argv[3]),std::atoi(argv[4]));
	wr.run();
	return 0;
}
