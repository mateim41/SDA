#include <iostream>

template <typename T>
struct Node
{
    T data = T{};
    Node *next = nullptr;
};
template <typename T>
Node<T> *InsertRecursiv(Node<T> *&cap, int x)
{
    if (!cap)
    {
        Node<T> *p = new Node<T>;
        p->data = x;
        return p;
    }
    else
    {
        cap->next = InsertRecursiv(cap->next, x);
        return cap;
    }
}
template <typename T>
void DisplayBothWays(Node<T> *&cap)
{
    Node<T> *p = cap;
    if (p)
    {
        std::cout << p->data << " ";
        DisplayBothWays(p->next);
        std::cout << p->data << " ";
    }
}

template <typename T>
void DeleteList(Node<T> *&cap)
{
    Node<T> *p = cap;
    while (p)
    {
        Node<T> *temp = p->next;
        delete p;
        p = temp;
    }
}

int cmmdc(int m, int n)
{
    if (!n)
        return m;
    return cmmdc(n, m % n);
}

double factorial(int n)
{
    if (n == 1)
        return n;
    return n * factorial(n - 1);
}

double putere(int x, int p)
{
    if (p == 0)
        return 1;
    return x * putere(x, p - 1);
}

// n - nr de termeni
double Exp(int x, int n)
{
    if (!n)
        return 1;
    else
    {
        return Exp(x, n - 1) + putere(x, n) / factorial(n);
    }
}

int BinarySearch(int *arr, int elem, int st, int dr)
{
    if (st == dr)
        return arr[st] == elem ? st : -1;
    else
    {
        int mid = (st + dr) / 2;
        if (arr[mid] > elem)
            return BinarySearch(arr, elem, st, mid - 1);
        else
            return BinarySearch(arr, elem, mid, dr);
    }
}

/*
f(0) = 0;
f(1) = 1;
f(2) = 1;
f(3) = 2;
f(4) = 3;
f(5) = 5;
f(6) = 8;
f(7) = 13;
Implementare optimizata cu un array
*/
// int Fibonacci(const int &indexTermen)
// {
//     static int termeni[100];

//     if (indexTermen < 2)
//     {
//         return;
//     }
// }

int main()
{
    // Node<int> *cap = nullptr;
    // cap = InsertRecursiv(cap, 2);
    // cap = InsertRecursiv(cap, 3);
    // cap = InsertRecursiv(cap, 5);
    // DisplayBothWays(cap);
    // DeleteList(cap);

    // std::cout << Exp(5, 50) << "\n";
    // std::cout << Fibonacci(21) << "\n";

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    std::cout << BinarySearch(arr, 2, 0, sizeof(arr) / sizeof(int) - 1) << "\n";

    return 0;
}
