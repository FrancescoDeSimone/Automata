#include "worldRender.hpp"

int main(int argc, char* argv[])
{
	if(argc != 5)
		exit(1);
	WorldRender wr(std::atoi(argv[1]),std::atoi(argv[2]),std::atoi(argv[3]),std::atoi(argv[4]));
	wr.run();
	return 0;
}
