#include "CoordinateNode.h"

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool operator< (const Coordinate& lhs, const Coordinate& rhs)
{
	// TODO: Implement
}

bool operator> (const Coordinate& lhs, const Coordinate& rhs)
{
	// TODO: Implement
}

bool operator== (const Coordinate& lhs, const Coordinate& rhs)
{
	// TODO: Implement
}

CoordinateNode::CoordinateNode(string key, Coordinate value, CoordinateNode* left, CoordinateNode* right)
{
	this->key = key;
	this->value = value;
	this->left = left;
	this->right = right;
}

bool CoordinateNode::is_leaf()
{
	// TODO: Implement
}
