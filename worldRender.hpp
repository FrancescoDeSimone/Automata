#ifndef WORLD_RENDER_H
#define WORLD_RENDER_H

#include <SFML/Graphics.hpp>
#include "world.hpp"

float getFPS(const sf::Time& time) {
     return (1000000.0f / time.asMicroseconds());
}

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
			view.reset(sf::FloatRect(-((width/2)-(number_cell_width/2)),-((height/2)-(number_cell_height/2)), width, height));
			textView.reset(sf::FloatRect(0,0, width, height));
			this->world.random_init(number_cell_width,number_cell_height);
			this->widthCell = 1;
			this->heightCell = 1;
			if (!font.loadFromFile("font/amyn.ttf"))
				exit(1);

			text.setFont(font);
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::Red);
			text.setStyle(sf::Text::Bold);
			window.setFramerateLimit(20);
			window.setView(view);
		}
		void run()
		{
			while(window.isOpen()){
				processEvents();
				render();
				update();
				fps = getFPS(clock.restart());
			}
		}

	private:
		void processEvents();
		void update(){ world.play(); }
		void render();
		T world;
		sf::RenderWindow window;
		sf::View view;
		sf::View textView;
		int widthCell = 0;
		int heightCell = 0;
		float fps = 0;
		sf::Font font;
		sf::Text text;
		sf::Clock clock;
};

#include "worldRender.tpp"
#endif
