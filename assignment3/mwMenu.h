/*****************************************************
 *  This header file contains the menu class, which  *
 *    provides interactive User Interface to test    *
 *      CircularLinkedList and DoubleLinkedList      *
 *****************************************************/

#ifndef MWMENU
#define MWMENU

#include <iostream>                   // Standard Library
#include <string>                     // Standard Library

using namespace std;                  // Standard Namespace

class menu {                          // Class Name

public:
    menu(void);                       // Default Constructor
    virtual ~menu(void);              // Mandatory destructor due to the use of virtual
    void run(void);                   // Run the Menu
    void sayHi(void);                 // Cout Intro
    void describeSelf(void);          // Cout Description
    void sayFarewell(void);           // Cout Outro
    virtual bool runAnOption(string); // Run the Menu Option

protected:
    string hi;                        // Member Variable: Store Intro
    string description;               // Member Variable: Store Description
    string farewell;                  // Member Variable: Store Outro

};

#endif // MWMENU
