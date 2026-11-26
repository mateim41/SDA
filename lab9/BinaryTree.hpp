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
int Depth(Arbore<T> *&r)
{
    if (!r)
    {
        return 0;
    }
    int depth_st = 1 + Depth(r->st);
    int depth_dr = 1 + Depth(r->dr);
    return std::max(depth_st, depth_dr);
}

template <typename T>
int NrFrunze(Arbore<T> *r)
{
    if (!r->st && !r->dr)
        return 1;
    int nrFrunze_st = NrFrunze(r->st);
    int nrFunze_dr = NrFrunze(r->dr);
}

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
void Insert_Perfect(Arbore<T> *&r, const T &x)
{
    static int k = 0;
    if (!r)
    {
        Node<T> *p = new Node<T>;
        p->data = x;
        r = p;
        return;
    }
    else if (!r->st || !r->dr)
    {
        if (k == 0)
        {
            Insert_Perfect(r->st, x);
            k++;
        }
        else
        {
            Insert_Perfect(r->dr, x);
            k--;
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