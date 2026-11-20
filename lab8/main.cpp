#include <iostream>
#include <fstream>
#include "hashmap.hpp"

bool IsPrime(const int &x)
{
    if (x < 2)
        return false;
    for (int d = 2; d <= x / 2; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}
int PrimInJurulNr(const int &N) // caut cel mai apropiat nr de N
{
    int output = 0;
    for (int i = N; i >= N / 2; i--)
    {
        if (IsPrime(i))
        {
            output = i;
            break;
        }
    }
    return output;
}

int main()
{
    int N = 87;
    int M;
    double alfa = 0;

    alfa = (double)N / PrimInJurulNr(N);
    // alfa = N / M;
    M = N / alfa;
    List HT[M];

    std::string cuvant;
    std::ifstream file("dictionar_termeni_PC.txt");
    while (file >> cuvant)
    {
        Add(HT, M, cuvant);
    }
    for (int i = 0; i < M; i++)
    {

    }

    return 0;
}