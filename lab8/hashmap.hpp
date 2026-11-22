#if !defined(HASHMAP_HPP)
#define HASHMAP_HPP

#include <string>
#include <cmath>

struct Node
{
    std::string key;
    int value; // daca apare sau nu / alta prelucrare pt aceleasi chei
    Node *next;
};

struct List
{
    Node *first = nullptr, *last = nullptr;
};

int transf_ascii(const std::string &cuv)
{
    int sum = 0;
    for (auto &&c : cuv)
    {
        sum += c;
    }
    return sum;
}

int HF_modular(const std::string &cuv, const int &M)
{
    int k = transf_ascii(cuv);
    return k % M;
}

int HF_inmultire(const std::string &cuv, const int &M)
{
    int k = transf_ascii(cuv);
    double A = 0.618034;
    double kA_fract = k * A - floor(k * A);
    return floor(M * kA_fract);
}

void push_back(List &l, Node *&p)
{
    if (!l.first && !l.last)
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        l.last->next = p;
        l.last = p;
    }
}

void Remove(List &l, const std::string &key)
{
    Node *p = l.first;
    while (p)
    {
        if (p->next->key == key)
        {
            p->next = p->next->next;
            delete p->next;
            break;
        }
        p = p->next;
    }
}

void DisplayList(const List &l)
{
    Node *p = l.first;
    while (p)
    {
        std::cout << p->key << '-' << p->value << " | ";
        p = p->next;
    }
    std::cout << "\n";
}

void Display_HT(List HT[], const int &M)
{
    for (int i = 0; i < M; i++)
        DisplayList(HT[i]);
}

void DeleteList(List &l)
{
    Node *p = l.first;
    while (p)
    {
        Node *temp = p->next;
        delete p;
        p = temp;
    }
}

bool Search(List HT[], const int &idx, const std::string &cuv)
{
    Node *q = HT[idx].first; // parcurg lista ca sa vad daca am deja un entry
    while (q)
    {
        if (q->key == cuv)
        {
            return true;
        }
        q = q->next;
    }
    return false;
}

void Add_HT(List HT[], const int &M, const std::string &cuv)
{
    int idx = HF_modular(cuv, M);
    Node *p = new Node;
    p->key = cuv;
    p->value = 1;

    if (!Search(HT, idx, cuv))
        push_back(HT[idx], p);
    // else
    //      prelucrare
}

void DeleteEntry(List HT[], const int &M, const std::string &entry)
{
    int idx = HF_modular(entry, M);
    if (Search(HT, idx, entry))
        Remove(HT[idx], entry);
    else
        std::cout << "Nu exista cheia data\n";
}

void delete_ht(List HT[], const int &M)
{
    for (int i = 0; i < M; i++)
    {
        DeleteList(HT[i]);
    }
}

#endif // HASHMAP_HPP
