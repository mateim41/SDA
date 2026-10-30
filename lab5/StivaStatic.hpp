#ifndef STIVASTATIC_HPP
#define STIVASTATIC_HPP

#define DIM 10

struct StivaStatic
{
    int vf;
    int vect[DIM]{};
};
void Init(StivaStatic &s);
bool IsEmpty(const StivaStatic &s);
bool IsFull(const StivaStatic &s);
int Top(const StivaStatic &s);
void Push(StivaStatic &s, int elem);
int Pop(StivaStatic &s);

void Display(const StivaStatic &s);

#endif