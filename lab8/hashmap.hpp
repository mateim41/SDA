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

int hf_modular(const std::string &key, const int &M)
{
    int k = transf_ascii(key);
    return k % M;
}

int hf_inmultire(const std::string &key, const int &M)
{
    int k = transf_ascii(key);
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
    Node *q = p->next;
    while (q->key != key)
    {
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    delete q;
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

void DisplayHT(List HT[], const int &M)
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

bool Search(List HT[], const int &M, const std::string &key)
{
    int idx = hf_modular(key, M);
    Node *q = HT[idx].first; // parcurg lista ca sa vad daca am deja un entry
    while (q)
    {
        if (q->key == key)
        {
            return true;
        }
        q = q->next;
    }
    return false;
}

void AddHT(List HT[], const int &M, const std::string &key)
{
    int idx = hf_modular(key, M);
    Node *p = new Node;
    p->key = key;
    p->value = 1;

    if (!Search(HT, M, key))
        push_back(HT[idx], p);
    // else
    //      prelucrare
}

void DeleteEntry(List HT[], const int &M, const std::string &entry)
{
    int idx = hf_modular(entry, M);
    if (Search(HT, M, entry))
        Remove(HT[idx], entry);
    else
        std::cout << "Nu exista cheia data\n";
}

void DeleteHT(List HT[], const int &M)
{
    for (int i = 0; i < M; i++)
    {
        DeleteList(HT[i]);
    }
}

#endif // HASHMAP_HPP