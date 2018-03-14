#ifndef CELL_H
#define CELLH

#include <map>
#include <array>
#include <utility>


class Cell{
	public:
		Cell(std::pair<int,int>);
		std::pair<int,int> get_position() const {return position;}
		std::array<std::pair<int, int>, 8> get_neigbours() const {
			return neigbours;
		}
		bool operator<(const Cell& cell) const{ 
			return position.first < cell.get_position().first && position.second < cell.get_position().second;
		}
		bool operator==(const Cell& cell) const{ 
			return position.first == cell.get_position().first && position.second == cell.get_position().second;
		}
		bool operator>(const Cell& cell) const{
			return !(*this<cell);
		}
	private:
		std::pair<int,int> position;
		std::array<std::pair<int,int>,8> neigbours;
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
