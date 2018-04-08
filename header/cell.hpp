#ifndef CELL_H
#define CELL_H

#include <map>
#include <array>
#include <utility>
class Cell{
	public:
		Cell(std::pair<int,int> position, std::tuple<int,int,int> color = std::make_tuple(0,255,0)){
			this->color = color;
			this->position = position;
		}
		std::pair<int,int> const &get_position() const {return position;}
		bool operator<(const Cell& cell) const{ 
			return position.first < cell.get_position().first && position.second < cell.get_position().second;
		}
		bool operator==(const Cell& cell) const{ 
			return position.first == cell.get_position().first && position.second == cell.get_position().second;
		}
		bool operator>(const Cell& cell) const{
			return !(*this<cell);
		}
		std::tuple<int,int,int> const &get_color() const{
			return color;
		}
		void set_color(std::tuple<int,int,int> color){
			this->color = color;
		}
	protected:
		std::pair<int,int> position;
		std::tuple<int,int,int> color;
};

namespace std
{
    template<> struct hash<Cell>
    {
        std::size_t operator()(Cell const& cell) const noexcept
        {
			return std::hash<long long>()(((long long)cell.get_position().first)^(((long long)cell.get_position().second)<<32));
        }
    };
}

#endif
