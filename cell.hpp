#ifndef CELL_H
#define CELLH

#include <map>
#include <array>
#include <utility>
#include <tuple>
class cell{
	public:
		cell(std::pair<int,int>,bool status = true);
		bool iWillSurvive();
		void setStatus(bool status){this->status = status;}
		bool getStatus(){return status;}
		bool setNeigbours(std::tuple<int,int,cell*>);
		std::array<std::tuple<int,int,cell*>,8> getNeigbours(){return neigbours;}
		std::pair<int,int> getPosition(){return position;}
	private:
		bool status;
		std::pair<int,int> position;
		std::array<std::tuple<int,int,cell*>,8> neigbours;
};

#endif
