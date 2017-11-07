Assignment 3

Author  : Michael Winata

Main    : MichaelWinataAssignment3.cpp

Compiler: GNU GCC Compiler [-std=C++11]


When the main is compiled, user will be presented with an interactive

user interface to test the functionality of two types of linked list,

circular linked list and double linked list.



This program is separated into 12 files (5 headers and 7 cpps).



The header files are as follow:



mwCircularLinkedList.h -> handles mwCircularLinkedList Declaration

                       :  the mwCircularLinkedList class contains the

                          design and functionality of a circular

                          linkedlist model



mwDoubleLinkedList.h   -> handles mwDoubleLinkedList Declaration

                       :  the mwDoubleLinkedList class contains the

                          design and functionality of a double

                          linkedlist model



mwLinkedListNode.h     -> handles LinkedList Node Declaration

                       :  the mwSinglyDoubleNode class serves as the

                          nodes for the mwCircularLinkedList, while

                          the mwDoublyIntNode class serves as the

                          nodes for the mwDoubeLinkedList



mwMenu.h               -> handles menu Declaration

                       :  the menu class contains the interactive

                          user interface for running tests



mwMenuLL.h             -> handles menuLL Declaration

                       :  the menuLL class is a child of menu;

                          the menuLL class contains the interactive

                          user interface for running tests on any

                          LinkedList model



The cpp files are as follow:



MichaelWinataAssignment3.cpp -> handles Main Definition

                             :  the main file creates a menu variable

                                and run said menu

mwCircularLinkedList.cpp     -> handles mwCircularLinkedList definition

                             :  the mwCircularLinkedList class contains

                                a mwSinglyDoubleNode pointer variable

                                to store the head of the List and

                                an integer variable to store the size

                                of the list



mwDoubleLinkedList.cpp       -> handles mwDoubleLinkedList definition

                             :  the mwDoubleLinkedList class contains

                                two mwDoublyIntNode pointers variable

                                to store the head and the tail of the

                                List and an integer variable to store

                                the size of the list



mwLinkedListNode.cpp         -> handles LinkedList Node definition

                             :  the mwSinglyDoubleNode class contains

                                a mwSinglyDoubleNode pointer to contain

                                the next address link and a double

                                variable to store a data;

                                the mwDoublyIntNode class contains

                                two mwDoublyIntNode pointers to contain

                                the next and the prev address link and

                                a double variable to store a data



mwMenu.cpp                   -> handles menu definition

                             :  the menu class contains three strings

                                to store the intro, description, and

                                outro of the menu



mwMenuLL.cpp                 -> handles menuLL definition

                             :  the menuLL class is defined with a

                                class template: menuLL<class T>



mwMenuLL-implementing.cpp    -> handles mwMenuLL forward declaration

                             :  declare the template for the

                                mwCircularLinkedList and

                                mwDoubleLinkedList class:

                                template class menuLL<LinkedList>

