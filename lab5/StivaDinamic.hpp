#ifndef STIVADINAMIC_HPP
#define STIVADINAMIC_HPP

template <typename T>
struct Node
{
    T data;
    Node *succ;
};

#if !defined(StivaDinamic)
#define StivaDinamic Node

#endif // StivaDinamic

template <typename T>
bool IsEmpty(const StivaDinamic<T> *const &s)
{
    if (!s)
        return true;
    return false;
}

template <typename T>
T Top(const StivaDinamic<T> *const &s)
{
    return s->data;
}

template <typename T>
void Push(StivaDinamic<T> *&s, T elem)
{
    Node<T> *p = new Node<T>;
    p->data = elem;

    p->succ = s;
    s = p;
}

template <typename T>
void Pop(StivaDinamic<T> *&s)
{
    Node<T> *temp = s;
    s = s->succ;
    delete temp;
}

template <typename T>
void Display(const StivaDinamic<T> *const &s)
{
    Node<T> *p = s;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->succ;
    }
}

template <typename T>
void DeleteStiva(StivaDinamic<T> *&s)
{
    while (s)
    {
        Node<T> *temp = s;
        s = s->succ;
        delete temp;
    }
}

#endif