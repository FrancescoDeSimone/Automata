#ifndef CELL_H
#define CELLH

#include <map>
#include <array>
#include <utility>
#include <tuple>
class cell{
	public:
		cell(std::pair<int,int>,bool status = true);
		bool i_will_survive();
		void set_status(bool status){this->status = status;}
		bool get_status(){return status;}
		bool set_neigbours(cell*);
		std::array<std::tuple<int,int,cell*>,8> get_neigbours(){return neigbours;}
		std::pair<int,int> get_position(){return position;}
	private:
		bool status;
		std::pair<int,int> position;
		std::array<std::tuple<int,int,cell*>,8> neigbours;
};

#endif
