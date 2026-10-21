#include <iostream>
#include <string>
#include <algorithm>
#include "nod.hpp"
#include "Phonebook.hpp"

void pb1()
{
    int x = -1;
    Nod *cap = nullptr;
    Nod *last = nullptr;
    CreateList(cap, last);

    // std::cout << "\nIntroduceti elementul cautat: ";
    // std::cin >> x;
    // std::cout << "X gasit: " << Contains(x, cap) << "\n";

    // std::cout << "Introduceti elementul: ";
    // std::cin >> x;
    // std::cout << "Introduceti pozitia: ";
    // int poz;
    // std::cin >> poz;
    // Insert(x, poz, cap);

    // Remove(5, cap);
    // DisplayList(cap);
    // std::cout << "\n";

    // DisplayByIndex(3, cap);
    // DisplayList(cap);
    // std::cout << "\n\n";

    // DisplayBothWays(cap);
    // std::cout << "\n\n";

    auto mijloc = DetermineMiddleElement(cap);
    std::cout << mijloc->data << "\n";
    InvertLinks(cap);
    DisplayList(cap);

    DeleteList(cap);
}

void pb2()
{
    Nod *xcap = nullptr;
    Nod *xlast = nullptr;
    Nod *ycap = nullptr;
    Nod *ylast = nullptr;

    // 2a
    // std::cout << "Creati lista x\n";
    // CreateList(xcap, xlast);
    // std::cout << "\nCreati lista y\n";
    // CreateList(ycap, ylast);

    // Nod *zcap = nullptr;
    // Nod *zlast = nullptr;
    // zcap = xcap;
    // xcap = 0;

    // xlast->succ = ycap;
    // xlast = 0;

    // ycap = 0;
    // zlast = ylast;
    // ylast = 0;

    // 2b
    std::cout << "Creati lista x\n";
    CreateList(xcap, xlast);
    std::cout << "\nCreati lista y\n";
    CreateList(ycap, ylast);
    Nod *zcap = nullptr;
    zcap = MergeLists(xcap, ycap); // xcap si ycap devin null

    DisplayList(zcap);
    DeleteList(zcap);
}

void pb3()
{
    Phonebook *phonebook = new Phonebook;
    CreatePhonebook(phonebook);
    std::cout << *phonebook;

    // std::cout << "Introduceti a - Inserare element in lista pe o pozitie\nb - Sterge din lista o anumita persoana\nc - Cauta in agenda numarul unei persoane\nd - Afiseaza agenda\n";
    // char operatie;
    // std::cin >> operatie;
    // std::cin >> std::ws;

    // std::string indexText = 0;
    // std::string nume;
    // std::string telefon;
    // switch (operatie)
    // {
    // case 'a':
    //     std::cout << "Introdu pozitia: ";
    //     std::getline(std::cin, indexText);
    //     int index = std::stoi(indexText); // nu introduc date proaste; corect trb un block try catch
    //     std::cout << "Introdu numele: ";
    //     std::getline(std::cin, nume);
    //     std::cout << "Introdu nr de telefon: ";
    //     std::getline(std::cin, telefon);

    //     phonebook->Insert(nume, telefon, index);
    //     break;
    // // Restul la fel; daca vreau pot sa fac intr-un while si sa tot intreb ce vrea sa faca
    // default:
    //     break;
    // }

    delete phonebook;
}

int main()
{
    // pb1();
    // pb2();
    pb3();

    return 0;
}
