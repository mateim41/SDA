#include <iostream>
#include "StivaStatic.hpp"

void Init(StivaStatic &s)
{
    s.vf = -1;
}

bool IsEmpty(const StivaStatic &s)
{
    if (s.vf == -1)
        return true;
    return false;
}

bool IsFull(const StivaStatic &s)
{
    if (s.vf == DIM - 1)
        return true;
    return false;
}

int Top(const StivaStatic &s)
{
    return s.vect[s.vf];
}

void Push(StivaStatic &s, int elem)
{
    if (!IsFull(s))
    {
        s.vect[++s.vf] = elem;
    }
}

int Pop(StivaStatic &s)
{
    int temp = -1;
    if (!IsEmpty(s))
    {
        temp = s.vect[s.vf];
        s.vect[s.vf--] = 0;

        return temp;
    }
    return temp;
}

void Display(const StivaStatic &s)
{
    for (int i = s.vf; i >= 0; i--)
    {
        std::cout << s.vect[i] << " ";
    }
}
