#include <iostream>
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

    delete phonebook;
}

int main()
{
    // pb1();
    // pb2();
    pb3();

    return 0;
}
