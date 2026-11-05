#if !defined(LINKEDNODE_HPP)
#define LINKEDNODE_HPP

// lista simplu inlantuita
template <typename T>
struct LinkedNode
{
    T data;
    LinkedNode *next = nullptr;
    LinkedNode() : next(nullptr) {}
    LinkedNode(T x) : data(x), next(nullptr) {}
    LinkedNode(T x, LinkedNode *next) : data(x), next(next) {}
};
#define StivaDinamic LinkedNode

// bool IsFull(); - doar pt stive statice

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
void Push(StivaDinamic<T> *&s, T x)
{
    LinkedNode<T> *p = new LinkedNode<T>(x);

    p->next = s;
    s = p;
}

template <typename T>
void Pop(StivaDinamic<T> *&s)
{
    if (!IsEmpty(s))
    {
        LinkedNode<T> *temp = s;
        s = s->next;

        delete temp;
    }
}

template <typename T>
void DeleteList(StivaDinamic<T> *&s)
{
    LinkedNode<T> *p = s;
    while (s)
    {
        s = s->next;
        delete p;
        p = s;
    }
}

#endif // LINKEDNODE_HPP
