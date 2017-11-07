/******************************************
 * This cpp file provides definitions for *
 * the node constructors                  *
 ******************************************/

#include "mwLinkedListNode.h"

mwSinglyDoubleNode::mwSinglyDoubleNode(): data(0) {}         // Default Constructor: Set data to 0
mwSinglyDoubleNode::mwSinglyDoubleNode(double d): data(d) {} // Custom Constructor: Set data to parameter

mwDoublyIntNode::mwDoublyIntNode(): data(0) {}               // Default Constructor: Set data to 0
mwDoublyIntNode::mwDoublyIntNode(int d): data(d) {}          // Custom Constructor: Set data to parameter
