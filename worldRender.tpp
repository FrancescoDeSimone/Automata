
template<class T>
void WorldRender<T>::processEvents()
{
	sf::Event event;
	while(window.pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				window.close();
			break;
		}
	}
}

template<class T>
void WorldRender<T>::render()
{
	sf::VertexArray cellVertex(sf::Quads,4*(world.get_new().size()+world.get_dead().size()));
	int i=0;
	for(const Cell cell:world.get_new()){
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

	for(const Cell cell:world.get_dead()){
		auto x = cell.get_position().first * widthCell; 
		auto y = cell.get_position().second * heightCell; 
		cellVertex[i].color = sf::Color::Black;
		cellVertex[i++].position = sf::Vector2f(x,y);
		cellVertex[i].color = sf::Color::Black;
		cellVertex[i++].position = sf::Vector2f(x+widthCell,y);
		cellVertex[i].color = sf::Color::Black;
		cellVertex[i++].position = sf::Vector2f(x+widthCell,y+heightCell);
		cellVertex[i].color = sf::Color::Black;
		cellVertex[i++].position = sf::Vector2f(x,y+heightCell);
	}

	window.draw(cellVertex);
	window.display();
}

