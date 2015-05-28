#ifndef ANT_H
#define ANT_H
#include "World.h"
#include "Organism.h"

class Ant : public Organism 
{
    public:
        // Create an organism at the given coordinates.
        Ant(World* aWorld, int xcoord, int ycoord);
        virtual ~Ant() { }

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
};

#endif // ANT_H

