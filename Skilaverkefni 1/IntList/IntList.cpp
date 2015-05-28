#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList()     // Constructor: creates an empty list
{
	head = NULL;
}
IntList::~IntList()    // Destructor
{
	removeAll();
}

int IntList::length() // Returns the length of the list
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

// Inserts a node with value the_number at the head of the list
void IntList::headInsert(int the_number)
{
	NodePtr tmpNode = new IntNode;
	tmpNode->setLink(head);
	tmpNode->setData(the_number);
	head = tmpNode;
}

// Inserts a node with value the_number at the end of the list
void IntList::endInsert(int the_number)
{
	NodePtr curr = head;
	if(curr == NULL)
    {
        headInsert(the_number);
    }
	else
    {
        while(curr->getLink() != NULL) // Go to the end of the list
        {
            curr = curr->getLink();
        }

        NodePtr tmpNode = new IntNode;
        tmpNode->setData(the_number);
        tmpNode->setLink(NULL);
        curr->setLink(tmpNode);
	}
}

// Removes the first instance of a node with value the_number from the list
void IntList::remove(int the_number)
{
	NodePtr curr = head, tmpNode;
	if(curr->getData() == the_number)
    {
        head = curr->getLink();
        delete curr;
    }
    else
    {
        while(curr->getLink() != NULL)
        {
            if ((curr->getLink())->getData() == the_number)
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

// Removes all the nodes in the list
void IntList::removeAll()
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

// Reverses the order of the nodes in the list
void IntList::reverse()
{
    if(head == NULL)
    {
        return;
    }
	NodePtr tmpNode1 = head, tmpNode2 = head->getLink(), tmpNode3 = (head->getLink())->getLink();
	tmpNode1->setLink(NULL);
	while(tmpNode3 != NULL)
	{
		tmpNode2->setLink(tmpNode1);
		tmpNode1 = tmpNode2;
		tmpNode2 = tmpNode3;
		tmpNode3 = tmpNode3->getLink();
	}
	tmpNode2->setLink(tmpNode1);
	head = tmpNode2;
}

// A friend function for writing the contents of the list to an output stream
ostream& operator <<(ostream& outs, const IntList& lis)
{
	NodePtr curr = lis.head;
	while(curr != NULL)
	{
		outs << curr->getData() << " ";
		curr = curr->getLink();
	}
	return outs;
}
