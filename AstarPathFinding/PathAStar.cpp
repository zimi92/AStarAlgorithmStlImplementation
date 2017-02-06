#include "PathAStar.h"



PathAStar::PathAStar()
{
	grid = new Grid(10, 10);
	grid->manageGrid(10);
}

void PathAStar::FindingPath(Node *start, Node *finish) {
	start->hValue = grid->distance(start, finish);
	start->gValue = 0;
	open.push_back(start);
	Node *current = new Node(0,0,0,0,0);
	while (!open.empty()) {
		std::cout << current->x << " " << current->y << " current\n";
		int currentPosition = getLowestFValue(open);
		if (current->x == finish->x && current->y == finish->y)
		{
			current->status = 5;
			std::cout << "SUCCESS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			ReadMyGrid();
			return;
		}
		current = open[currentPosition];
		open.erase(open.begin() + currentPosition);
		if (std::find(close.begin(), close.end(), current) != close.end())
			continue;
		close.push_back(current);
		std::vector <Node*> neighbours = grid->neighbours(current->x, current->y);
		for (int i = 0; i < neighbours.size(); i++) {
			if (std::find(open.begin(), open.end(), neighbours[i]) == open.end()) {
				neighbours[i]->hValue = grid->distance(neighbours[i], finish);
				if (current->x == neighbours[i]->x || current->y == neighbours[i]->y)
					neighbours[i]->gValue = current->gValue + 10;
				else
					neighbours[i]->gValue = current->gValue + 14;
				open.push_back(neighbours[i]);
			}
			else {
				int gValue = 0;
				if (current->x == neighbours[i]->x || current->y == neighbours[i]->y)
					gValue = current->gValue + 10;
				else
					gValue = current->gValue + 14;
				if (neighbours[i]->gValue > gValue || neighbours[i]->gValue == 0)
					neighbours[i]->gValue = gValue;
			}
		}
		//grid->grid[current.x][9 - current.y].status = 2;
		current->status = 2;
	}
}

int PathAStar::getLowestFValue(std::vector<Node*> v) {
	int first = 0;
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i]->fValue() << "fValue\n";
		if (v[i]->fValue() < v[first]->fValue())
			first = i;
	}
	return first;
}

void PathAStar::ReadMyGrid() {
	for (int i = 0; i < grid->grid.size(); i++) {
		for (int j = 0; j < grid->grid[0].size(); j++) {
			std::cout << grid->grid[i][j].status;
		}
		std::cout << std::endl;
	}
}

PathAStar::~PathAStar()
{
}
