#if !defined(STATICQUEUE_HPP)
#define STATICQUEUE_HPP

#define DIM 8

struct StaticQueue
{
    int head, tail;
    int vect[DIM + 1]{};

    StaticQueue() : head(0), tail(0) {}
    int NextPosition(int index);
    void Push(int x);
    void Pop();
};
// vom introduce pe tail - 1 ca sa avem un spatiu liber intre tail si head

#endif // STATICQUEUE_HPP
