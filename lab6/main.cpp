#include <iostream>
#include "Queue.hpp"

int main()
{
    Queue<int> q;
    Push(q, 5);
    Push(q, 6);
    Push(q, -2);
    DisplayQueue(q);
    std::cout << "\n";
    Pop(q);
    DisplayQueue(q);

    DeleteList(q);
    return 0;
}