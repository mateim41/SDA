#include <iostream>
#include <string>
#include <fstream>
#include "hashmap.hpp"

bool IsPrime(const int &x)
{
    if (x < 2)
        return false;
    for (int d = 2; d <= x / 2; d++)
        if (x % d == 0)
            return false;
    return true;
}

int ClosestPrime(const int &N, bool lessThan = true)
{
    if (lessThan)
    {
        for (int i = N; i >= N / 2; i--)
        {
            if (IsPrime(i))
                return i;
        }
    }
    else
    {
        for (int i = N; i <= 2 * N; i++)
        {
            if (IsPrime(i))
                return i;
        }
    }
    return -1;
}

int main()
{
    int N = 87;
    int M; // trb sa caut M cat mai aproape de N ai alfa sa dea in jur de 1
           // M - prim
    M = ClosestPrime(N);
    // double alfa = (double)N / M; 0.5 < alfa < 2
    // factorul de incarcare
    // ne arata cam cate elemente ar reveni pe fiecare index
    // alfa = N / M
    // unde N - nr de elemente pe care vrem sa le introducem
    //      M - nr de elemente al tabelei de dispersie

    List HT[M];
    std::fstream file("dictionar_termeni_PC.txt");
    std::string cuv;
    while (file >> cuv)
    {
        AddHT(HT, M, cuv);
    }
    DeleteEntry(HT, M, "script");
    DisplayHT(HT, M);

    DeleteHT(HT, M);
    return 0;
}