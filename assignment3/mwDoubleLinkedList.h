/*************************
 * Part #2's header file *
 * Double linked list    *
 *************************/

#ifndef MWDOUBLELINKEDLIST
#define MWDOUBLELINKEDLIST

#include <iostream>                                           // Standard Library
#include <string>                                             // Standard Library
#include "mwLinkedListNode.h"                                 // Custom Library

using namespace std;                                          // Standard Namespace

class mwDoubleLinkedList {                                    // Class Type Name

public:
    mwDoubleLinkedList(void);                                 // Default Constructor

    mwDoubleLinkedList(const mwDoubleLinkedList&);            // Big-3: copy constructor

    ~mwDoubleLinkedList(void);                                // Big-3: destructor

    mwDoubleLinkedList& operator=(const mwDoubleLinkedList&); // Big-3: overloaded assignment operator

    void pushFront(int);                                      // Problem #1
    void pushBack(int);                                       // Problem #2
    void popFront(void);                                      // Problem #3
    void popBack(void);                                       // Problem #4
    void insert(int, int);                                    // Problem #5
    void deleteDuplicates(int);                               // Problem #6
    int mtoLastElement(int) const;                            // Problem #7
    int size(void) const;                                     // Problem #8
    friend ostream& operator<<(                               // Problem #9
        ostream&,
        const mwDoubleLinkedList&
    );
    void reverseList(void);                                   // Problem #10
    mwDoubleLinkedList mergeLists(                            // Problem #11
        mwDoubleLinkedList&,
        mwDoubleLinkedList&
    );

    bool exceptionIsSorted(string) const;                     // Exception Check: Unsorted List
    bool exceptionIsEmpty(string) const;                      // Exception check: Empty List
    bool exceptionOutOfBound(string, int) const;              // Exception check: Out of Bound Position

private:
    mwDoublyIntNode* head;                                    // Member Variable
    mwDoublyIntNode* tail;                                    // Member Variable
    int LLsize;                                               // Member Variable

};

#endif // MWDOUBLELINKEDLIST
