#include <iostream>
template<class T>
void WorldRender<T>::addPoints(auto const &map, sf::Color color)
{
	for(const Cell cell:map){
		auto x = cell.get_position().first * widthCell; 
		auto y = cell.get_position().second * heightCell; 
		cellVertex.append(sf::Vertex(sf::Vector2f(x,y),color));
		cellVertex.append(sf::Vertex(sf::Vector2f(x+widthCell,y),color));
		cellVertex.append(sf::Vertex(sf::Vector2f(x+widthCell,y+heightCell),color));
		cellVertex.append(sf::Vertex(sf::Vector2f(x,y+heightCell),color));
	}
}

template<class T>
void WorldRender<T>::processEvents()
{
	sf::Event event;
	while(window.pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				window.close();
			break;
			case sf::Event::KeyPressed:
				switch(event.key.code){
					case sf::Keyboard::Down:
						view.move(0,10);
						reprint=true;
					break;
					case sf::Keyboard::Up:
						view.move(0,-10);
						reprint=true;
					break;
					case sf::Keyboard::Left:
						view.move(-10,0);
						reprint=true;
					break;
					case sf::Keyboard::Right:
						view.move(10,0);
						reprint=true;
					break;
					case -1:
						view.zoom(0.5f);
						reprint=true;
					break;
					case 56:
						view.zoom(1.5f);
						reprint=true;
					break;
				}
			break;
			case sf::Event::Resized:
				reprint=true;
			break;
		}
	}
}

template<class T>
void WorldRender<T>::render()
{
	//forse meglio unsare un unordered_set
	cellVertex.clear();

	if(reprint){
		window.clear();
		addPoints(world.get_map(),sf::Color::Green);
		reprint = false;
	}else{
		addPoints(world.get_new(),sf::Color::Green);
		addPoints(world.get_dead(),sf::Color::Black);
	}
	window.setView(view);
	window.draw(cellVertex);
	window.setView(textView);
	sf::RectangleShape rectangle(sf::Vector2f(200, 60));
	rectangle.setFillColor(sf::Color::Black);
	window.draw(rectangle);
	text.setString("FPS:\t"+std::to_string(fps)+"\n#Cell:\t"+std::to_string(world.get_map().size()));
	window.draw(text);
	window.display();
}

