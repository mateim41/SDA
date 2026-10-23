#include <iostream>
#include "Node.hpp"

void Add(Node *&last, int elem)
{
    Node *p = new Node;
    p->data = elem;
    if (!last)
    {
        last = p;
        last->succ = last;
    }
    else
    {
        Node *legaturaCap = last->succ;
        last->succ = p;
        p->succ = legaturaCap;
        last = p;
    }
}

void CreateCircularList(Node *&cap, Node *&last)
{
    int x = -1;
    std::cout << "Introduceti elemente sau 0 pt a iesi\n";
    std::cout << "Introdu elementul: ";
    std::cin >> x;
    Add(cap, x);
    last = cap;

    while (x)
    {
        std::cout << "Introdu elementul: ";
        std::cin >> x;
        if (!x)
            break;
        Add(last, x);
    }
}

void DeleteList(Node *&cap)
{
    Node *p = cap;
    while (p->succ != cap)
    {
        Node *temp = p->succ;
        delete p;
        p = temp;
    }
    delete p; // ca sa nu iau p->succ care duce la un membru sters
}

void DisplayList(Node *cap)
{
    Node *p = cap;
    while (p)
    {
        std::cout << p->data << " ";
        if (p->succ == cap)
            break;
        p = p->succ;
    }
}

void ExecutePerson(Node *&cap, Node *&last, int index, int m)
{
    Node *p0 = cap;
    Node *prev = nullptr;
    if (index < 1)
    {
        return;
    }
    if (index == 1)
    {
        prev = last;
        last = nullptr;
    }
    for (int i = 0; i < index; i++)
    {
        prev = p0;
        p0 = p0->succ;
        if (i == index - 2)
        {
            break;
        }
    }

    int cnt = 1;
    while (p0 != prev)
    {
        if (cnt == m)
        {
            Node *temp = p0;
            p0 = p0->succ;
            prev->succ = p0;

            std::cout << temp->data << " ";
            delete temp;
            cnt = 1;
        }
        else
        {
            cnt++;
            prev = p0;
            p0 = p0->succ;
        }
    }
    cap = p0;
}
