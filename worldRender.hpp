#ifndef WORLD_RENDER_H
#define WORLD_RENDER_H

#include <SFML/Graphics.hpp>
#include "world.hpp"
class WorldRender
{
	public:
		WorldRender(int, int);
		WorldRender(int,int,int,int);
		void run();
	private:
		void processEvents();
		void update();
		void render();
		World world;
		sf::RenderWindow window;
		int widthCell = 0;
		int heightCell = 0;
};

#endif
