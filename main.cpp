#include <iostream>
#include "world.hpp"
#include <SFML/Graphics.hpp>
#define X 1366
#define Y 768
#define Nx 1366/2
#define Ny 768/2



int main()
{
    sf::RenderWindow window(sf::VideoMode(X, Y), "Game Of Life");
    world w(Nx,Ny);
    sf::RectangleShape rectangle(sf::Vector2f(X/Nx, Y/Ny));
    rectangle.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
	std::cout<<w.get_map().size()<<"\n";
	for(const auto cell_pair: w.get_map()){
		auto cell = cell_pair.second;
		rectangle.setPosition(cell.get_position().first*(X/Nx),cell.get_position().second*(Y/Ny));
		window.draw(rectangle);
	}
	w.play();
        window.display();
    }

    return 0;
}
