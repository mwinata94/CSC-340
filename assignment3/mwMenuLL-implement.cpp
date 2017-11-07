/***************************
 * This cpp file serves as *
 * a forward declaration   *
 * for the class templates *
 ***************************/

#include "mwMenuLL.cpp"           // Base cpp file
#include "mwCircularLinkedList.h" // Class template 1
#include "mwDoubleLinkedList.h"   // Class template 2

template class menuLL<mwCircularLinkedList>; // Forward Declaration 1
template class menuLL<mwDoubleLinkedList>;   // Forward Declaration 2
