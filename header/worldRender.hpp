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
		WorldRender<T>() : WorldRender(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height){}
		WorldRender<T>(int width, int height) : window(sf::VideoMode(width,height),"Automata")
		{
			view.reset(sf::FloatRect(0,0, width, height));
			textView.reset(sf::FloatRect(0,0, width, height));
			if (!font.loadFromFile("font/amyn.ttf"))
				exit(1);
			text.setFont(font);
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::Red);
			text.setStyle(sf::Text::Bold);
			window.setFramerateLimit(25);
			window.setView(view);
			cellVertex.setPrimitiveType(sf::Quads);
		}
		WorldRender<T>(int width,int height,int number_cell_width,int number_cell_height) : WorldRender(width,height) 
		{

			this->world.random_init(width,height,number_cell_width,number_cell_height);
			cellVertex.resize(world.get_map().size());
		}
		void run()
		{
			while(window.isOpen()){
				processEvents();
				render();
				if(!pause)
					update();
				fps = getFPS(clock.restart());
			}
		}

	private:
		sf::VertexArray cellVertex;
		void processEvents();
		void update(){ world.play(); }
		void render();
		void addPoints(auto const &); 
		T world;
		sf::RenderWindow window;
		sf::View view;
		sf::View textView;
		int widthCell = 1;
		int heightCell = 1;
		float fps = 0;
		sf::Font font;
		sf::Text text;
		sf::Clock clock;
		bool reprint = true;
		bool pause = true;
};

#include "../source/worldRender.tpp"
#endif
