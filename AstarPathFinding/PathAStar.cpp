#include "PathAStar.h"



PathAStar::PathAStar()
{
	grid = new Grid(10, 10);
	grid->manageGrid(10);

	std::cout << "map:\n";
	ReadMyGrid();
}

void PathAStar::FindingPath(Node *start, Node *finish) {
	start->hValue = grid->distance(start, finish);
	start->gValue = 0;
	grid->setNode(start->x, start->y, 2);
	open.push_back(start);
	Node *current = new Node(0, 0, 0, 0, 0);
	while (!open.empty()) {		
		int currentPosition = getLowestFValue(open);
		if (current->x == finish->x && current->y == finish->y)
		{
			current->status = 5;
			std::cout << "A way has been found\n";
			ReadMyGrid();
			getRoute(finish, start);
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
		current->status = 2;
	}
}

void PathAStar::getRoute(Node *end, Node *beggining) {
	Node *temp = new Node(0, 0, 0, 0, 0);;
	temp = end;
	beggining->status = 2;
	
	while (temp->x != beggining->x || temp->y != beggining->y) {
		Route.push_back(temp);
		std::vector <Node*> neighbours = grid->neighbours(temp->x, temp->y);
		temp->status = 5;
		for (int i = 0; i < neighbours.size(); i++) {
			if (neighbours[i]->status != 2)
				continue;
			int fScore = neighbours[i]->fValue();
			int gScore = neighbours[i]->gValue;
			temp = neighbours[i];
			if (neighbours[i]->fValue() < fScore) {
				temp = neighbours[i];
				fScore = neighbours[i]->fValue();
				gScore = neighbours[i]->gValue;
			}
			else if (neighbours[i]->fValue() == fScore) {
				if (neighbours[i]->gValue < gScore) {
					temp = neighbours[i];
					fScore = neighbours[i]->fValue();
					gScore = neighbours[i]->gValue;
				}
			}
		}
	}
	Route.push_back(temp);
	std::cout << "final route:\n";
	for (int i = 0; i < Route.size(); i++) {
		std::cout << Route[i]->x << " " << Route[i]->y << "\n";
	}
}

int PathAStar::getLowestFValue(std::vector<Node*> v) {
	int first = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->fValue() < v[first]->fValue())
			first = i;
		else if(v[i]->fValue() == v[first]->fValue())
			if(v[i]->hValue < v[first]->hValue)
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
