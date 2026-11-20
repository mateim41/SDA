#if !defined(STACK_HPP)
#define STACK_HPP

#include <stdexcept>

template <typename T>
struct Node
{
    T data = T{};
    Node *next = nullptr;
};

template <typename T>
class Stack
{
private:
    Node<T> *first;
    Node<T> *last;
    

public:
    ~Stack();
    bool IsEmpty();
    void Push(T x);
    T Pop();
    T Top();
};

template <typename T>
inline bool Stack<T>::IsEmpty()
{
    if (!first && !last)
        return true;
    return false;
}

template <typename T>
inline Stack<T>::~Stack()
{
    Node<T> *p = first;
    while (p)
    {
        Node<T> *temp = p->next;
        delete p;
        p = temp;
    }
}

template <typename T>
inline void Stack<T>::Push(T x)
{
    Node<T> *p = new Node<T>;
    p->data = x;
    if (IsEmpty())
    {
        first = p;
        last = first;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

template <typename T>
inline T Stack<T>::Pop()
{
    if (!IsEmpty())
    {
        Node<T> *q = first;
        while (q->next != last)
        {
            q = q->next;
        }
        T data = last->data;

        delete last;
        last = q;

        return data;
    }
    else
        throw std::out_of_range("Stack is empty");
}

template <typename T>
inline T Stack<T>::Top()
{
    return last->data;
}

#endif // STACK_HPP