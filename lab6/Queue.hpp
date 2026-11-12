#if !defined(QUEUE_HPP)
#define QUEUE_HPP

#include <stdexcept>

template <typename T>
class Queue
{
private:
    T *vect = new T[2]{}; // Dynamic Circular Array
    int head, tail;

    int NextPosition(int &index);
    bool IsFull();
    void IncreaseCapacity();

public:
    int Capacity = 2;
    int Count = 0;
    Queue() : head(0), tail(0) {}
    ~Queue();

    bool IsEmpty();
    void Enqueue(T x);
    T Dequeue();
    T Peek();
};

template <typename T>
inline int Queue<T>::NextPosition(int &index)
{
    if (index < Capacity - 1)
        return index + 1;
    return 0;
}

template <typename T>
inline bool Queue<T>::IsFull()
{
    return NextPosition(tail) == head;
    // if (NextPosition(tail) == head)
    //     return true;
    // return false;
}

template <typename T>
inline bool Queue<T>::IsEmpty()
{
    return head == tail;
    // if (head == tail)
    //     return true;
    // return false;
}

template <typename T>
inline void Queue<T>::IncreaseCapacity()
{
    T *temp = new T[Capacity * 2];

    int k = 0;
    int copyCount = Count;
    while (!IsEmpty())
    {
        temp[k++] = Dequeue();
    }
    delete[] vect;
    vect = temp;
    Capacity *= 2;

    Count = copyCount;
    head = 0;
    tail = k;
}

template <typename T>
inline void Queue<T>::Enqueue(T x)
{
    if (!IsFull())
    {
        vect[tail] = x;
        tail = NextPosition(tail);
        Count++;
    }
    else
    {
        IncreaseCapacity();
        vect[tail] = x;
        tail = NextPosition(tail);
        Count++;
    }
}

template <typename T>
inline T Queue<T>::Dequeue()
{
    if (!IsEmpty())
    {
        T temp = vect[head];
        vect[head] = T{};
        head = NextPosition(head);
        Count--;
        return temp;
    }
    else
        throw std::out_of_range("Queue is empty");
}

template <typename T>
inline T Queue<T>::Peek()
{
    if (!IsEmpty())
        return vect[head];
    else
        throw std::out_of_range("Queue is empty");
}

template <typename T>
inline Queue<T>::~Queue()
{
    delete[] vect;
    vect = nullptr;

    head = -1;
    tail = -1;
    Count = 0;
    Capacity = 0;
}

#endif // QUEUE_HPP