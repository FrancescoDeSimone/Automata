#ifndef WORLD_RENDER_H
#define WORLD_RENDER_H

#include <SFML/Graphics.hpp>
#include "world.hpp"

template <class T>
class WorldRender
{
	public:
		WorldRender<T>(int number_cell_width,int number_cell_height)
		{
			sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
			WorldRender(desktop.width,desktop.height,number_cell_width,number_cell_height);
		}
		WorldRender<T>(int width,int height,int number_cell_width,int number_cell_height) : window(sf::VideoMode(width,height),"Game of life")
		{
			this->world.random_init(number_cell_width,number_cell_height);
			this->widthCell = width / (width/2);
			this->heightCell = height / (height/2);
			window.setFramerateLimit(30);
		}
		void run()
		{
			while(window.isOpen()){
				processEvents();
				render();
				update();
			}
		}

	private:
		void processEvents();

		void update()
		{
			world.play();
		}

		void render();
		T world;
		sf::RenderWindow window;
		int widthCell = 0;
		int heightCell = 0;
};

#include "worldRender.tpp"
#endif
