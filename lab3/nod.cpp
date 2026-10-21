#include <iostream>
#include "nod.hpp"

void CreateList(Nod *&cap) // cu inserare in fata listei
{
    int x;
    std::cout << "Introduceti x (0 pt a iesi): ";
    std::cin >> x;
    while (x)
    {
        InsertFront(x, cap);
        std::cout << "Introdu x: ";
        std::cin >> x;
    }
    std::cout << "\n";
}

void CreateList(Nod *&cap, Nod *&last)
{
    int x;
    std::cout << "Introduceti x sau 0 pt a iesi: ";
    std::cin >> x;
    while (x)
    {
        if (cap == nullptr)
        {
            Add(x, cap);
            last = cap;
        }
        else
        {
            Add(x, last);
        }
        std::cout << "Introduceti x: ";
        std::cin >> x;
    }
}

void DeleteList(Nod *&cap)
{
    while (cap)
    {
        Nod *temp = cap;
        cap = cap->succ;
        delete temp;
    }
}

void Add(int elem, Nod *&last)
{
    Nod *p = new Nod;
    p->data = elem;
    if (last == nullptr) // primul element
    {
        last = p;
    }
    else
    {
        last->succ = p;
        last = p;
    }
}

void Remove(int elem, Nod *&cap)
{
    Nod *p = cap;
    Nod *q = p->succ;
    while (q)
    {
        if (q->data == elem)
        {
            p->succ = q->succ;
            delete q;
            q = nullptr;
            break;
        }
        p = q;
        q = q->succ;
    }
}

void DisplayByIndex(int k, Nod *&cap)
{
    Nod *p = cap;
    Nod *q = p;
    for (int i = 0; i < k - 1; i++)
    {
        q = q->succ;
    }
    while (q)
    {
        p = p->succ;
        q = q->succ;
    }
    std::cout << p->data << "\n";
}

void DisplayBothWays(Nod *cap)
{
    auto p = cap;
    if (p)
    {
        std::cout << p->data << " ";
        DisplayBothWays(p->succ);
        std::cout << p->data << " ";
    }
}

void InsertFront(int elem, Nod *&cap)
{
    Nod *p = new Nod;
    p->data = elem;
    p->succ = cap;
    cap = p;
}

void Insert(int elem, int index, Nod *&cap)
{
    Nod *p = new Nod;
    p->data = elem;
    Nod *q = cap;
    for (int i = 0; i < index - 1; ++i) // pp ca utilizatorul introduce cu indexare de la 1
    {
        if (i == index - 2)
        {
            p->succ = q->succ;
            q->succ = p;
            break;
        }
        q = q->succ;
    }
}

void DisplayList(Nod *cap)
{
    auto p = cap;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->succ;
    }
}

bool Contains(int x, Nod *cap)
{
    Nod *p = cap;
    while (p)
    {
        if (p->data = x)
            return true;
        p = p->succ;
    }
    return false;
}

bool ListHasLoops(Nod *cap)
{
    auto p = cap;
    auto q = p->succ->succ;
    while (q)
    {
        if (p == q)
        {
            return true;
        }
        p = p->succ;
        q = q->succ;
    }
    return false;
}

Nod *DetermineMiddleElement(Nod *cap)
{
    Nod *p = cap;
    Nod *q = cap->succ->succ;
    while (q)
    {
        p = p->succ;
        if (q->succ != nullptr)
        {
            q = q->succ->succ;
        }
        else
        {
            q = q->succ;
        }
    }
    return p;
}

void InvertLinks(Nod *&cap)
{
    Nod *prev = 0;
    Nod *next = cap->succ;
    while (next)
    {
        cap->succ = prev;
        prev = cap;
        cap = next;
        next = next->succ;
    }
    cap->succ = prev;
}

// NU returna referinta
// variabila din interior se distruge, insa eu voi returna adresa corespunzatoare
Nod *MergeLists(Nod *&xcap, Nod *&ycap)
{
    Nod *zcap;
    Nod *p = xcap;
    Nod *q = p->succ;

    Nod *r = ycap;
    Nod *s = r->succ;
    while (q != nullptr && s != nullptr)
    {
        p->succ = r;
        r->succ = q;

        p = q;
        q = q->succ;

        r = s;
        s = s->succ;
    }
    if (q == nullptr)
    {
        p->succ = r;
    }
    else if (s == nullptr)
    {
        p->succ = r;
        r->succ = q;
    }

    zcap = xcap;
    xcap = nullptr;
    ycap = nullptr;
    return zcap;
}