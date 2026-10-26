#include <iostream>
#include "Node.hpp"
// mereu cand e de sters facem o copie si stergem copia (de ex la cap nu stergem capul ci copia)

void pb1()
{
    LinkedNode *cap = nullptr;
    LinkedNode *last = nullptr;
    CreateDoublyLinkedList(cap, last);
    RemoveBeforeIndex(cap, 3);
    PrintList(cap);

    Delete(cap);
}

void pb5()
{
    Node *cap = nullptr;
    Node *last = nullptr;
    CreateCircularList(cap, last);
    ExecutePerson(cap, last, 3, 4);

    DeleteList(cap);
}

int main()
{
    pb1();
    // pb5();

    return 0;
}