#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

namespace LinkedList
{
    struct LinkedNode
    {
        int data;
        LinkedNode *succ;
        LinkedNode *prev;
    };
    // Insert in front of the list
    void Add(LinkedNode *&cap, LinkedNode *&last, int elem);
    void DeleteList(LinkedNode *&cap);
}
#endif