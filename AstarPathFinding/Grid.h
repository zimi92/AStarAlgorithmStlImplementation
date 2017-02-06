#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Node.h"

class Grid
{
public:
	Grid(int _x, int _y);
	int x, y;
	std::vector<std::vector<Node>> grid;
	void manageGrid(int obstacles);
	void ReadGrid();
	int distance(Node start, Node end);
	Node getNode(int x, int y);
	std::vector<Node> neighbours(int x, int y);
	~Grid();
};

