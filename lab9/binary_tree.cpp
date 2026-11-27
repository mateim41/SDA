#include <iostream>
#include <algorithm>
#include "binary_tree.hpp"

void RSD(Arbore *&r)
{
    if (r)
    {
        std::cout << r->data << " ";
        RSD(r->st);
        RSD(r->dr);
    }
}

void SRD(Arbore *&r)
{
    if (r)
    {
        SRD(r->st);
        std::cout << r->data << " ";
        SRD(r->dr);
    }
}

void SDR(Arbore *&r)
{
    if (r)
    {
        SDR(r->st);
        SDR(r->dr);
        std::cout << r->data << " ";
    }
}

int Depth(const Arbore *const &r)
{
    if (!r)
        return 0;
    return std::max(1 + Depth(r->st), 1 + Depth(r->dr));
}

int NrNoduri(const Arbore *const &r)
{
    if (!r)
        return 0;
    return 1 + NrNoduri(r->st) + NrNoduri(r->dr);
}

int NrFrunze(const Arbore *const &r)
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

void DeleteArbore(Arbore *&r)
{
    if (r->st)
        DeleteArbore(r->st);
    if (r->dr)
        DeleteArbore(r->dr);
    if (r)
    {
        delete r;
        r = nullptr;
    }
}