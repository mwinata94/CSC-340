/*************************************
 * This cpp file defines the methods *
 *    declared in the header file    *
 *************************************/

#include <typeinfo>   // Standard Library
#include "mwMenuLL.h" // Header File

template<class T>
menuLL<T>::menuLL() { // Default Constructor
    templateClassName = typeid(T).name(); // Set typeid name as template class name
    size_t pos = templateClassName.find("mw") + 2;
    templateClassName = templateClassName.substr(pos); // substring the typeid name to remove extra chars
    hi = "Running " + templateClassName + "Menu\n";
    description =
        "\n*******************************\n"
        "*                             *\n"
        "   " + templateClassName + " MENU   \n"
        "*                             *\n"
        "*  1.Create A List            *\n"
        "*  2.Update A List            *\n"
        "*  3.Delete A List            *\n"
        "*  4.Print A List             *\n"
        "*  5.Print All Lists          *\n"
        "*  6.Return to Main Menu      *\n"
        "*                             *\n"
        "*******************************\n"
        "Choose an option: ";
    farewell = "\nReturning to Main Menu\n";
}

template<class T>
menuLL<T>::~menuLL() {} // Mandatory destructor due to the use of virtual

template<class T>
bool menuLL<T>::runAnOption(string option) { // Return True or False Depending on Option Value
    if (option == "1") { // Run Path 1
        menuCreateLL();
    } else if (option == "2") { // Run Path 2
        menuUpdateLL();
    } else if (option == "3") { // Run Path 3
        menuDeleteLL();
    } else if (option == "4") { // Run Path 4
        menuPrintLL();
    } else if (option == "5") { // Run Path 5
        menuPrintAll();
    } else if (option == "6") { // Return to Main Menu
        return false;
    } else { // Default Path
        cout << endl << "Option is not listed, please choose a different option" << endl;
    }
    return true;
}

template<class T>
void menuLL<T>::menuCreateLL() { // Create a LinkedList
    string option;
    cout <<
        "\n    ***************************\n"
        "    * Create A LinkedList By: *\n"
        "    * 1. Default              *\n"
        "    * 2. Copy                 *\n"
        "    * 3. Merge                *\n"
        "    ***************************\n"
        "    Enter an Option:";
    getline(cin, option);
    if (option == "1") { // Run Path 1
        menuCreateLLByDefault();
    } else if (option == "2") { // Run Path 2
        menuCreateLLByCopy();
    } else if (option == "3") { // Run Path 3
        menuCreateLLByMerge();
    } else { // Default Path
        cout << endl << "Option is not listed" << endl;
    }
}

template<class T>
void menuLL<T>::menuCreateLLByDefault() { // Create a LinkedList By Default Constructor (Big-3)
    T t; // Default Construction
    ll.push_back(t); // Push LinkedList into the Vector
    cout << "Default construction is done.\n";
}

template<class T>
void menuLL<T>::menuCreateLLByCopy() { // Create a LinkedList By Copy Constructor (Big-3)
    string input;
    int i;
    int llsize = ll.size();
    if (ll.size() < 1) {
        cout << "There is no LinkedList to be copied.\n";
    } else {
        menuPrintAll();
        cout << "Choose a LinkedList to be copied: ";
        getline(cin, input);
        try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        if (i < 0 || i >= llsize) {
            cout << "Element is out of bound.\n";
        } else {
            T t(ll.at(i));
            ll.push_back(t);
            cout << "Copy construction is done.\n";
        }
    }
}

template<class T>
void menuLL<T>::menuCreateLLByMerge() { // Create a LinkedList By Merging two sorted LinkedList (Test #11)
    string input;
    int i, j;
    int llsize = ll.size();
    if (ll.size() < 2) {
        cout << "There is not enough LinkedList to be merged.\n";
    } else {
        menuPrintAll();
        cout << "Choose the first base linkedlist: ";
        getline(cin, input);
        try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        cout << "Choose the second base linkedlist: ";
        getline(cin, input);
        try {j = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        if (i < 0 || i >= llsize || j < 0 || j >= llsize) {
            cout << "Element is out of bound.\n";
        } else {
            T t(ll.at(i).mergeLists(ll.at(i), ll.at(j)));
            ll.push_back(t);
            cout << "Merged list is done.\n";
        }
    }
}

template<class T>
void menuLL<T>::menuUpdateLL() { // Update a LinkedList
    string option;
    int llsize = ll.size();
    if (llsize < 1) {
        cout << "There is no LinkedList to be updated.\n";
        return;
    }
    cout <<
        "\n    ***************************\n"
        "    * Update A LinkedList By: *\n"
        "    * 1. PushFront            *\n"
        "    * 2. PushBack             *\n"
        "    * 3. PopFront             *\n"
        "    * 4. PopBack              *\n"
        "    * 5. Insert               *\n"
        "    * 6. Delete Duplicate     *\n"
        "    * 7. Reverse              *\n"
        "    ***************************\n"
        "    Enter an Option:";
    getline(cin, option);
    if (option == "1") { // Run Path 1
        menuUpdateLLByPushFront();
    } else if (option == "2") { // Run Path 2
        menuUpdateLLByPushBack();
    } else if (option == "3") { // Run Path 3
        menuUpdateLLByPopFront();
    } else if (option == "4") { // Run Path 4
        menuUpdateLLByPopBack();
    } else if (option == "5") { // Run Path 5
        menuUpdateLLByInsert();
    } else if (option == "6") { // Run Path 6
        menuUpdateLLByDltDup();
    } else if (option == "7") { // Run Path 7
        menuUpdateLLByReverse();
    } else { // Default Path
        cout << endl << "Option is not listed" << endl;
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByPushFront() { // Update a LinkedList By Push Front (Test #1)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        double data;
        cout << "Enter a data to be pushed: ";
        getline(cin, input);
        try {data = stod(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        ll.at(i).pushFront(data);
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByPushBack() { // Update a LinkedList By Push Back (Test #2)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        double data;
        cout << "Enter a data to be pushed: ";
        getline(cin, input);
        try {data = stod(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        ll.at(i).pushBack(data);
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByPopFront() { // Update a LinkedList By Pop Front (Test #3)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        ll.at(i).popFront();
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByPopBack() { // Update a LinkedList By Pop Back (Test #4)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        ll.at(i).popBack();
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByInsert() { // Update a LinkedList By Insert (Test #5)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        int p;
        double data;
        cout << "Enter the insert position: ";
        getline(cin, input);
        try {p = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        cout << "Enter the data: ";
        getline(cin, input);
        try {data = stod(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        ll.at(i).insert(p, data);
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByDltDup() { // Update a LinkedList By Delete Duplicates (Test #6)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        double data;
        cout << "Enter data duplicate: ";
        getline(cin, input);
        try {data = stod(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        ll.at(i).deleteDuplicates(data);
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuUpdateLLByReverse() { // Update a LinkedList By Reverse (Test #10)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        ll.at(i).reverseList();
        cout << "Update is done.\n";
    }
}

template<class T>
void menuLL<T>::menuDeleteLL() { // Delete a LinkedList (Big-3)
    string input;
    int llsize = ll.size();
    if (llsize < 1) {
        cout << "There is no linkedlist to be deleted.\n";
        return;
    }
    int i;
    menuPrintAll();
    cout << "Choose a LinkedList to be deleted: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        ll.erase(ll.begin() + i);
        cout << "Deletion is done.\n";
    }
}

template<class T>
void menuLL<T>::menuPrintLL() { // Print a LinkedList
    string option;
    int llsize = ll.size();
    if (llsize < 1) {
        cout << "There is no LinkedList to be updated.\n";
        return;
    }
    cout <<
        "\n    ***************************\n"
        "    * Print LinkedList By:    *\n"
        "    * 1. mthToLast            *\n"
        "    * 2. size                 *\n"
        "    * 3. whole                *\n"
        "    ***************************\n"
        "    Enter an Option:";
    getline(cin, option);
    if (option == "1") { // Run Path 1
        menuPrintLLMthFromLast();
    } else if (option == "2") { // Run Path 2
        menuPrintLLSize();
    } else if (option == "3") { // Run Path 3
        menuPrintLLWhole();
    } else { // Run Default Path
        cout << "Option is not listed.\n";
    }
}

template<class T>
void menuLL<T>::menuPrintLLMthFromLast() { // Print a LinkedList mth from last (Test #7)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be printed: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        int p;
        cout << "Enter the position: ";
        getline(cin, input);
        try {p = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
        cout << "Data at position " << p << ": " << ll.at(i).mtoLastElement(p) << endl;
    }
}

template<class T>
void menuLL<T>::menuPrintLLSize() { // Print a LinkedList size (Test #8)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be printed: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        cout << "size: " << ll.at(i).size() << endl;
    }
}

template<class T>
void menuLL<T>::menuPrintLLWhole() { // Print a LinkedList whole (Test #9)
    string input;
    int i;
    int llsize = ll.size();
    menuPrintAll();
    cout << "Choose a LinkedList to be printed: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "Invalid Input.\n"; return;}
    if (i < 0 || i >= llsize) {
        cout << "Element is out of bound.\n";
    } else {
        cout << "LinkedList: " << ll.at(i) << endl;
    }
}

template<class T>
void menuLL<T>::menuPrintAll() { // Print all LinkedList
    cout << "Listing all LinkedList:\n";
    int llsize = ll.size();
    for (int i = 0; i < llsize; i++)
        cout << i << ": " << ll.at(i);
    cout << endl;
}
