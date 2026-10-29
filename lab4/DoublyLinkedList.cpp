#include <iostream>
#include <cstring>
#include "DoublyLinkedList.hpp"

void LinkedList::Add(LinkedNode *&cap, LinkedNode *&last, std::string elem)
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
        cap = p;
        cap->prev = last;
        last->succ = cap;
    }
}

void LinkedList::DisplayList(LinkedNode *cap)
{
    LinkedNode *p = cap;
    if (p->data.substr(0, 2) == "00")
    {
        std::cout << p->data.substr(2);
    }
    else if (p->data.substr(0, 1) == "0")
    {
        std::cout << p->data.substr(1);
    }
    else
        std::cout << p->data;
    p = p->succ;

    while (p != cap)
    {
        std::cout << p->data;
        p = p->succ;
    }
}

void LinkedList::RemoveFirst(LinkedNode *&cap, LinkedNode *&last)
{
    LinkedNode *p = cap;
    cap = cap->succ;
    delete p;

    cap->prev = last;
    last->succ = cap;
}

// functia nu returneaza bine
void LinkedList::Compare(LinkedNode *xcap, LinkedNode *ycap)
{
    auto p = xcap;
    auto r = ycap;
    do
    {
        if (p > r)
        {
            std::cout << "Primul numar este mai mare decat al doilea\n";
            return;
        }
        else if (p < r)
        {
            std::cout << "Primul numar este mai mic decat al doilea\n";
            return;
        }
        p = p->succ;
        r = r->succ;
    } while (p != xcap && r != ycap);
    std::cout << "Cele doua numere sunt egale\n";
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

std::string GetInputNumber()
{
    std::string nr;
    std::cout << "Introduceti nr: ";
    std::cin >> nr;
    // std::getline(std::cin >> std::ws, nr); daca mai am std::cin in program

    if (nr.length() % 3)
    {
        auto lung = nr.length();
        int lungModificata = 3 * (lung / 3 + 1);
        if (lungModificata - lung == 2)
            nr = "00" + nr;
        else
            nr = "0" + nr;
    }
    return nr;
}
