#include <iostream>
#include <cstring>
#include "student.hpp"

void InitStudent(Student &s)
{
    std::cout << "Introduceti nota: ";
    std::cin >> s.nota;

    std::cout << "\nIntrodu numele studentului: ";
    char buffer[20];
    std::cin >> std::ws;
    std::cin.getline(buffer, 20);
    s.nume = new char[strlen(buffer) + 1];
    std::strcpy(s.nume, buffer);
}

void AfisStudent(Student &s)
{
    std::cout << s.nume << "\n";
    std::cout << "Nota: " << s.nota << "\n";
}

void StergeStudent(Student &s)
{
    delete s.nume;
    s.nume = nullptr;
}