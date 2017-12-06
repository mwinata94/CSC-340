/*****************************************************
 *  This header file contains the menu class, which  *
 *    provides interactive User Interface to test    *
 *        Vector_double Class Functionality          *
 *****************************************************/

#ifndef MWMENU
#define MWMENU

#include <iostream>                          // Standard Library
#include <string>                            // Standard Library
#include <vector>                            // Standard Library

#include "Vector_double.h"                   // Custom Library

using namespace std;                         // Standard Namespace

class menu {                                 // Class Name

public:
    menu(void);                              // Default Constructor
    virtual ~menu(void);                     // Mandatory destructor due to the use of virtual
    void run(void);                          // Run the Menu
    void sayHi(void);                        // Cout Intro
    void describeSelf(void);                 // Cout Description
    void sayFarewell(void);                  // Cout Outro
    virtual bool runAnOption(string);        // Run the Menu Option

    void menuCreateVector(void);             // Create A Vector
    void menuCreateVectorByDefault(void);    // Create a Vector By Default Constructor
    void menuCreateVectorByCopy(void);       // Create a Vector By Copy Constructor (Big-3)

    void menuUpdateVector(void);             // Update A Vector
    void menuUpdateVectorByAssignment(void); // Update A Vector By Assignment Operator (Big-3)
    void menuUpdateVectorByPopBack(void);    // Update A Vector By Pop Back
    void menuUpdateVectorByPushBack(void);   // Update A Vector By Push Back
    void menuUpdateVectorInsert(void);       // Update A Vector By Insert
    void menuUpdateVectorResize(void);       // Update A Vector By Resize
    void menuUpdateVectorShrinkToFit(void);  // Update A Vector By ShrinkToFit

    void menuDeleteVector(void);             // Delete A Vector

    void menuPrintVector(void);              // Print A Vector
    void menuPrintVectorSize(void);          // Print A Vector Size
    void menuPrintVectorElements(void);      // Print A Vector Elements
    void menuPrintVectorStats(void);         // Print A Vector Stats
    void menuPrintVectorAll(void);           // Print All Vectors

protected:
    string hi;                               // Member Variable: Store Intro
    string description;                      // Member Variable: Store Description
    string farewell;                         // Member Variable: Store Outro

private:
    vector <Vector_double> v_list;           // Member Variable: Vectors of Vector_double

};

#endif // MWMENU

