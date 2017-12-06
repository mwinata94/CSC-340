/******************************************
 * This cpp file provides definitions for *
 *       the Vector_double class          *
 ******************************************/

#include "Vector_double.h"

// Default Constructor
Vector_double::Vector_double() {
    v_size = 0;     // Default value for vector size
    v_size_cap = 0; // Default value for vector size capacity
    data = 0;       // Default value for data
}

// Big-3: Copy Constructor
Vector_double::Vector_double(const Vector_double& base) {
    v_size = base.v_size; // Copy size value
    v_size_cap = base.v_size_cap; // Copy size capacity value
    if (v_size == 0) { // If size is 0, then data is empty
        data = 0;
    } else { // Else initialize data
        data = new double[v_size_cap];
        for (int i = 0; i < v_size; i++) data[i] = base[i];
    }
}

// Big-3: Destructor
Vector_double::~Vector_double() {
    delete data; // deallocate data memory
    v_size = 0;  // assign empty value
    v_size_cap = 0; // assign empty value
    data = 0; // assign empty value
}

// Big-3: Overloaded Assignment Operator
Vector_double& Vector_double::operator=(const Vector_double& base) {
    delete data; // deallocate data memory
    v_size = base.v_size; // copy size value
    v_size_cap = base.v_size_cap; // copy size capacity value
    if (v_size == 0) { // If size is 0, then data is empty
        data = 0;
    } else { // Else initialize data
        data = new double[v_size_cap];
        for (int i = 0; i < v_size; i++) data[i] = base[i];
    }
    return *this; // return self
}

// Test If The Container Is Empty
bool Vector_double::empty() {
    return data == 0; // return whether data value is empty or not
}

// Insert An Element At A Specified Position
void Vector_double::insert(int n, double d) {
    if (n < 0 || n >= v_size) { // Check if index is available
        cout << "\nVector_double: insert: Error: out of bound index.\n";
    } else if (++v_size > v_size_cap) { // Check if size capacity needs to be updated
        v_size_cap *= 2; // update capacity by a multiple of two
        double* newData = new double[v_size_cap]; // create a new array
        for (int i = 0; i < n; i++) newData[i] = data[i]; // store old values before index n
        newData[n] = d; // store the new value
        for (int i = n + 1; i < v_size; i++) newData[i] = data[i - 1]; // store old values after index n
        delete data; // deallocate data memory
        data = newData; // assign new data memory
    } else {
        double* newData = new double[v_size - n]; // create a new array
        newData[0] = d; // store new value at index 0 of new array
        for (int i = n; i < v_size; i++) newData[i - n + 1] = data[i]; // store old values from index n until index v_size to the new array from index 1 to v_size - n
        for (int i = n; i < v_size; i++) data[i] = newData[i - n]; // store new values to data
    }
}

// Delete The Element At The End Of The Vector
void Vector_double::pop_back() {
    if (empty()) { // If data is empty, no need to pop_back
        cout << "\nVector_double: pop_back: Error: Container is empty.\n";
        return;
    } else {
        --v_size; // decrement size
        data[v_size] = 0; // assign empty value to the popped index
    }
}
// Add An Element To The End Of The Vector
void Vector_double::push_back(double d) {
    if (empty()) { // If data is empty, initialize data
        v_size++; // Increment size
        v_size_cap = v_size; // assign capacity
        data = new double[v_size_cap]; // allocate data memory
        data[0] = d; // assign push_back value
    } else if (++v_size > v_size_cap) { // If capacity needs to be updated
        v_size_cap *= 2; // Increase capacity by a multiple of two
        double* newData = new double[v_size_cap]; // allocate new data memory
        for (int i = 0; i < v_size - 1; i++) newData[i] = data[i]; // copy old values to new data
        newData[v_size - 1] = d; // assign push_back value
        delete data; // delete old data
        data = newData; // assign new data
    } else {
        data[v_size - 1] = d; // assign push_back value
    }
}

// Resize The Vector To A Specified Size
void Vector_double::resize(int s) {
    if (s > v_size_cap) { // If capacity needs to be updated
        v_size_cap = s; // Update capacity with the new value
        double* newData = new double[v_size_cap]; // Allocate new data memory
        for (int i = 0; i < v_size; i++) newData[i] = data[i]; // assign old data value to new data
        delete data; // delete old data
        data = newData; // assign new data
        v_size = s; // update size value
    } else if (s == v_size_cap) { // If nothing needs to be updated
        return;
    } else {
        for (int i = s; i < v_size; i++) data[i] = 0; // assign empty value to out of bound indexes
        v_size = s; // update size value
    }
}

// Discard Excess Capacity
void Vector_double::shrink_to_fit() {
    if (v_size < v_size_cap) { // if size is smaller than capacity, then shrink capacity
        v_size_cap = v_size; // update capacity value
        double* newData = new double[v_size_cap]; // allocate new data
        for (int i = 0; i < v_size; i++) newData[i] = data[i]; // assign old data value to new data
        delete data; // delete old data
        data = newData; // assign new data
    }
}

// Returns The Number Of Elements Stored In The Vector
int Vector_double::size() {
    return v_size; // return size
}

// Overloaded Output Operator
ostream& operator<<(ostream& os, Vector_double& v) {
    if (v.v_size == 0) { // If empty vector
        os << "Empty Vector" << endl;
    } else { // print all elements in an array form
        os << "[";
        for (int i = 0; i < v.v_size; i++) os << v[i] << ", ";
        os << "\b\b]" << endl;
    }
    return os;
}

// Overloaded Subscript Operator
double Vector_double::operator[](int n) const {
    if (n < 0 || n >= v_size) { // If index is out of bound
        cout << "\nVector_double: operator[]: Error: out of bound index.\n";
        return 0;
    } else { // Else return index value
        return data[n];
    }
}

// Print Container's Stats
void Vector_double::printStats() {
    cout
        << "-- Vector_double --\n"            // Title
        << "size: " << v_size << endl         // Size
        << "capacity: " << v_size_cap << endl // Capacity
        << "Values: " << *this;               // Element values
}

