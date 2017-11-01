#pragma once
#include "Grid.h"

class PathAStar
{
	Grid *grid;
public:
	std::vector<Node*> path;
	std::vector<Node*> open;
	std::vector<Node*> close;
	std::vector<Node*> route;

	void getRoute(Node *end, Node *finish);
	void readMyGrid();
	int getLowestFValue(std::vector<Node*> v);
	void findingPath(int, int, int, int);
	PathAStar();
	~PathAStar();
};

