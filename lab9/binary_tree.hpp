#if !defined(BINARYTREE_HPP)
#define BINARYTREE_HPP

#include <iostream>

struct Node
{
	char data;
	Node *st, *dr;
};

#define Arbore Node

void RSD(Arbore *&r); // preordine
void SRD(Arbore *&r); // inordine
void SDR(Arbore *&r); // postordine
int Depth(const Arbore *const &r);
int NrNoduri(const Arbore *const &r);
int NrFrunze(const Arbore *const &r);
Node *creareArbore();
void DeleteArbore(Arbore *&r);

#endif // BINARYTREE_HPP
