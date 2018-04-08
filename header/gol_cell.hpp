#ifndef GOL_CELL_HPP
#define GOL_CELL_HPP

#include "cell.hpp"
class Gol_cell : public Cell
{
    public:
        Gol_cell(std::pair<int,int> position) :Cell(position), neighbours {
			std::make_pair(position.first-1,position.second),
			std::make_pair(position.first-1,position.second-1),
			std::make_pair(position.first,position.second-1),
			std::make_pair(position.first+1,position.second-1),
			std::make_pair(position.first+1,position.second),
			std::make_pair(position.first+1,position.second+1),
			std::make_pair(position.first,position.second+1),
			std::make_pair(position.first-1,position.second+1)
		}{}

        std::array<std::pair<int,int>,8> const &get_neighbours() const
        {
            return neighbours;
        }

    private:
        std::array<std::pair<int,int>,8> neighbours;
};

namespace std
{
    template<> struct hash<Gol_cell>
    {
        std::size_t operator()(Gol_cell const& cell) const noexcept
        {
		return std::hash<long long>()(((long long)cell.get_position().first)^(((long long)cell.get_position().second)<<32));
        }
    };
}

#endif
