#ifndef NOD_HPP
#define NOD_HPP

// Nod / Element
struct Nod
{
    int data;
    Nod *succ;
};
void CreateList(Nod *&cap);             // by adding in front of the list
void CreateList(Nod *&cap, Nod *&last); // by adding at the end of the list
void DeleteList(Nod *&cap);
void Add(int elem, Nod *&last);        // add element at the end of the list
void Remove(int elem, Nod *&cap);      // remove the first apparition of the given element
void DisplayByIndex(int k, Nod *&cap); // al k-lea element de la coada
void DisplayBothWays(Nod *cap);
void InsertFront(int elem, Nod *&cap);
void Insert(int elem, int index, Nod *&cap);
void DisplayList(Nod *cap);
bool Contains(int x, Nod *cap);
bool ListHasLoops(Nod *cap);
Nod *DetermineMiddleElement(Nod *cap);
void InvertLinks(Nod *&cap);
Nod *MergeLists(Nod *&xcap, Nod *&ycap);

#endif