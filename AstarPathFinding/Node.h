#pragma once
class Node
{
public:
	int x;
	int y;
	int hValue;
	int fValue();
	int gValue;
	int status;
	bool Node::operator==(const Node &node) {
		if (this->x == node.x && this->y == node.y) {
			return true;
		}
		return false;
	}
	Node(int, int, int, int, int);
	~Node();
};

