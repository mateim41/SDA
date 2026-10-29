#include "DoublyLinkedList.hpp"

void LinkedList::Add(LinkedNode *&cap, LinkedNode *&last, int elem)
{
    LinkedNode *p = new LinkedNode;
    p->data = elem;
    if (!cap)
    {
        p->succ = p;
        p->prev = p;
        cap = p;
        last = cap;
    }
    else
    {
        p->succ = cap;
        cap->prev = p;
        p->prev = last;
        last->succ = p;
        cap = p;
    }
}

void LinkedList::DeleteList(LinkedNode *&cap)
{
    LinkedNode *p = cap->succ;
    while (p->succ != cap)
    {
        LinkedNode *temp = p->succ;
        delete p;
        p = temp;
    }
    delete cap;
    cap = nullptr;
}
