#if !defined(HASHMAP_HPP)
#define HASHMAP_HPP

#include <string>

struct Node
{
    int key; // indexul la care adaug elem
    std::string value;
    Node *next = nullptr;
};

struct List
{
    Node *first = nullptr, *last = nullptr;
};

// pt chei alfanumerice
int transf_ascii(const std::string &key)
{
    int sum = 0;
    for (auto &&i : key)
    {
        sum += int(i);
    }
    return sum;
}

int HF(const int &M, const std::string &p)
{
    // M - nr de indecsi din hashmap
    // p - primul caracter din sir
    return transf_ascii(p) % M;
}

void push_back(List &l, Node *p)
{
    if (!l.first && !l.last)
    {
        l.first = p;
        l.last = l.first;
    }
    else
    {
        l.last->next = p;
        l.last = p;
    }
}

void ShowList(List &l)
{
    Node *p = l.first;
    while (p)
    {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << "\n";
}

void Add(List HT[], const int &M, const std::string &x)
{
    Node *p = new Node;
    p->value = x;
    p->key = HF(M, x);

    for (int i = 0; i < M; i++)
    {
        if (p->key == i)
        {
            push_back(HT[i], p);
            break;
        }
    }
}

#endif // HASHMAP_HPP