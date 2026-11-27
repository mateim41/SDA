#include <iostream>
#include "BinaryTree.hpp"

int main()
{
    // Arbore<int> *rad = nullptr;
    // Insert(rad, 1);        // cap
    // Insert(rad, 2, false); // dr
    // Insert(rad, 3);        // st
    // Insert(rad, 4);        // st
    // Insert(rad, 5, false); // dr
    // SRD(rad);
    // Node<int> *p = new Node<int>;
    // p->data = 1;
    // rad = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 2;
    // rad->st = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 3;
    // rad->dr = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 4;
    // rad->st->st = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 5;
    // rad->st->dr = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 6;
    // rad->dr->st = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 7;
    // rad->dr->dr = p;
    // p = nullptr;

    // p = new Node<int>;
    // p->data = 8;
    // rad->st->st->st = p;
    // p = nullptr;

    // std::cout << Depth(rad) << "\n";
    // DeleteArbore(rad);
    Arbore<char> *r = creareArbore();
    RSD(r);
    std::cout << "\n";
    std::cout << Depth(r) << "\n"
              << NrFrunze(r) << "\n"
              << NrNoduri(r) << "\n";

    DeleteArbore(r);
    return 0;
}