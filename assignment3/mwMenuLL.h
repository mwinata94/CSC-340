/*************************************************
 * This header file contains a sub menu template *
 * for the user to test a LinkedList Model       *
 *************************************************/

#ifndef MWMENULL
#define MWMENULL

#include <vector>                       // Standard Library
#include "mwMenu.h"                     // Custom Library - Parent Class

using namespace std;                    // Standard Namespace

template<class T>
class menuLL : virtual public menu {    // Class Name : Parent Class

public:
    menuLL(void);                       // Default Constructor
    ~menuLL(void);                      // Mandatory destructor due to the use of virtual
    bool runAnOption(string);           // Run the Menu Option

    void menuCreateLL(void);            // Create a LinkedList
    void menuCreateLLByDefault(void);   // Create a LinkedList By Default Constructor (Big-3)
    void menuCreateLLByCopy(void);      // Create a LinkedList By Copy Constructor (Big-3)
    void menuCreateLLByMerge(void);     // Create a LinkedList By Merging two sorted LinkedList (Test #11)

    void menuUpdateLL(void);            // Update a LinkedList
    void menuUpdateLLByPushFront(void); // Update a LinkedList By Push Front (Test #1)
    void menuUpdateLLByPushBack(void);  // Update a LinkedList By Push Back (Test #2)
    void menuUpdateLLByPopFront(void);  // Update a LinkedList By Pop Front (Test #3)
    void menuUpdateLLByPopBack(void);   // Update a LinkedList By Pop Back (Test #4)
    void menuUpdateLLByInsert(void);    // Update a LinkedList By Insert (Test #5)
    void menuUpdateLLByDltDup(void);    // Update a LinkedList By Delete Duplicates (Test #6)
    void menuUpdateLLByReverse(void);   // Update a LinkedList By Reverse (Test #10)

    void menuDeleteLL(void);            // Delete a LinkedList (Big-3)

    void menuPrintLL(void);             // Print a LinkedList
    void menuPrintLLMthFromLast(void);  // Print a LinkedList mth from last (Test #7)
    void menuPrintLLSize(void);         // Print a LinkedList size (Test #8)
    void menuPrintLLWhole(void);        // Print a LinkedList whole (Test #9)

    void menuPrintAll(void);            // Print all LinkedList

protected:
    string templateClassName;           // Member Variable: Store Template Class Name
    vector<T> ll;                       // Member Variable: Store LinkedList

};

#endif // MWMENULL
