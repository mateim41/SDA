#include <iostream>
#include "StaticQueue.hpp"

int StaticQueue::NextPosition(int index)
{
    if (index < DIM)
        return index + 1;
    return 0;
}

void StaticQueue::Push(int x)
{
    
}
