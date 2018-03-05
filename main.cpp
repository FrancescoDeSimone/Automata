#include "worldRender.hpp"
#define X 1366
#define Y 768
#define Nx (X/2)
#define Ny (Y/2)

int main(int argc, char* argv[])
{
	WorldRender wr(Nx,Y);
	wr.run();
	return 0;
}
