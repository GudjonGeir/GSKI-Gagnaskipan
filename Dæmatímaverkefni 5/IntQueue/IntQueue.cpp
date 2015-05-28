#include <iostream>
#include "IntQueue.h"


IntQueue::IntQueue()
{
	head = NULL;
	tail = NULL;
}

// Destructor
IntQueue::~IntQueue()
{
	NodePtr curr = head, tmpNode;
	while(curr != NULL)
	{
		tmpNode = curr;
		curr = curr->link;
		delete tmpNode;
	}
}

// Returns true if and only if the queue is empty
bool IntQueue::empty() const
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Inserts 'item' at the back of the queue.
void IntQueue::enqueue(int item)
{
	NodePtr tmpNode = new IntNode;
	tmpNode->data = item;
	tmpNode->link = NULL;

	if (empty())
	{
		head = tmpNode;
	}
	else
	{
		tail->link = tmpNode;
	}
	tail = tmpNode;
}

// Removes and returns the front of the queue (i.e. the element that
// was enqueued earliest).
// If the queue is empty, EmptyQueueException is thrown.
int IntQueue::dequeue()
{
	if (empty())
	{
		throw EmptyQueueException();
		return 0;
	}
	int tempInt = head->data;
	NodePtr tmpNode = head;
	if (head == tail) // If queue contains only one item
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->link;
	}

	delete tmpNode;
	return tempInt;
}

// Returns the front of the queue (i.e. the element that
// was enqueued earliest).
// If the queue is empty, EmptyQueueException is thrown.
int IntQueue::front() const
{
	if (empty())
	{
		throw EmptyQueueException();
	}
	int tempInt = head->data;
	return tempInt;
}

// Prints the elements of the queue to the stream 'outs', from front to
// back, separated by a single space.
ostream& operator<< (ostream& outs, const IntQueue& queue)
{
	NodePtr curr = queue.head;
	while(curr != NULL)
	{
		outs << curr->data << " ";
		curr = curr->link;
	}
	return outs;
}
