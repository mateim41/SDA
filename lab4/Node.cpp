#include <iostream>
#include "Node.hpp"

void AddFirst(LinkedNode *&cap, int elem)
{
    LinkedNode *p = new LinkedNode;
    p->data = elem;
    if (!cap)
    {
        cap = p;
        cap->succ = nullptr;
        cap->prev = nullptr;
    }
    else
    {
        p->succ = cap;
        cap->prev = p;
        cap = p;
        cap->prev = 0;
    }
}

void Add(LinkedNode *&last, int elem)
{
    LinkedNode *p = new LinkedNode;
    p->data = elem;
    if (!last)
    {
        last = p;
        last->prev = nullptr;
        last->succ = nullptr;
    }
    else
    {
        last->succ = p;
        p->prev = last;
        last = p;
        last->succ = nullptr;
    }
}

void CreateDoublyLinkedList(LinkedNode *&cap)
{
    int elem = -1;
    std::cout << "Introdu elementul sau 0 pentru a iesi: ";
    std::cin >> elem;
    while (elem)
    {
        AddFirst(cap, elem);
        std::cout << "Introdu elementul sau 0 pentru a iesi: ";
        std::cin >> elem;
    }
}

void CreateDoublyLinkedList(LinkedNode *&cap, LinkedNode *&last)
{
    int elem = -1;
    std::cout << "Introdu elementul sau 0 pentru a iesi: ";
    std::cin >> elem;
    Add(cap, elem);
    last = cap;

    std::cout << "Introdu elementul sau 0 pentru a iesi: ";
    std::cin >> elem;
    while (elem)
    {
        Add(last, elem);
        std::cout << "Introdu elementul sau 0 pentru a iesi: ";
        std::cin >> elem;
    }
}

void PrintList(LinkedNode *cap)
{
    LinkedNode *p = cap;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->succ;
    }
}

// inserarea normala este in fata
void Insert(LinkedNode *&cap, int elem, int index)
{
    LinkedNode *p = new LinkedNode;
    p->data = elem;

    LinkedNode *q = cap;
    for (int i = 0; i < index - 1; i++)
    {
        q = q->succ;
    }
    p->prev = q->prev;
    p->succ = q;
    q->prev->succ = p;
    q->prev = p;
}

void RemoveBeforeIndex(LinkedNode *&cap, int index)
{
    LinkedNode *p = cap;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->succ;
        if (i == index - 2)
            break;
    }
    p->prev->succ = p->succ;
    p->succ->prev = p->prev;
    delete p;
}

void Delete(LinkedNode *&cap)
{
    while (cap)
    {
        LinkedNode *temp = cap;
        cap = cap->succ;
        delete temp;
        temp = nullptr;
    }
}

void Add(Node *&last, int elem)
{
    Node *p = new Node;
    p->data = elem;
    if (!last) // pt lista vida
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
