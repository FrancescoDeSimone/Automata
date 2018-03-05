#ifndef WORLD_RENDER_H
#define WORLD_RENDER_H

#include <SFML/Graphics.hpp>
#include "world.hpp"
class WorldRender
{
	public:
		WorldRender(int w,int h);
		void run();
	private:
	World world;
	sf::RenderWindow window;
};

#endif
