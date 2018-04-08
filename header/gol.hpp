#ifndef GOL_H
#define GOL_H

#include "world.hpp"
#include "gol_cell.hpp"
#include <ctime>

class Gol : public World<Gol_cell>
{
    public:
	Gol(){}
	Gol(int x, int y) : map(x*y)
        {
            random_init(x,y);
        }
	void play() override;
	void random_init(int x,int  y) override {random_init(0,0,x,y);}
	void random_init(int width_screen, int height_screen, int x, int  y) override;
	void add_cell(int x, int y) override;
	void remove_cell(int x, int y) override;
	std::unordered_set<Gol_cell> const &get_map() const override{
		return map;
	}
	std::unordered_set<Gol_cell> const &get_new() const override{
		return to_add;
	}
	std::vector<Gol_cell> const &get_dead() const override{
		return to_delete;
	}
    private:
	std::unordered_set<Gol_cell> map;
	std::unordered_set<Gol_cell> to_add;
	std::vector<Gol_cell> to_delete;
};
#include "../source/gol.tpp"
#endif
