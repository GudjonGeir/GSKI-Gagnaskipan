#ifndef COORDSET_H
#define COORDSET_H

#include <iostream>
#include <string>
#include <vector>
#include "CoordinateNode.h"

class CoordSet
{
	public:

		// Creates an empty set
		CoordSet ();

		~CoordSet();

		bool insert();

		void removeAll();

	private:
		NodePtr root;
}

#endif
