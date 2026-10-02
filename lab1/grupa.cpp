#include <iostream>
#include <cstring>
#include "grupa.hpp"

void InitGrupa(Grupa &g)
{
    std::cout << "Introdu nr grupei: ";
    std::cin >> g.id;
    std::cout << "Introdu numarul de studenti: ";
    std::cin >> g.nr;

    g.studenti = new Student[g.nr];
    for (int i = 0; i < g.nr; ++i)
    {
        InitStudent(g.studenti[i]);
    }
}

void AfisGrupa(Grupa &g)
{
    std::cout << "ID grupa: " << g.id << "\n";
    for (int i = 0; i < g.nr; i++)
    {
        AfisStudent(g.studenti[i]);
    }
}

void StergeGrupa(Grupa &g)
{
    for (int i = 0; i < g.nr; i++)
    {
        StergeStudent(g.studenti[i]);
    }
    delete g.studenti;
    g.studenti = nullptr;
}

void FindStudent(Grupa &g, char *numeStudent)
{
    bool found = false;
    for (int i = 0; i < g.nr; i++)
    {
        if (strcmp(g.studenti[i].nume, numeStudent) == 0)
        {
            std::cout << numeStudent << " a luat nota " << g.studenti[i].nota << "\n";
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Studentul nu apartine acestei grupe\n";
    }
}

void FindNote(Grupa &g, int &notaMin, int &notaMax)
{
    notaMin = g.studenti[0].nota;
    notaMax = g.studenti[0].nota;
    for (int i = 1; i < g.nr; ++i)
    {
        if (g.studenti[i].nota < notaMin)
            notaMin = g.studenti[i].nota;
        if (g.studenti[i].nota > notaMax)
            notaMax = g.studenti[i].nota;
    }
}
