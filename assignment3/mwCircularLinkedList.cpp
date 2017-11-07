/*******************************************
 * This cpp file provides definitions for  *
 * the mwCircularLinkedList class' methods *
 *******************************************/

#include "mwCircularLinkedList.h"

mwCircularLinkedList::mwCircularLinkedList():head(0), LLsize(0) {} // Default Constructor

mwCircularLinkedList::mwCircularLinkedList(const mwCircularLinkedList& base) { // Copy Constructor
    head = base.head;              // Copy Default Value
    LLsize = base.LLsize;          // Copy Default Value
    mwSinglyDoubleNode* thisWalk;  // Initialize thisWalk
    mwSinglyDoubleNode* baseWalk;  // Initialize baseWalk
    if (base.head != 0) { // If base LinkedList isn't empty, then start copying the nodes
        baseWalk = base.head;
        head = new mwSinglyDoubleNode(baseWalk->data); // Copy the first node
        thisWalk = head;
        for (baseWalk = baseWalk->next; baseWalk != base.head; baseWalk = baseWalk->next) { // Iterate the baseWalk
            thisWalk->next = new mwSinglyDoubleNode(baseWalk->data); // Copy the next node
            thisWalk = thisWalk->next; // Iterate the thisWalk
        }
        thisWalk->next = head; // Linked the last node to the head
    }
}

mwCircularLinkedList::~mwCircularLinkedList() { // Destruct the LinkedList
    if (LLsize > 1) // If size is larger than one, then delete and reassign  index one until size is no longer larger than one
        for (mwSinglyDoubleNode* temp = head->next->next; LLsize-- > 1; temp = temp->next) {
            delete head->next;
            head->next = temp;
        }
    // By this point, head is either a nullptr or pointing to head itself
    delete head; // Delete head
    head = 0; // Assign head to zero
}

mwCircularLinkedList& mwCircularLinkedList::operator=(const mwCircularLinkedList& base) { // Assignment Operator Overloading
    if (head != 0) { // Empty Nodes if Node exists
        for (mwSinglyDoubleNode* temp = head->next->next; LLsize-- > 1; temp = temp->next) { // Iterate temp as next of next
            delete head->next; // Delete the next node
            head->next = temp; // Link temp as the next node
        }
        // By this point head is pointing to head itself
        delete head; // Delete head
    }
    LLsize = base.LLsize; // Assign new size, and then assign new nodes
    mwSinglyDoubleNode* thisWalk;
    mwSinglyDoubleNode* baseWalk;
    if (base.head != 0) { // If base LinkedList isn't empty, then start copying the nodes
        baseWalk = base.head;
        head = new mwSinglyDoubleNode(baseWalk->data); // Copy the first node
        thisWalk = head;
        for (baseWalk = baseWalk->next; baseWalk != base.head; baseWalk = baseWalk->next) { // Iterate the baseWalk
            thisWalk->next = new mwSinglyDoubleNode(baseWalk->data); // Copy the next node
            thisWalk = thisWalk->next; // Iterate the thisWalk
        }
        thisWalk->next = head;
    }
    return *this;
}

void mwCircularLinkedList::pushFront(double d) { // Push a new Node to the front of the List
    if (LLsize == 0) { // If List is empty, then assign the new Node as the head
        head = new mwSinglyDoubleNode(d);
        head->next = head;
    } else { // Else connect the head Node and the last Node with the new Node, then assign the new Node as the head
        mwSinglyDoubleNode* thisWalk;
        for(thisWalk = head; thisWalk->next != head; thisWalk = thisWalk->next);
        thisWalk->next = new mwSinglyDoubleNode(d);
        thisWalk->next->next = head;
        head = thisWalk->next;
    }
    LLsize++; // Increment the size by one
}

void mwCircularLinkedList::pushBack(double d) { // Push a new Node to the back of the list
    if (LLsize == 0) { // If List is empty, then assign the new Node as the head
        head = new mwSinglyDoubleNode(d);
        head->next = head;
    } else { // Else connect the head Node and the last Node with the new Node
        mwSinglyDoubleNode* thisWalk;
        for (thisWalk = head; thisWalk->next != head; thisWalk = thisWalk->next);
        thisWalk->next = new mwSinglyDoubleNode(d);
        thisWalk->next->next = head;
    }
    LLsize++; // Increment the size by one
}

void mwCircularLinkedList::popFront() { // Pop the head Node of the list
    if (exceptionIsEmpty("popFront()")) { // Exception check if the list is empty
        return;
    } else if (LLsize == 1) { // If the list size is one, then pop the head
        delete head;
        head = 0;
    } else { // Else walk through the last Node, pop the head, then reassign the head
        mwSinglyDoubleNode* dump = head;
        mwSinglyDoubleNode* thisWalk;
        for (thisWalk = head->next; thisWalk->next != head; thisWalk = thisWalk->next);
        head = head->next;
        thisWalk->next = head;
        delete dump;
    }
    LLsize--; // Decrement the size by one
}

void mwCircularLinkedList::popBack() { // Pop the last Node of the list
    if (exceptionIsEmpty("popBack()")) { // Exception check if the list is empty
        return;
    } else if (LLsize == 1) { // If the list size is one, then pop the head
        delete head;
        head = 0;
    } else { // Else walk through the second last Node, then pop the last Node
        mwSinglyDoubleNode* dump;
        mwSinglyDoubleNode* thisWalk;
        for (thisWalk = head; thisWalk->next->next != head; thisWalk = thisWalk->next);
        dump = thisWalk->next;
        thisWalk->next = head;
        delete dump;
    }
    LLsize--; // Decrement the size by one
}

void mwCircularLinkedList::insert(int p, double d) { // Insert a new data to a certain position
    if (exceptionOutOfBound("insert(int, double)", p)) { // Exception check if the position is out of bound
        return;
    } else if (p == 0) { // If the position is zero, then pushFront the new data
        pushFront(d);
    } else if (p == LLsize) {
        pushBack(d);
    } else { // Else walk through the previous position of the desired position, then insert the new data
        mwSinglyDoubleNode* thisWalk = head;
        for (int i = 2; i++ <= p; thisWalk = thisWalk->next);
        mwSinglyDoubleNode* insert = new mwSinglyDoubleNode(d);
        insert->next = thisWalk->next;
        thisWalk->next = insert;
        LLsize++; // Increment the size by one
    }
}

void mwCircularLinkedList::deleteDuplicates(double d) { // Delete nodes with a certain data value
    if (!exceptionIsEmpty("deleteDuplicates(double)")) { // Exception check if the list is empty
        mwSinglyDoubleNode* dump;
        mwSinglyDoubleNode* thisWalk = head;
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
                delete dump;
                LLsize--;
            } else { // Else continue walking through the list
                thisWalk = thisWalk->next;
            }
        }
    }
}

double mwCircularLinkedList::mtoLastElement(int p) const { // Get the data on mth position from the last element
    mwSinglyDoubleNode* r = head;
    if (!exceptionIsEmpty("mtoLastElement(int)") && !exceptionOutOfBound("mtoLastElement(int)", p)) { // Exception check if the list is empty or the position is out of bound
        for (r = head; p-- != 0; r = r->next); // Walk through the node until the desired position
        return r->data; // return the data of the desired position
    }
    return 0;
}

int mwCircularLinkedList::size() const { // Return the size of the list
    return LLsize;
}

ostream& operator<<(ostream& os, const mwCircularLinkedList& base) { // ostream operator overloading
    if (base.LLsize != 0) { // If list is not empty
        os << base.head->data << " -> "; // Print the head node
        for (mwSinglyDoubleNode* baseWalk = base.head->next; baseWalk != base.head; baseWalk = baseWalk->next)
            os << baseWalk->data << " -> "; // Print the next nodes
        os << base.head->data << endl; // Print the last node
    } else {
        os << "Empty Linked List\n";
    }
    return os;
}

void mwCircularLinkedList::reverseList() { // Reverse the node positions of the list
    if (LLsize > 1) { // If the LinkedList size is larger than one, then perform the reversal, else do nothing
        mwSinglyDoubleNode* thisWalkPrev = head;
        mwSinglyDoubleNode* thisWalk = thisWalkPrev->next;
        mwSinglyDoubleNode* thisWalkNext = thisWalk->next;
        for (int i = LLsize; i > 0; i--) { // reverse the linked of walk with walkPrev (size) times
            thisWalk->next = thisWalkPrev;
            if (i - 1 > 0) { // iterate the walks (size - 1) times
                thisWalkPrev = thisWalk;
                thisWalk = thisWalkNext;
                thisWalkNext = thisWalkNext->next;
            }
        }
        head = thisWalkPrev; // reassign head
    }
}

mwCircularLinkedList mwCircularLinkedList::mergeLists(mwCircularLinkedList& b1, mwCircularLinkedList& b2) { // Merge two sorted linked lists
    mwCircularLinkedList r; // Declare Return Variable
    mwSinglyDoubleNode* b1Walk = b1.head;
    mwSinglyDoubleNode* b2Walk = b2.head;
    if (b1.exceptionIsSorted("mergeLists()") || b2.exceptionIsEmpty("mergeLists()")) // Exit if LinkedLists aren't sorted
        return r;
    int ll_s = b1.LLsize + b2.LLsize; // store the desired size
    for (int i(0), m(0), n(0); i < ll_s; i++) { // iterate until the desired size
        if (b1.LLsize == 0 || b1.LLsize == m) { // If list one is empty or iterated through, then push and iterate list two
            r.pushBack(b2Walk->data);
            b2Walk = b2Walk->next;
        } else if (b2.LLsize == 0 || b2.LLsize == n) { // If list two is empty or iterated through, then push and iterate list one
            r.pushBack(b1Walk->data);
            b1Walk = b1Walk->next;
        } else if (b1Walk->data < b2Walk->data) { // If list one node data is smaller than list two node data, then push and iterate list one data
            r.pushBack(b1Walk->data);
            b1Walk = b1Walk->next;
            m++;
        } else { // Else push and iterate list two data
            r.pushBack(b2Walk->data);
            b2Walk = b2Walk->next;
            n++;
        }
    }
    return r;
}

bool mwCircularLinkedList::exceptionIsSorted(string fncHeader) const { // Exception check if the list is sorted
    for (mwSinglyDoubleNode* thisWalk = head; thisWalk->next != head; thisWalk = thisWalk->next) // Walk through the end of the list
        if (thisWalk->data > thisWalk->next->data) { // If the node data is larger than the next node data, then the list is not sorted
            cout << "Error: mwCircularLinkedList::"<< fncHeader << ":LinkedList is unsorted\n";
            return true;
        }
    return false;
}

bool mwCircularLinkedList::exceptionIsEmpty(string fncHeader) const { // Exception check if the list is empty
    if (LLsize == 0) { // If list size is zero, then the node is empty
        cout << "Error: mwCircularLinkedList::" << fncHeader << ": LinkedList is empty\n";
        return true;
    } else {
        return false;
    }
}

bool mwCircularLinkedList::exceptionOutOfBound(string fncHeader, int p) const  { // Exception check if the position is out of bound
    if ((p > LLsize) || p < 0) { // If the position is smaller than 0 or larger than the size of the list, then the position is out of bound
        cout << "Error: mwCircularLinkedList::" << fncHeader << ": out-of-bound element position\n";
        return true;
    } else {
        return false;
    }
}
