#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;


NodePtr createNode(int the_number) {
// Creates a new node with value the_number
// Both links are initialised to NULL
// A pointer to the new node is returned

    NodePtr tmp = new Node;
    tmp->data = the_number;
    tmp->forward_link = NULL;
    tmp->back_link = NULL;
    return tmp;
}

void display(NodePtr head) {
// displays the contents of the list pointed to by head on the screen
    if (head == NULL)
    {
        cout << "Empty list" << endl;
    }
    NodePtr stepPtr = head;
    while(stepPtr != NULL)
    {
        cout << stepPtr->data << " ";
        stepPtr = stepPtr->forward_link;
    }
    cout << endl;
}

void displayReverse(NodePtr head) {
// displays the contents of the list pointed to by head on the screen in a reverse order
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    // Start by finding the tail of the list
    NodePtr stepPtr = head;
    while(stepPtr->forward_link != NULL)
    {
        stepPtr = stepPtr->forward_link;
    }
    while(stepPtr != NULL)
    {
        cout << stepPtr->data << " ";
        stepPtr = stepPtr->back_link;
    }
    cout << endl;
}

void insert(NodePtr& after_me, NodePtr& newNode)
// after_me is a pointer to the node after which newNode will be inserted
{
    if (after_me == NULL)
    {
        //newNode->forward_link = NULL;
        after_me = newNode;
    }
    else if (after_me->forward_link == NULL)
    {
        after_me->forward_link = newNode;
        newNode->back_link = after_me;
        newNode->forward_link = NULL;
    }
    else
    {
        newNode->forward_link = after_me->forward_link;
        (after_me->forward_link)->back_link = newNode;
        newNode->back_link = after_me;
        after_me->forward_link = newNode;
    }

}


void remove(NodePtr& head, NodePtr discard) {
// head is a pointer to the head of the list
// discard is a pointer to the node to remove
    // Then we are discarding the first node
    if (discard->back_link == NULL) {
        // Now the head pointer points to the node after discard (could be NULL)
        head = discard->forward_link;
        // If the head is not NULL, then make sure that its back link is set to NULL
        if (head != NULL) {
            head->back_link = NULL;
        }
    }
    else {
        // Make the node preceeding the discard node point forward to the node coming after discard
        (discard->back_link)->forward_link = discard->forward_link;
        if (discard->forward_link != NULL) {
            // Make the node coming after discard point back to the node preceeding discard
            (discard->forward_link)->back_link = discard->back_link;
        }
    }
    delete discard;    // Now we can safely delete discard
}
