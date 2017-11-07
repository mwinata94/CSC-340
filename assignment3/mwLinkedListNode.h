/**********************************************
 * This header file provides the nodes for    *
 * each assigned LinkedList.                  *
 * Singly Node is for the Circular LinkedList *
 * Doubly Node is for the Double LinkedList   *
 **********************************************/

#ifndef MWLINKEDLISTNODE
#define MWLINKEDLISTNODE

struct mwSinglyDoubleNode {
    mwSinglyDoubleNode(void);    // Default Constructor
    mwSinglyDoubleNode(double);  // Custom Constructor

    double data;                 // Member Variable
    mwSinglyDoubleNode* next;    // Member Variable
};

struct mwDoublyIntNode {
    mwDoublyIntNode(void);       // Default Constructor
    mwDoublyIntNode(int);        // Custom Constructor

    int data;                    // Member Variable
    mwDoublyIntNode* next;       // Member Variable
    mwDoublyIntNode* prev;       // Member Variable
};

#endif // MWLINKEDLISTNODE
