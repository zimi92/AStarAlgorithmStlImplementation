#include "Grid.h"
#include "PathAStar.h"
void func(Node nd) {
	std::cout << nd.x << " " << nd.y << " " << nd.status << std::endl;
}

int main() {
	Grid grid(5,10);
	grid.manageGrid(10);
	grid.ReadGrid();
	Node *start= new Node(1,1,0,0,0);
	Node * end = new Node(3, 6, 0, 0, 0);
	//std::vector<Node> nodes = grid.ne
	Node temp(0, 0, 0, 0, 0);
	//std::vector<Node> gridNeg = grid.neighbours(1,1);
	//for(int i = 0; i < gridNeg.size(); i++)
	//	std::cout << gridNeg[i].x << " " << gridNeg[i].y << " " << gridNeg[i].status << std::endl;
	PathAStar star;
	star.FindingPath(start, end);
	grid.ReadGrid();
	getchar();
	return 0;
}