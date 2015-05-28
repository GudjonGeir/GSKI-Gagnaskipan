#include <iostream>
#include "Bug.h"
using namespace std;
// Create an organism at the given coordinates.
Bug::Bug(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord) 
{
	feedTicks = 0;
}


// In the given world moves this organism.
void Bug::move()
{
	if (world->getAt(x, y + 1) != NULL && world->getAt(x, y + 1)->getType() == ANT && y + 1 < WORLDSIZE)
	{
		delete world->getAt(x, y + 1);
		movesTo(x, y + 1);
		this->feedTicks = 0;
	}
	else if (world->getAt(x, y - 1) != NULL && world->getAt(x, y - 1)->getType() == ANT && y - 1 >= 0)
	{
		delete world->getAt(x, y - 1);
		movesTo(x, y - 1);
		this->feedTicks = 0;
	}
	else if (world->getAt(x - 1, y) != NULL && world->getAt(x - 1, y)->getType() == ANT && x - 1 >= 0)
	{
		delete world->getAt(x - 1, y);
		movesTo(x - 1, y);
		this->feedTicks = 0;
	}
	else if (world->getAt(x + 1, y) != NULL && world->getAt(x + 1, y)->getType() == ANT && x + 1 < WORLDSIZE)
	{
		delete world->getAt(x + 1, y);
		movesTo(x + 1, y);
		this->feedTicks = 0;
	}
	else
	{
		Move dir = world->randomMove();
		if (dir == UP && (world->getAt(x, y + 1) == NULL) && y + 1 < WORLDSIZE)
		{
			movesTo(x, y + 1);
		}
		else if (dir ==  DOWN && (world->getAt(x, y - 1) == NULL) && y != 0)
		{
			movesTo(x, y - 1);
		}
		else if (dir == LEFT && (world->getAt(x - 1, y) == NULL) && x != 0)
		{
			movesTo(x - 1, y);
		}
		else if (dir == RIGHT && (world->getAt(x + 1, y) == NULL) && x + 1 < WORLDSIZE)
		{
			movesTo(x + 1, y);
		}
		feedTicks++;
	}
	setMoved(true);
	if (this->feedTicks == STARVE_BUGS)
	{
		dead = true;
	}
	breedTicks++;
}

// Makes this organism breed.
void Bug::breed()
{
	if (breedTicks >= BREED_BUGS)
	{
		breedAtAdjacentCell();
	}
}

// Returns the type of this organism.
OrganismType Bug::getType() const
{
	return BUG;
}

// The character representation of this organism.
char Bug::representation() const
{
	return 'X';
}

// The size of this organism.
int Bug::size() const
{
	return 30;
}


// Generates an offspring at the given position.
void Bug::generateOffspring(int whereX, int whereY)
{
	 new Bug(world, whereX, whereY);
}
