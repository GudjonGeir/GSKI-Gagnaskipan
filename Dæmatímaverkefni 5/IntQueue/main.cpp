#include <iostream>
#include "IntQueue.h"

using namespace std;

int main()
{
    IntQueue queue;
    for (int i = 0; i < 10; ++i)
    {
    	queue.enqueue(i);
    }
    for (int i = 0; i < 10; ++i)
    {
    	cout << queue.dequeue() << endl;
    }
    try
    {
    	queue.dequeue();
    }
    catch(EmptyQueueException())
    {
    	cout << "Error" << endl;
    }
//    for (int i = 0; i < 10; ++i)
//    {
//    	queue.enqueue(i);
//    }
//    cout << queue << endl;
    return 0;
}
