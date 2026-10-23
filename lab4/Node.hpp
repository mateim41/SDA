#ifndef NODE_HPP
#define NODE_HPP

struct Node
{
    int data;
    Node *succ;
};
// circular singly linked list
//
void Add(Node *&last, int elem);
void Remove(Node *&cap, Node *&last, int elem);
void CreateCircularList(Node *&cap, Node *&last);
void DeleteList(Node *&cap);
void DisplayList(Node *cap);

// problema lui Joseph; Metoda de executare; cea de-a m-a persoana
void ExecutePerson(Node *&cap, Node *&last, int index, int m);

#endif