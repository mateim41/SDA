#include <iostream>
#include <cstring>
#include "Phonebook.hpp"

void CreatePhonebook(Phonebook *&phonebook)
{
    std::string nume;
    std::string telefon;
    do
    {
        std::cout << "Introduceti numele sau 'stop' pentru a iesi: ";
        std::getline(std::cin, nume);
        if (nume == "stop") // ar trb facuta o verificare pt datele introduse de utilizator .ToLower()
        {
            break;
        }
        std::cout << "Introduceti numarul de telefon: ";
        std::getline(std::cin, telefon);
        /*
            - std::cin lasa in buffer un \n
            - daca foloseam std::cin pt telefon trebuia sa apelez std::ws in getline pt a elimina \n,\t,\s 

            std::getline(std::cin >> std::ws, nume);
            ...
            std::cin>>telefon;
        */
        phonebook->Add(nume, telefon);
    } while (true);
}

void Phonebook::Add(std::string nume, std::string telefon)
{
    Node *p = new Node;
    p->nume = nume;
    p->telefon = telefon;

    if (!head)
    {
        head = p;
        last = head;
    }
    else
    {
        last->succ = p;
        last = p;
    }
}

void Phonebook::Insert(std::string nume, std::string telefon, int index)
{
    Node *q = new Node;
    q->nume = nume;
    q->telefon = telefon;
    Node *p = head;
    if (index < 1)
    {
        return;
    }
    if (index == 1)
    {
        q->succ = p;
        head = q;
    }
    else
    {
        // 1 based indexing; need to stop before the required index
        for (int i = 0; i < index - 1; i++)
        {
            if (i == index - 2)
            {
                Node *temp = p->succ;
                p->succ = q;
                q->succ = temp;
                break;
            }
            p = p->succ;
        }
    }
}

void Phonebook::Remove(std::string nume, std::string telefon)
{
    Node *p = head;
    Node *q = p->succ;
    while (q)
    {
        if (q->nume == nume && q->telefon == telefon)
        {
            p->succ = q->succ;

            delete q;
            q = nullptr;
            break;
        }
        p = p->succ;
        q = q->succ;
    }
}

Node *Phonebook::SearchPhoneNumber(std::string nume)
{
    Node *p = head;
    while (p)
    {
        if (p->nume == nume)
        {
            return p;
        }
        p = p->succ;
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &output, Node *nod)
{
    output << nod->nume << " " << nod->telefon << "\n";
    return output;
}
std::ostream &operator<<(std::ostream &output, const Phonebook &phonebook)
{
    Node *p = phonebook.head;
    while (p)
    {
        output << p;
        p = p->succ;
    }
    return output;
}

Phonebook::~Phonebook()
{
    while (head)
    {
        Node *temp = head;
        head = head->succ;
        delete temp;
    }
    last = nullptr;
}