/*******************************************
 * This cpp file provides definitions for  *
 * the mwDoubleLinkedList class' methods   *
 *******************************************/

#include "mwDoubleLinkedList.h"

mwDoubleLinkedList::mwDoubleLinkedList():head(0), tail(0), LLsize(0) {} // Default Constructor

mwDoubleLinkedList::mwDoubleLinkedList(const mwDoubleLinkedList& base) { // Copy Constructor
    head = base.head;          // Copy Default Value
    tail = base.tail;          // Copy Default Value
    LLsize = base.LLsize;      // Copy Default Value
    mwDoublyIntNode* thisWalk; // Initialize thisWalk
    mwDoublyIntNode* baseWalk; // Initialize baseWalk
    if (base.head != 0) { // If base LinkedList isn't empty, then start copying the nodes
        baseWalk = base.head;
        head = new mwDoublyIntNode(baseWalk->data); // Copy the first node
        thisWalk = head;
        for (baseWalk = baseWalk->next; baseWalk != NULL; baseWalk = baseWalk->next) { // Iterate baseWalk
            thisWalk->next = new mwDoublyIntNode(baseWalk->data); // Copy the next node
            thisWalk->next->prev = thisWalk; // Link the next node with the thisWalk node
            thisWalk = thisWalk->next; // Iterate thisWalk
        }
        tail = thisWalk;      // Reassign tail
        tail->next = NULL; // Default link value
        head->prev = NULL; // Default link value
    }
}

mwDoubleLinkedList::~mwDoubleLinkedList() { // Destruct the LinkedList
    while (LLsize > 0) // If size is larger than one, then pop front until LLsize is 0
        popFront();
    // By this point, the LinkedList should be empty
    head = 0; // Assign head to zero
    tail = 0; // Assign tail to zero
}

mwDoubleLinkedList& mwDoubleLinkedList::operator=(const mwDoubleLinkedList& base) { // Assignment Operator Overload
    if (head != 0) { // Empty nodes if nodes exist
        for (mwDoublyIntNode* temp = head->next->next; LLsize-- > 1; temp = temp->next) { // Iterate temp
            delete head->next;
            head->next = temp;
        }
        // By this point, head is the last node
        delete head; // Delete head
    }
    LLsize = base.LLsize; // Assign size, and then assign new nodes
    mwDoublyIntNode* thisWalk;
    mwDoublyIntNode* baseWalk;
    if (base.head != 0) { // If base LinkedList isn't empty, then start copying the nodes
        baseWalk = base.head;
        head = new mwDoublyIntNode(baseWalk->data); // Copy the first node
        thisWalk = head;
        for (baseWalk = baseWalk->next; baseWalk != NULL; baseWalk = baseWalk->next) { // Iterate baseWalk
            thisWalk->next = new mwDoublyIntNode(baseWalk->data); // Copy the next node
            thisWalk->next->prev = thisWalk; // Link the next node with the thisWalk node
            thisWalk = thisWalk->next; // Iterate thisWalk
        }
        tail = thisWalk;      // Reassign tail
        tail->next = NULL; // Default link value
        head->prev = NULL; // Default link value
    }
    return *this;
}

void mwDoubleLinkedList::pushFront(int d) {
    if (LLsize == 0) { // If List is empty, then assign the new Node as the head
        head = new mwDoublyIntNode(d);
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    } else { // Else connect the head Node with the new Node, then assign the new Node as the head
        mwDoublyIntNode* temp = new mwDoublyIntNode(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = NULL;
    }
    LLsize++; // Increment the size by one
}

void mwDoubleLinkedList::pushBack(int d) { // Push a new Node to the back of the list
    if (LLsize == 0) { // If List is empty, then assign the new Node as the head
        head = new mwDoublyIntNode(d);
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    } else { // Else connect the tail Node with the new Node, update the tail
        tail->next = new mwDoublyIntNode(d);
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
    LLsize++; // Increment the size by one
}

void mwDoubleLinkedList::popFront() { // Pop the head Node of the list
    if (exceptionIsEmpty("popFront()")) { // Exception check if the list is empty
        return;
    } else if (LLsize == 1) { // If the list size is one, then pop the head
        delete head;
        head = 0;
        tail = 0;
    } else { // Else store the next node at temp, delete head, assign temp as the new head
        mwDoublyIntNode* temp = head->next;
        delete head;
        head = temp;
        temp->prev = NULL;
    }
    LLsize--; // Decrement the size by one
}

void mwDoubleLinkedList::popBack() { // Pop the last Node of the list
    if (exceptionIsEmpty("popBack()")) { // Exception check if the list is empty
        return;
    } else if (LLsize == 1) { // If the list size is one, then pop the head
        delete head;
        head = 0;
        tail = 0;
    } else { // Else store tail prev, pop the tail, then reassign the tail
        mwDoublyIntNode* temp = tail->prev;
        delete tail;
        temp->next = NULL;
        tail = temp;
    }
    LLsize--; // Decrement the size by one
}

void mwDoubleLinkedList::insert(int p, int d) { // Insert a new data to a certain position
    if (exceptionOutOfBound("insert(int, double)", p)) { // Exception check if the position is out of bound
        return;
    } else if (p == 0) { // If the position is zero, then pushFront the new data
        pushFront(d);
    } else if (p == LLsize) {
        pushBack(d);
    } else { // Else walk through the previous position of the desired position, then insert the new data
        mwDoublyIntNode* thisWalk = head;
        for (int i = 2; i++ <= p; thisWalk = thisWalk->next);
        mwDoublyIntNode* insert = new mwDoublyIntNode(d);
        insert->next = thisWalk->next;
        thisWalk->next->prev = insert;
        thisWalk->next = insert;
        insert->prev = thisWalk;
        LLsize++; // Increment the size by one
    }
}

void mwDoubleLinkedList::deleteDuplicates(int d) { // Delete nodes with a certain data value
    if (!exceptionIsEmpty("deleteDuplicates(double)")) { // Exception check if the list is empty
        mwDoublyIntNode* dump;
        mwDoublyIntNode* thisWalk = head;
        for (int i = 0; i < 1; thisWalk = head) { // If the head is the target, delete the head until the head is not the target
            if (thisWalk->data == d) {
                popFront(); // pop
            } else {
                i++; // break
            }
        }
        while (thisWalk->next != head) { // Walk from the second node to the last node, and delete any node with the desired data value
            if (thisWalk->next->data == d) { // If the node contains the desired data, delete the node
                dump = thisWalk->next;
                thisWalk->next = dump->next;
                if (thisWalk->next != NULL) // Safety measurement to avoid calling NULL->prev
                    thisWalk->next->prev = thisWalk;
                if (tail == dump) // Update tail if tail node is about to be deleted
                    tail = dump->prev;
                delete dump;
                LLsize--;
            } else { // Else continue walking through the list
                thisWalk = thisWalk->next;
            }
        }
    }
}

int mwDoubleLinkedList::mtoLastElement(int p) const { // Get the data on mth position from the last element
    mwDoublyIntNode* r;
    if (!exceptionIsEmpty("mtoLastElement(int)") && !exceptionOutOfBound("mtoLastElement(int)", p)) { // Exception check if the list is empty or the position is out of bound
        for (r = tail; p++ < (LLsize - 1); r = r->prev); // Walk through the node until the desired position
        return r->data; // return the data of the desired position
    }
    return 0;
}

int mwDoubleLinkedList::size() const { // Return the size of the list
    return LLsize;
}

ostream& operator<<(ostream& os, const mwDoubleLinkedList& base) { // ostream operator overloading
    if (base.LLsize != 0) { // If list is not empty
        os << "NULL \u2190 ";
        os << base.head->data << " \u21cc "; // Print the head node
        for (mwDoublyIntNode* baseWalk = base.head->next; baseWalk != NULL; baseWalk = baseWalk->next)
            os << baseWalk->data << " \u21cc "; // Print the next nodes
        os << "\b\b\u2192 NULL" << endl; // Print the last node
    } else {
        os << "Empty Linked List\n";
    }
    return os;
}

void mwDoubleLinkedList::reverseList() { // Reverse the node positions of the list
    if (LLsize > 1) { // If the LinkedList size is larger than one, then perform the reversal, else do nothing
        mwDoublyIntNode* thisWalkPrev = head;
        mwDoublyIntNode* thisWalk = thisWalkPrev->next;
        mwDoublyIntNode* thisWalkNext = thisWalk->next;
        for (int i = LLsize - 1; i > 0; i--) { // reverse the linked of walk with walkPrev (size - 1) times
            thisWalkPrev->next = thisWalkPrev->prev;
            thisWalkPrev->prev = thisWalk;
            thisWalk->next = thisWalkPrev;
            thisWalk->prev = thisWalkNext;
            if (i - 2 > 0) { // iterate the walks (size - 2) times
                thisWalkPrev = thisWalk;
                thisWalk = thisWalkNext;
                thisWalkNext = thisWalkNext->next;
            }
        }
        tail = head;
        head = thisWalk;
    }
}

mwDoubleLinkedList mwDoubleLinkedList::mergeLists(mwDoubleLinkedList& b1, mwDoubleLinkedList& b2) { // Merge two sorted linked lists
    mwDoubleLinkedList r; // Declare Return Variable
    mwDoublyIntNode* b1Walk = b1.head;
    mwDoublyIntNode* b2Walk = b2.head;
    if (b1.exceptionIsSorted("mergeLists()") || b2.exceptionIsEmpty("mergeLists()")) // Exit if LinkedLists aren't sorted
        return r;
    for (int i = b1.LLsize + b2.LLsize; i > 0; i--) { // Iterate until the desired size
        if (b1Walk == NULL) { // If list one is empty, then push and iterate list two
            r.pushBack(b2Walk->data);
            b2Walk = b2Walk->next;
        } else if (b2Walk == NULL) { // If list two is empty, then push and iterate list one
            r.pushBack(b1Walk->data);
            b1Walk = b1Walk->next;
        } else if (b1Walk->data < b2Walk->data) { // If list one node data is smaller than list two node data, then push and iterate list one
            r.pushBack(b1Walk->data);
            b1Walk = b1Walk->next;
        } else { // Else push and iterate list two
            r.pushBack(b2Walk->data);
            b2Walk = b2Walk->next;
        }
    }
    return r;
}

bool mwDoubleLinkedList::exceptionIsSorted(string fncHeader) const { // Exception check if the list is sorted
    for (mwDoublyIntNode* thisWalk = head; thisWalk->next != NULL; thisWalk = thisWalk->next) // Walk through the end of the list
        if (thisWalk->data > thisWalk->next->data) { // If the node data is larger than the next node data, then the list is not sorted
            cout << "Error: mwDoubleLinkedList::"<< fncHeader << ":LinkedList is unsorted\n";
            return true;
        }
    return false;
}

bool mwDoubleLinkedList::exceptionIsEmpty(string fncHeader) const { // Exception check if the list is empty
    if (LLsize == 0) { // If list size is zero, then the node is empty
        cout << "Error: mwDoubleLinkedList::" << fncHeader << ": LinkedList is empty\n";
        return true;
    } else {
        return false;
    }
}

bool mwDoubleLinkedList::exceptionOutOfBound(string fncHeader, int p) const  { // Exception check if the position is out of bound
    if ((p > LLsize) || p < 0) { // If the position is smaller than 0 or larger than the size of the list, then the position is out of bound
        cout << "Error: mwDoubleLinkedList::" << fncHeader << ": out-of-bound element position\n";
        return true;
    } else {
        return false;
    }
}
