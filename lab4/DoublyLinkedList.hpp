#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <string>
#include <tuple>
namespace LinkedList
{
    struct LinkedNode
    {
        std::string data;
        LinkedNode *succ;
        LinkedNode *prev;
    };
    // Insert in front of the list
    void Add(LinkedNode *&cap, LinkedNode *&last, std::string elem, int &nrElem);
    void DisplayList(LinkedNode *cap);
    void RemoveFirst(LinkedNode *&cap, LinkedNode *&last, int &nrELem);

    void Compare(LinkedNode *xcap, LinkedNode *ycap, const int &xElem, const int &yElem);
    std::tuple<LinkedNode *, LinkedNode *> Sum(LinkedNode *xlast, LinkedNode *ylast);
    void DeleteList(LinkedNode *&cap, LinkedNode *&last, int &nrElem);
}
std::string GetInputNumber();

#endif