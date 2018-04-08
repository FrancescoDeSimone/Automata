#ifndef LANGTON_ANT_HPP
#define LANGTON_ANT_HPP
#include "ant.hpp"
#include "world.hpp"
class Langton_ant : public World<Cell>
{
	public:
		void play() override;
		void random_init(int x,int  y) override {
			random_init(0,0,x,y);
		}

		void random_init(int width_screen, int height_screen, int x,int  y) override;
		
		void add_cell(int x, int y) override{
			ants.push_back(std::make_pair(x,y));
		}

		void remove_cell(int x, int y) override;
		std::unordered_set<Cell> const &get_map() const override{
			return map;
		}
		std::unordered_set<Cell> const &get_new() const override{
			return to_add;	
		}
		std::vector<Cell> const &get_dead() const override{
			return to_delete;
		}
	private:
		std::vector<Ant> ants;
		std::unordered_set<Cell> map;
		std::unordered_set<Cell> to_add;
		std::vector<Cell> to_delete;
};
#include "../source/langton_ant.tpp"
#endif
