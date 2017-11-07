/*************************
 * Part #1's header file *
 * Circular linked list  *
 *************************/

#ifndef MWCIRCULARLINKEDLIST
#define MWCIRCULARLINKEDLIST

#include <iostream>                                               // Standard Library
#include <string>                                                 // Standard Library
#include "mwLinkedListNode.h"                                     // Custom Library

using namespace std;                                              // Standard Namespace

class mwCircularLinkedList {                                      // Class Type Name

public:
    mwCircularLinkedList(void);                                   // Default constructor

    mwCircularLinkedList(const mwCircularLinkedList&);            // Big-3: copy constructor

    ~mwCircularLinkedList(void);                                  // Big-3: destructor

    mwCircularLinkedList& operator=(const mwCircularLinkedList&); // Big-3: overloaded assignment operator

    void pushFront(double);                                       // Problem #1
    void pushBack(double);                                        // Problem #2
    void popFront(void);                                          // Problem #3
    void popBack(void);                                           // Problem #4
    void insert(int, double);                                     // Problem #5
    void deleteDuplicates(double);                                // Problem #6
    double mtoLastElement(int) const;                             // Problem #7
    int size(void) const;                                         // Problem #8
    friend ostream& operator<<(                                   // Problem #9
        ostream&,
        const mwCircularLinkedList&
    );
    void reverseList(void);                                       // Problem #10
    mwCircularLinkedList mergeLists(                              // Problem #11
        mwCircularLinkedList&,
        mwCircularLinkedList&
    );

    bool exceptionIsSorted(string) const;                         // Exception Check: Unsorted List
    bool exceptionIsEmpty(string) const;                          // Exception check: Empty List
    bool exceptionOutOfBound(string, int) const;                  // Exception check: Out of Bound Position

private:
    mwSinglyDoubleNode* head;                                     // Member Variable
    int LLsize;                                                   // Member Variable

};

#endif // MWCIRCULARLINKEDLIST
