#ifndef GRUPA_HPP
#define GRUPA_HPP
#include "student.hpp"

struct Grupa
{
    Student *studenti;
    int nr; // nr studenti
    int id; // identificatorul grupei
};
void InitGrupa(Grupa &);
void AfisGrupa(Grupa &);
void StergeGrupa(Grupa &);
void FindStudent(Grupa &, char *numeStudent);
void FindNote(Grupa &, int &notaMin, int &notaMax);

#endif