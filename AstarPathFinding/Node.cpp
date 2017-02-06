#include "Node.h"



Node::Node(int _x = 1, int _y = 1, int _hValue = 0, int _gValue = 0, int _status = 0) :x(_x), y(_y), hValue(_hValue), gValue(_gValue), status(_status)
{
	
}										

int Node::fValue() {
	return gValue + hValue;
}

Node::~Node()
{
}
