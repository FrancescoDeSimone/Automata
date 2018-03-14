#ifndef LANGTON_ANT_HPP
#define LANGTON_ANT_HPP

enum Direction{LEFT,RIGHT};

class Langton_ant : public World
{
	public:
		void play();
	private:
		Direction direction = direction.LEFT;
};

#endif
