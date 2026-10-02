#include <iostream>
#include <cstring>
#include "student.hpp"
#include "grupa.hpp"

void pb1()
{
    Student s1;
    InitStudent(s1);
    AfisStudent(s1);
    StergeStudent(s1);
}

void pb2()
{
    Grupa g1;
    InitGrupa(g1);
    AfisGrupa(g1);

    char buffer[20];
    std::cout << "Introdu numele de cautat: ";
    std::cin.getline(buffer, 20);
    char *numeStudent = new char[strlen(buffer) + 1];
    strcpy(numeStudent, buffer);
    FindStudent(g1, numeStudent);

    int notaMin, notaMax;
    FindNote(g1, notaMin, notaMax);
    std::cout << "\nNota minima: " << notaMin << "\nNota maxima: " << notaMax << "\n";

    StergeGrupa(g1);
}

int main()
{
    // pb1();
    pb2();

    return 0;
}
