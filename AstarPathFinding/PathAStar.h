#pragma once
#include "Grid.h"

class PathAStar
{
	Grid *grid;
public:
	std::vector<Node*> path;
	std::vector<Node*> open;
	std::vector<Node*> close;
	std::vector<Node*> Route;

	void getRoute(Node *end, Node *finish);
	void ReadMyGrid();
	int getLowestFValue(std::vector<Node*> v);
	void FindingPath(Node *start, Node *finish);
	PathAStar();
	~PathAStar();
};

