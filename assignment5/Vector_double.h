/**********************************************
 * This header file provides the definition   *
 *          of Vector_double class            *
 **********************************************/

#ifndef VECTOR_DOUBLE_H
#define VECTOR_DOUBLE_H

#include <iostream>                                       // Standard Library

using namespace std;                                      // Standard Namespace

class Vector_double {                                     // Class Name
public:
    Vector_double(void);                                  // Default Constructor
    Vector_double(const Vector_double&);                  // Big-3: Copy Constructor

    ~Vector_double(void);                                 // Big-3: Destructor

    Vector_double& operator=(const Vector_double&);       // Big-3: Overloaded Assignment Operator

    bool empty(void);                                     // Test If The Container Is Empty

    void insert(int, double);                             // Insert An Element At A Specified Position

    void pop_back(void);                                  // Delete The Element At The End Of The Vector

    void push_back(double);                               // Add An Element To The End Of The Vector

    void resize(int);                                     // Resize The Vector To A Specified Size

    void shrink_to_fit(void);                             // Discard Excess Capacity

    int size(void);                                       // Returns The Number Of Elements Stored In The Vector

    friend ostream& operator<<(ostream&, Vector_double&); // Overloaded Output Operator

    double operator[](int) const;                         // Overloaded Subscript Operator

    void printStats(void);                                // Print Container's Stats

private:
    int v_size;                                           // Member Variable: Vector Size
    int v_size_cap;                                       // Member Variable: Vector Size Capacity
    double* data;                                         // Member Variable: Data
};

#endif // VECTOR_DOUBLE_H
