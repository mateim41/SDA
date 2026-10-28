#include <iostream>
#include "Node.hpp"
// mereu cand e de sters facem o copie si stergem copia (de ex la cap nu stergem capul ci copia)

void pb1()
{
    LinkedNode *cap = nullptr;
    LinkedNode *last = nullptr;
    CreateDoublyLinkedList(cap);
    PrintList(cap);
    RemoveBeforeIndex(cap, 3);
    std::cout << "\n";
    PrintList(cap);

    DeleteList(cap);
}

void pb2a()
{
    LinkedNode *xcap = nullptr;
    LinkedNode *xlast = nullptr;
    CreateDoublyLinkedList(xcap, xlast);
    std::cout << "\n";

    LinkedNode *ycap = nullptr;
    LinkedNode *ylast = nullptr;
    CreateDoublyLinkedList(ycap, ylast);

    LinkedNode *zcap = nullptr;
    xlast->succ = ycap;
    ycap->prev = xlast;
    zcap = xcap;
    xcap = nullptr;
    ycap = nullptr;
    xlast = nullptr;
    ylast = nullptr;
    PrintList(zcap);

    DeleteList(zcap);
}

void pb2b()
{
    LinkedNode *xcap = nullptr;
    LinkedNode *xlast = nullptr;
    CreateDoublyLinkedList(xcap, xlast);
    std::cout << "\n";

    LinkedNode *ycap = nullptr;
    LinkedNode *ylast = nullptr;
    CreateDoublyLinkedList(ycap, ylast);

    LinkedNode *zcap = MergeLists(xcap, ycap);
    xlast = nullptr;
    ylast = nullptr;
    PrintList(zcap);

    DeleteList(zcap);
}

void pb3()
{
    Node *cap = nullptr;
    Node *last = nullptr;
    CreateCircularList(cap, last);
    DisplayList(cap);
    std::cout << "\n";
    InvertLinks(cap);
    DisplayList(cap);

    DeleteList(cap);
}

void pb4()
{
    Node *xcap = nullptr;
    Node *xlast = nullptr;
    CreateCircularList(xcap, xlast);

    Node *ycap = nullptr;
    Node *ylast = nullptr;
    CreateCircularList(ycap, ylast);

    // Node *zcap = ConcatenateCircularSinglyLinkedLists(xcap, ycap);
    Node *zcap = MergeCircularLists(xcap, ycap);
    xlast = nullptr;
    ylast = nullptr;
    DisplayList(zcap);

    DeleteList(zcap);
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
    // pb1();
    // pb2a();
    // pb2b();
    // pb3();
    pb4();
    // pb5();

    return 0;
}