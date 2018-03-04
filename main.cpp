#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define X 1920
#define Y 1080
#define Nx (1920/2)
#define Ny (1080/2)

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(X, Y), "Game Of Life");
    World w(Nx,Ny);
    sf::RectangleShape rectangle(sf::Vector2f(X/Nx, Y/Ny));
    rectangle.setFillColor(sf::Color::Green);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
	for(const auto cell: w.get_map()){
		rectangle.setPosition(cell.get_position().first*(X/Nx),cell.get_position().second*(Y/Ny));
		window.draw(rectangle);
	}
	w.play();
        window.display();
    }

    return 0;
}
