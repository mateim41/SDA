#include <iostream>
#include "nod.hpp"

int main()
{
    int x = -1;
    Nod *cap = nullptr;
    CreateList(cap);

    // std::cout << "\nIntroduceti elementul cautat: ";
    // std::cin >> x;
    // std::cout << "X gasit: " << Contains(x, cap) << "\n";

    std::cout << "Introduceti elementul: ";
    std::cin >> x;
    std::cout << "Introduceti pozitia: ";
    int poz;
    std::cin >> poz;
    Insert(x, poz, cap);

    Remove(5, cap);
    DisplayList(cap);
    std::cout << "\n";

    DisplayByIndex(3, cap);
    DisplayList(cap);
    std::cout << "\n\n";

    DisplayBothWays(cap);
    std::cout << "\n\n";


    
    DeleteList(cap);
    return 0;
}
