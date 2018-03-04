#ifndef CELL_H
#define CELLH

#include <map>
#include <array>
#include <utility>

class cell{
	public:
		cell(std::pair<int,int>,bool status = true);
		std::pair<int,int> get_position() const {return position;}
		std::array<std::pair<int, int>, 8> get_neigbours() const {return neigbours;};
		bool operator<(const cell& cell) const{ return position.first < cell.get_position().first && position.second < cell.get_position().second;}
		bool operator==(const cell& cell) const{ return position.first == cell.get_position().first && position.second == cell.get_position().second;}
	private:
		std::pair<int,int> position;
		std::array<std::pair<int,int>,8> neigbours;
};

#endif
