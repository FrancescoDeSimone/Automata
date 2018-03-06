#include "worldRender.hpp"

WorldRender::WorldRender(int number_cell_width, int number_cell_height){
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	WorldRender(desktop.width,desktop.height,number_cell_width,number_cell_height);
}

WorldRender::WorldRender(int width, int height, int number_cell_width, int number_cell_height) : window(sf::VideoMode(width,height), "Game of Life"){
	this->world.random_init(number_cell_width,number_cell_height);
	this->widthCell = width / number_cell_width;
	this->heightCell = height / number_cell_height;
	window.setFramerateLimit(30);
}

void WorldRender::run(){
	while(window.isOpen()){
		processEvents();
		render();
		update();
	}
}

void WorldRender::processEvents(){
	sf::Event event;
	while(window.pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				window.close();
			break;
		}
	}
}

void WorldRender::update(){
	world.play();
}

void WorldRender::render(){
	window.clear();
	auto map = world.get_map();
	sf::VertexArray cellVertex(sf::Quads,4*map.size());
	int i=0;
	for(auto cell:map){
		auto x = cell.get_position().first * widthCell; 
		auto y = cell.get_position().second * heightCell; 
		cellVertex[i].color = sf::Color::Green;
		cellVertex[i++].position = sf::Vector2f(x,y);
		cellVertex[i].color = sf::Color::Green;
		cellVertex[i++].position = sf::Vector2f(x+widthCell,y);
		cellVertex[i].color = sf::Color::Green;
		cellVertex[i++].position = sf::Vector2f(x+widthCell,y+heightCell);
		cellVertex[i].color = sf::Color::Green;
		cellVertex[i++].position = sf::Vector2f(x,y+heightCell);
	}
	window.draw(cellVertex);
	window.display();
}

