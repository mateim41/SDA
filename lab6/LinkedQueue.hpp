#if !defined(LINKEDQUEUE_HPP)
#define LINKEDQUEUE_HPP

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node() : next(nullptr) {}
    Node(T x) : data(x), next(nullptr) {}
    Node(const Node *next, T x) : data(x), next(next) {}
};

template <typename T>
struct LinkedQueue
{
    Node<T> *first;
    Node<T> *last;
    LinkedQueue() : first(nullptr), last(nullptr) {}
};

template <typename T>
bool IsEmpty(const LinkedQueue<T> &q)
{
    if (!q.first)
        return true;
    return false;
}

template <typename T>
void Push(LinkedQueue<T> &q, T elem)
{
    Node<T> *p = new Node<T>(elem);
    if (IsEmpty(q))
    {
        q.first = p;
        q.last = p;
    }
    else
    {
        q.last->next = p;
        q.last = p;
    }
}

template <typename T>
void Pop(LinkedQueue<T> &q)
{
    if (!IsEmpty(q))
    {
        Node<T> *currentElem = q.first;
        q.first = q.first->next;

        delete currentElem;
    }
}

template <typename T>
T Front(const LinkedQueue<T> &q)
{
    if (!IsEmpty(q))
        return q.first->data;
    return;
}

template <typename T>
T Back(const LinkedQueue<T> &q)
{
    if (!IsEmpty(q))
        return q.last->data;
    return;
}

template <typename T>
void DisplayLinkedQueue(const LinkedQueue<T> &q)
{
    Node<T> *p = q.first;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
}

template <typename T>
void DeleteList(LinkedQueue<T> &q)
{
    Node<T> *p = q.first;
    while (p)
    {
        Node<T> *temp = p;
        p = p->next;

        delete temp;
    }
}

#endif // LINKEDQUEUE_HPP
