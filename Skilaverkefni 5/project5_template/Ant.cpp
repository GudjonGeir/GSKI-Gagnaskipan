#include <iostream>
#include "Ant.h"
using namespace std;
// Create an organism at the given coordinates.
Ant::Ant(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord) {}


// In the given world moves this organism.
void Ant::move()
{

	Move dir = world->randomMove();
	if (dir == UP && ( world->getAt(x, y + 1) == NULL ) && y + 1 < WORLDSIZE)
	{
		movesTo(x, y + 1);
	}
	else if (dir == DOWN && ( world->getAt(x, y - 1) == NULL ) && y != 0)
	{
		movesTo(x, y - 1);
	}
	else if (dir == LEFT && ( world->getAt(x - 1, y) == NULL ) && x != 0)
	{
		movesTo(x - 1, y);
	}
	else if (dir == RIGHT && ( world->getAt(x + 1, y) == NULL ) && x + 1 < WORLDSIZE)
	{
		movesTo(x + 1, y);
	}

	setMoved(true);
	this->breedTicks++;

}

// Makes this organism breed.
void Ant::breed()
{
	if (breedTicks >= BREED_ANTS)
	{
		breedAtAdjacentCell();
	}
}

// Returns the type of this organism.
OrganismType Ant::getType() const
{
	return ANT;
}

// The character representation of this organism.
char Ant::representation() const
{
	return 'o';
}

// The size of this organism.
int Ant::size() const
{
	return 10;
}


// Generates an offspring at the given position.
void Ant::generateOffspring(int whereX, int whereY)
{
	new Ant(world, whereX, whereY);
}


