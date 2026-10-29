#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <string>

namespace LinkedList
{
    struct LinkedNode
    {
        std::string data;
        LinkedNode *succ;
        LinkedNode *prev;
    };
    // Insert in front of the list
    void Add(LinkedNode *&cap, LinkedNode *&last, std::string elem);
    void DisplayList(LinkedNode *cap);
    void RemoveFirst(LinkedNode *&cap, LinkedNode *&last);

    void Compare(LinkedNode *xcap, LinkedNode *ycap);
    void Sum(LinkedNode *xcap, LinkedNode *ycap);
    void DeleteList(LinkedNode *&cap);
}
std::string GetInputNumber();

#endif