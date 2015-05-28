#ifndef BUG_H
#define BUG_H
#include "World.h"
#include "Organism.h"

class Bug : public Organism 
{
    public:
        // Create an organism at the given coordinates.
        Bug(World* aWorld, int xcoord, int ycoord);
        virtual ~Bug() { }

        // In the given world moves this organism.
        void move();

        // Makes this organism breed.
        void breed();

        // Returns the type of this organism.
        OrganismType getType() const;

        // The character representation of this organism.
        char representation() const;

        // The size of this organism.
        int size() const;

    protected:
        // Generates an offspring at the given position.
        void generateOffspring(int whereX, int whereY);
    private:
	int feedTicks;
};

#endif // BUG_H
