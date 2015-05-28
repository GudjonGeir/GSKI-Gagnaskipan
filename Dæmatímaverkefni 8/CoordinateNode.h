#ifndef COORDINATENODE_H 
#define  COORDINATENODE_H

#include <iostream>
struct Coordinate
{
	Coordinate(int x = 0, int y = 0);

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}
	int x;
	int y;
};



struct CoordinateNode
{
    CoordinateNode(string key, Coordinate value, CoordinateNode* left = NULL, CoordinateNode* right = NULL);
    bool is_leaf();

    string key;
    Coordinate value;
    ContactNode *left;
    ContactNode *right;
};

typedef CoordinateNode* NodePtr;
#endif

