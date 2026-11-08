#include <iostream>
#include "Queue.hpp"
#include "LinkedQueue.hpp"

int main()
{
    Queue<int> *MyQueue = new Queue<int>();
    MyQueue->Enqueue(2);
    MyQueue->Enqueue(5);
    MyQueue->Enqueue(71);
    MyQueue->Enqueue(-24);
    MyQueue->Enqueue(89);

    int i = 5;
    while (i)
    {
        MyQueue->Dequeue();
        i--;
    }

    delete MyQueue;
    return 0;
}