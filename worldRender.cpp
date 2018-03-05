#include "worldRender.hpp"

WorldRender::WorldRender(int w, int h){
	this->world.random_init(w,h);
	window.create(sf::VideoMode(w, h), "Game of life");
	window.setFramerateLimit(30);
}

void WorldRender::run()
{
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		auto map = world.get_map();
		window.clear(sf::Color::Black);
		sf::VertexArray cellVertex(sf::Quads,4*map.size());
		int i=0;
		for(auto cell:map){
			auto x = cell.get_position().first; 
			auto y = cell.get_position().second; 
			cellVertex[i++].position = sf::Vector2f(x,y);
			cellVertex[i++].position = sf::Vector2f(x+1,y);
			cellVertex[i++].position = sf::Vector2f(x+1,y+1);
			cellVertex[i++].position = sf::Vector2f(x,y+1);
		}
		world.play();
		window.draw(cellVertex);
		window.display();
	}
}

