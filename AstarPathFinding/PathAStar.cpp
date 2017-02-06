#include "PathAStar.h"



PathAStar::PathAStar()
{
	grid = new Grid(10, 10);
	grid->manageGrid(10);
}

void PathAStar::FindingPath(Node start, Node finish) {
	start.hValue = grid->distance(start, finish);
	start.gValue = 0;
	open.push_back(start);
	Node current(0,0,0,0,0);
	while (!open.empty()) {
		std::cout << current.x << " " << current.y << "\n";
		int currentPosition = getLowestFValue(open);
		if (current == finish)
		{
			std::cout << "SUCCESS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			return;
		}
		current = open[currentPosition];
		open.erase(open.begin() + currentPosition);
		if (std::find(close.begin(), close.end(), current) != close.end())
			continue;
		close.push_back(current);
		std::vector <Node> neighbours = grid->neighbours(current.x, current.y);
		for (int i = 0; i < neighbours.size(); i++) {
			if (std::find(open.begin(), open.end(), neighbours[i]) == open.end())
				open.push_back(neighbours[i]);
		}
		current.status = 1;
	}
}

int PathAStar::getLowestFValue(std::vector<Node> v) {
	int first = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i].fValue() < v[first].fValue())
			first = i;
	return first;
}

PathAStar::~PathAStar()
{
}
