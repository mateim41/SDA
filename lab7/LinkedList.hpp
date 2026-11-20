#if !defined(LINKEDLIST_HPP)
#define LINKEDLIST_HPP

#include <exception>

template <typename T>
struct LinkedNode
{
    T data = T{};
    LinkedNode *prev = nullptr;
    LinkedNode *next = nullptr;
};

template <typename T>
class List
{
private:
    LinkedNode<T> *first = nullptr;
    LinkedNode<T> *last = nullptr;

public:
    bool IsEmpty();
    ~List();
    LinkedNode<T> *GetFirst();
    void Add(T x);
    T Pop(); // removes first element
    T RemoveLast();
};

template <typename T>
inline bool List<T>::IsEmpty()
{
    if (!first && !last)
        return true;
    return false;
}

template <typename T>
inline List<T>::~List()
{
    LinkedNode<T> *p = first;
    while (p)
    {
        LinkedNode<T> *temp = p->next;
        delete p;
        p = temp;
    }
}

template <typename T>
inline LinkedNode<T> *List<T>::GetFirst()
{
    return first;
}

template <typename T>
inline void List<T>::Add(T x)
{
    LinkedNode<T> *p = new LinkedNode<T>;
    p->data = x;
    if (IsEmpty())
    {
        first = p;
        last = first;
    }
    else
    {
        last->next = p;
        p->prev = last;
        last = p;
    }
}

template <typename T>
inline T List<T>::Pop()
{
    if (!IsEmpty() && first != last)
    {
        T temp = first->data;
        LinkedNode<T> *p = first;
        first = first->next;
        first->prev = nullptr;

        delete p;
        return temp;
    }
    else if (!IsEmpty())
    {

    }
    else
        throw std::exception();
}

template <typename T>
inline T List<T>::RemoveLast()
{
    if (!IsEmpty() && first != last)
    {
        T temp = last->data;
        LinkedNode<T> *p = last;
        last = last->prev;
        last->next = nullptr;

        delete p;
        return temp;
    }
    else if (!IsEmpty())
    {
        T temp = last->data;
        delete first;
        first = nullptr;
        last = nullptr;

        return temp;
    }
    else
        throw std::exception();
}

#endif // LINKEDLIST_HPP