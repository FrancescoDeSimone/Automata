#ifndef WORLD_H
#define WORLD_H

#include <map>
#include "cell.hpp"

struct hash_function{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

class world
{
	public:
	world(int x, int y);
	void play();
	std::unordered_map<std::pair<int,int>,cell,hash_function> get_map(){return map;}
	private:
	std::unordered_map<std::pair<int,int>,cell,hash_function> map;
};

#endif