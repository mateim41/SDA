#if !defined(QUEUE_HPP)
#define QUEUE_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Queue
{
private:
    int head, tail;
    T *vect = new T[2]{};

    int NextPosition(int &index);
    bool IsEmpty();
    bool IsFull();

public:
    int Capacity = 2;
    int Count = 0;

    Queue() : head(0), tail(0) {}
    ~Queue();
    void Enqueue(T x);
    T Dequeue();
    T Peek();
};
// tail ne va arata urmatorul spatiu liber pentru a insera astel incat
// vom insera pe index tail - 1 ca sa avem un spatiu liber intre tail si head

// daca ajung la finalul array-ului revin la inceput pe index 0

template <typename T>
inline int Queue<T>::NextPosition(int &index)
{
    if (index < Capacity - 1)
        return index + 1;
    return 0;
}

template <typename T>
inline bool Queue<T>::IsEmpty()
{
    return head == tail;
}

template <typename T>
inline bool Queue<T>::IsFull()
{
    return NextPosition(tail) == head;
}

template <typename T>
inline Queue<T>::~Queue()
{
    delete[] vect;
    vect = nullptr;

    Capacity = 0;
    Count = 0;
    head = -1;
    tail = -1;
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
    // In order to dequeue correctly I have to modify the capacity only after I'm done copying the elements
    // I make a copy of the Count because Dequeue modifies the number of elements
    {
        T *temp = new T[Capacity * 2]{};

        int k = 0;
        int copyCount = Count;
        while (!IsEmpty())
        {
            temp[k++] = Dequeue();
        }
        delete[] vect;
        vect = temp;

        Capacity *= 2;
        head = 0;
        tail = k;
        vect[tail] = x;
        tail = NextPosition(tail);
        Count = copyCount + 1;
    }
}

template <typename T>
inline T Queue<T>::Dequeue()
{
    if (!IsEmpty())
    {
        T temp = vect[head];
        vect[head] = T{}; // default value

        head = NextPosition(head);
        Count--;
        return temp;
    }
    else
    {
        throw std::out_of_range("Queue is empty.");
    }
}

template <typename T>
inline T Queue<T>::Peek()
{
    if (!IsEmpty())
        return vect[head];
    else
        throw std::out_of_range("Queue is empty.");
}

#endif // QUEUE_HPP
