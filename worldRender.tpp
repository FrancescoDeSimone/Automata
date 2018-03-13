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
					break;
					case sf::Keyboard::Up:
						view.move(0,-10);
					break;
					case sf::Keyboard::Left:
						view.move(-10,0);
					break;
					case sf::Keyboard::Right:
						view.move(10,0);
					break;
					case -1:
						view.zoom(0.5f);
					break;
					case 56:
						view.zoom(1.5f);
					break;
				}
			break;
		}
	}
}

template<class T>
void WorldRender<T>::render()
{
	sf::VertexArray cellVertex(sf::Quads,4*world.get_map().size());
	int i=0;
	window.clear();
	for(const Cell cell:world.get_map()){
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
	window.setView(view);
	window.draw(cellVertex);
	window.setView(textView);
	text.setString("FPS:\t"+std::to_string(fps)+"\n#Cell:\t"+std::to_string(world.get_map().size()));
	window.draw(text);
	window.display();
}

