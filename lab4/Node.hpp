#ifndef NODE_HPP
#define NODE_HPP

struct LinkedNode
{
    int data;
    LinkedNode *succ;
    LinkedNode *prev;
};

struct Node
{
    int data;
    Node *succ;
};

void AddFirst(LinkedNode *&cap, int elem);
void Add(LinkedNode *&last, int elem);
void CreateDoublyLinkedList(LinkedNode *&cap);
void CreateDoublyLinkedList(LinkedNode *&cap, LinkedNode *&last);
void PrintList(LinkedNode *cap);
void Insert(LinkedNode *&cap, int elem, int index);
void RemoveBeforeIndex(LinkedNode *&cap, int index); // sterg elementul din fata unui index
void Delete(LinkedNode *&cap);

// circular singly linked list
void Add(Node *&last, int elem);
void Remove(Node *&cap, Node *&last, int elem);
void CreateCircularList(Node *&cap, Node *&last);
void DeleteList(Node *&cap);
void DisplayList(Node *cap);

// problema lui Joseph; Metoda de executare; cea de-a m-a persoana
void ExecutePerson(Node *&cap, Node *&last, int index, int m);

#endif