#pragma once
#include "Grid.h"

class PathAStar
{
	Grid *grid;
public:
	std::vector<Node*> path;
	std::vector<Node*> open;
	std::vector<Node*> close;

	void ReadMyGrid();
	int getLowestFValue(std::vector<Node*> v);
	void FindingPath(Node *start, Node *finish);
	PathAStar();
	~PathAStar();
};

