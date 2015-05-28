#include <iostream>
#include <string>
#include "StringSet.h"

StringSet::StringSet()
{
	head = NULL;
}

		// Destructor.
StringSet::~StringSet()
{
	removeAll();
}

		// Returns the number of elements in the set.
int StringSet::size()
{
	NodePtr curr = head;
	int counter = 0;
	while(curr != NULL)
	{
		curr = curr->getLink();
		counter++;
	}
	return counter;
}

		// Inserts 'element' into the set. If 'element' is contained in the
		// set, this operation has no effect.
void StringSet::insert(string element)
{
	if (contains(element)) // Do nothing if element already contained
	{
		return;
	}

	if (element.substr(0, 4) == "not ") // Check if element starts with "not "
	{
		if (contains(element.substr(4))) // Remove from list
		{
			remove(element.substr(4));
		}
		return; // Stop the function
	}

	if (head == NULL) // Check if inserting into empty list
	{
		NodePtr tmpNode = new StringNode;
		tmpNode->setLink(head);
		tmpNode->setData(element);
		head = tmpNode;
		return;
	}
	else
	{
		NodePtr curr = head;
		NodePtr tmpNode = new StringNode;
		if (element < curr->getData())
		{
			tmpNode->setLink(curr);
			tmpNode->setData(element);
			head = tmpNode;
			return;
		}
		while(curr->getLink() != NULL) // Step through list and add if in correct position
		{
			if (element < (curr->getLink())->getData())
			{
				tmpNode->setLink(curr->getLink());
				tmpNode->setData(element);
				curr->setLink(tmpNode);
				return;
			}
			curr = curr->getLink();
		}
		// Add element into back of the list
		tmpNode->setData(element);
		tmpNode->setLink(NULL);
		curr->setLink(tmpNode);
	}
}

		// Removes 'element' from the set. If 'element' is not in the set, this
		// operation has no effect.
void StringSet::remove(string element)
{
	if (!contains(element)) // If element is not in list return
	{
		return;
	}
	else
	{
		NodePtr curr = head, tmpNode;
		if(curr->getData() == element) // Check first element
	    {
	        head = curr->getLink();
	        delete curr;
	    }
	    else
	    {
	        while(curr->getLink() != NULL) // Go through rest of the list
	        {
	            if ((curr->getLink())->getData() == element)
	            {
	                tmpNode = curr->getLink();
	                curr->setLink(tmpNode->getLink());
	                delete tmpNode;
	                break;
	            }
	            curr = curr->getLink();
	        }
    	}
	}
}

		// Returns true if and only if 'element' is a member of the set.
bool StringSet::contains(string element)
{
	NodePtr curr = head;

	while(curr != NULL)
	{
		if (curr->getData() == element)
		{
			return true;
		}
		curr = curr->getLink();
	}
	return false;
}

		// A friend function for writing the contents of the set to an output stream.
ostream& operator <<(ostream& outs, const StringSet& set)
{
	NodePtr curr = set.head;
	while(curr != NULL)
	{
		outs << curr->getData() << endl;
		curr = curr->getLink();
	}
	return outs;
}

void StringSet::removeAll()
{
	NodePtr curr = head, tmpNode;
	while(curr != NULL)
	{
		tmpNode = curr;
		curr = curr->getLink();
		delete tmpNode;
	}
	head = NULL;
}
