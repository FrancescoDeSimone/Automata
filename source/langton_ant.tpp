void Langton_ant::random_init(int width_screen, int heigth_screen, int x, int y){
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(rand()%8==0)
				add_cell(i,j);
}


void Langton_ant::remove_cell(int x, int y)
{
	to_add.clear();
	to_delete.clear();
	auto find_del = map.find(std::make_pair(x,y));
	if(find_del != map.end())
		map.erase(find_del);
	to_delete.push_back(Cell(std::make_pair(x,y),std::make_tuple(0,0,0)));
}

void Langton_ant::play(){
	to_add.clear();
	to_delete.clear();
	for(auto& ant:ants){
		auto find_path = map.find(ant.get_position());
		if( find_path == map.end() ){
			Cell c(ant.get_position(),ant.get_color());
			map.insert(c);
			to_add.insert(c);
		}else{
			map.erase(find_path);
			Cell c(ant.get_position(),std::make_tuple(0,0,0));
			to_delete.push_back(c);
		}
		std::pair<int,int> position;
		int x = ant.get_position().first;
		int y = ant.get_position().second;
		switch(ant.get_direction()){
			case UP:
				position = std::make_pair(x,y+1);
			break;
			case DOWN:	
				position = std::make_pair(x,y-1);
			break;
			case LEFT:	
				position = std::make_pair(x-1,y);
			break;
			case RIGHT:	
				position = std::make_pair(x+1,y);
			break;
		}
		find_path = map.find(position);
		if(find_path != map.end())
			ant.turn_left();
		else
			ant.turn_right();

		ant.move(position);
	}
}


