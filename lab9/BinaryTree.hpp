#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

template <typename T>
struct Node
{
    T data = T{};
    Node *st = nullptr, *dr = nullptr;
};

#define Arbore Node

template <typename T>
void RSD(const Arbore<T> *r) // preordine
{
    if (r)
    {
        std::cout << r->data << " ";
        RSD(r->st);
        RSD(r->dr);
    }
}

template <typename T>
void SRD(const Arbore<T> *r) // inordine
{
    if (r)
    {
        SRD(r->st);
        std::cout << r->data << " ";
        SRD(r->dr);
    }
}

template <typename T>
void SDR(const Arbore<T> *r) // postordine
{
    if (r)
    {
        SDR(r->st);
        SDR(r->dr);
        std::cout << r->data << " ";
    }
}

template <typename T>
int Depth(Arbore<T> *&r) // nr niveluri
{
    if (!r)
        return 0;
    return 1 + std::max(Depth(r->st), Depth(r->dr));
}

template <typename T>
int NrNoduri(Arbore<T> *&r)
{
    if (!r)
        return 0;
    return 1 + NrNoduri(r->st) + NrNoduri(r->dr);
}

template <typename T>
int NrFrunze(Arbore<T> *r)
{
    if (r)
    {
        if (!r->st && !r->dr)
            return 1;
    }
    else
        return 0;
    return NrFrunze(r->st) + NrFrunze(r->dr);
}

Arbore<char> *creareArbore();

template <typename T>
void Insert(Arbore<T> *&r, const T &x, bool insertLeft = true) // A shaped tree
{
    if (insertLeft)
    {
        if (r && r->st)
        {
            Insert(r->st, x);
        }
        else if (!r)
        {
            Node<T> *p = new Node<T>;
            p->data = x;
            r = p;
            return;
        }
        else
        {
            Node<T> *p = new Node<T>;
            p->data = x;
            r->st = p;
            return;
        }
    }
    else
    {
        if (r && r->dr)
        {
            Insert(r->dr, x, false);
        }
        else if (!r)
        {
            Node<T> *p = new Node<T>;
            p->data = x;
            r = p;
            return;
        }
        else
        {
            Node<T> *p = new Node<T>;
            p->data = x;
            r->dr = p;
            return;
        }
    }
}

template <typename T>
void DeleteArbore(Arbore<T> *&r)
{
    if (r->st)
    {
        DeleteArbore(r->st);
    }
    if (r->dr)
    {
        DeleteArbore(r->dr);
    }
    if (r)
    {
        delete r;
        r = nullptr;
    }
}

#endif