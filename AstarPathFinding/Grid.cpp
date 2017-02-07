#include "Grid.h"

Grid::Grid(int _x, int _y):x(_x), y(_y)
{
}

void Grid::manageGrid(int obstacles) {
	std::vector<Node> gridPart;
	for (int i = y-1; i >= 0; i--) {
		for (int j = 0; j < x; j++) {
			Node node(j, i, 0, 0, 0);
			if ((i == 2 && j == 3) || (i==0 && j == 0))
				node.status = 1;
			gridPart.push_back(node);
		}
		grid.push_back(gridPart);
		gridPart.clear();
	}
}

int Grid::distance(Node *start, Node *end) {
	int deltax, deltay;
	deltax = (start->x > end->x) ? start->x - end->x : end->x - start->x;
	deltay = (start->y > end->y) ? start->y - end->y : end->y - start->y;

	return ((deltax > deltay) ? 10 * (deltax - deltay) + 14 * (deltay):10 * (deltay - deltax) + 14 * (deltax));
}

Node *Grid::getNode(int mx, int my) {
	if (my < grid.size() && mx < grid[0].size())
		return &grid[y-my-1][mx];
	std::cout << "Argument Out of range please try again" << std::endl;
	return &Node(0, 0, 0, 0, 1);
}

std::vector<Node*> Grid::neighbours(int x, int y) {
	std::vector<Node*> vectorOfneighbours;
	Node *myNode = getNode(x, y);
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++)
			if (getNode(myNode->x + i, myNode->y + j)->status != 1 && (i != 0 || j != 0)) {
				Node *newNode = getNode(myNode->x + i, myNode->y + j);
				vectorOfneighbours.push_back(newNode);
			}
	}
	return vectorOfneighbours;
}

void Grid::ReadGrid() {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			std::cout << grid[i][j].status;
		}
		std::cout<< std::endl;
	}
}

Grid::~Grid()
{
}
