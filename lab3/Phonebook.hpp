#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

struct Node
{
    std::string nume;
    std::string telefon;
    Node *succ;
    friend std::ostream &operator<<(std::ostream &output, Node *nod);
};

class Phonebook
{
private:
    Node *head = nullptr;
    Node *last = nullptr;

public:
    // Add entry at the end of the phonebook
    void Add(std::string nume, std::string telefon);

    // Add entry at selected index
    void Insert(std::string nume, std::string telefon, int index);

    // Remove the first apparition of an entry
    void Remove(std::string nume, std::string telefon);
    // si telefonul pt ca pot exista mai multe persoane cu acelasi nume

    // Search and return the phone number of the first person that matches the given name
    Node *SearchPhoneNumber(std::string nume);

    friend std::ostream &operator<<(std::ostream &output, const Phonebook &phonebook);

    ~Phonebook();
};
void CreatePhonebook(Phonebook *&phonebook);

#endif