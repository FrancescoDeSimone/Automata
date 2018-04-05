#include "ant.hpp"

void Ant::turn_left()
{
	switch(direction){
		case UP:
			direction = LEFT;
		break;
		case DOWN:
			direction = RIGHT;
		break;
		case LEFT:
			direction = DOWN;
		break;
		case RIGHT:
			direction = UP;
		break;
	}
}

void Ant::turn_right()
{
	switch(direction){
		case UP:
			direction = RIGHT;
		break;
		case DOWN:
			direction = LEFT;
		break;
		case LEFT:
			direction = UP;
		break;
		case RIGHT:
			direction = DOWN;
		break;
	}
}
