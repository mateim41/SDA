#include <iostream>
#include <string>
#include <cstring>
#include "DoublyLinkedList.hpp"
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

void pb6()
{
    std::string nr = GetInputNumber();
    LinkedList::LinkedNode *xcap = nullptr;
    LinkedList::LinkedNode *xlast = nullptr;

    std::string cifre_nr[nr.length() / 3];
    for (int i = 0; i < nr.length() / 3; i++)
    {
        std::string temp = nr.substr(i * 3, 3);
        cifre_nr[i] = temp;
    }

    for (int i = nr.length() / 3 - 1; i >= 0; i--)
    {
        LinkedList::Add(xcap, xlast, cifre_nr[i]);
    }
    std::cout << "\n";
    LinkedList::DisplayList(xcap);
    std::cout << '\n';

    std::string nr2 = GetInputNumber();
    LinkedList::LinkedNode *ycap = nullptr;
    LinkedList::LinkedNode *ylast = nullptr;
    std::string cifre_nr2[nr2.length() / 3];
    for (int i = 0; i < nr2.length() / 3; i++)
    {
        std::string temp = nr2.substr(i * 3, 3);
        cifre_nr2[i] = temp;
    }

    for (int i = nr2.length() / 3 - 1; i >= 0; i--)
    {
        LinkedList::Add(ycap, ylast, cifre_nr2[i]);
    }

    LinkedList::Compare(xcap, ycap);

    LinkedList::DeleteList(xcap);
    LinkedList::DeleteList(ycap);
}

int main()
{
    // pb1();
    // pb2a();
    // pb2b();
    // pb3();
    // pb4();
    // pb5();
    // pb6();
    std::string s1("919");
    std::string s2("918");
    std::cout << (s1 > s2) << "\n";

    return 0;
}