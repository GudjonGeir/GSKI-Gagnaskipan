#include <iostream>
#include "Organism.h"
#include "World.h"

// Create an organism at the given coordinates in the given world.
Organism::Organism(World* aWorld, int xcoord, int ycoord) 
{
    world = aWorld;
    x = xcoord;
    y = ycoord;
    breedTicks = 0;
    moved = false;
    dead = false;
    world->setAt(x, y, this);
}

// flags the organism as moved or not
void Organism::setMoved(bool hasMoved) 
{
    this->moved = hasMoved;
}

// has the organism moved or not?
bool Organism::hasMoved() const 
{
    return moved;
}

void Organism::setDead(bool hasDied)
{
	dead = hasDied;
}

// moves the organism from coordinates (x,y) to (xNew,yNew)
void Organism::movesTo(int xNew, int yNew) 
{
	world->setAt(xNew, yNew, this);
	world->setAt(x, y, NULL);
	this->x = xNew;
	this->y = yNew;
}


// Breeds an organism at an adjacent cell. This method calls the
// generateOffspring() method.
void Organism::breedAtAdjacentCell()  
{
	if (world->getAt(x, y + 1) == NULL && y + 1 < WORLDSIZE)
	{
		generateOffspring(x, y + 1);
		breedTicks = 0;
		return;
	}
	else if (world->getAt(x, y - 1) == NULL && y - 1 >= 0)
	{
		generateOffspring(x, y - 1);
		breedTicks = 0;
		return;
	}
	else if (world->getAt(x - 1, y) == NULL && x - 1 >= 0)
	{
		generateOffspring(x - 1, y);
		breedTicks = 0;
		return;
	}
	else if (world->getAt(x + 1, y) == NULL && x + 1 <  WORLDSIZE)
	{
		generateOffspring(x + 1, y);
		breedTicks = 0;
		return;
	}
}
// Returns true if organism is dead, false otherwise.
bool Organism::isDead() const 
{
    return dead;
}
