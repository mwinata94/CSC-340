/*************************************
 * This cpp file defines the methods *
 *    declared in the header file    *
 *************************************/

#include "mwMenu.h"               // Header File

menu::menu() { // Default Constructor
    hi = "Hi, welcome!\n"; // Assigning Intro
    description = //Assigning Description
        "\n*******************************\n"
        "*                             *\n"
        "*             MENU            *\n"
        "*                             *\n"
        "*  1. Create A Vector         *\n"
        "*  2. Update A Vector         *\n"
        "*  3. Delete A Vector         *\n"
        "*  4. Print  A Vector         *\n"
        "*  5. Exit                    *\n"
        "*                             *\n"
        "*******************************\n"
        "Choose an option: ";
    farewell = "\nHave a nice day!\n"; // Assigning Outro
}

menu::~menu() {} // Mandatory destructor due to the use of virtual

void menu::run() { // Run the Menu
    string option; // Declare the Option Variable
    sayHi(); // Cout Intro
    do {
        describeSelf(); // Cout Description
        getline(cin, option); // Store Option from User Input
    } while (runAnOption(option)); // Loop Until Desired Option
    sayFarewell(); // Cout Outro
}

void menu::sayHi() { // Cout Intro
    cout << endl << hi;
}

void menu::describeSelf() { // Cout Description
    cout << description;
}

void menu::sayFarewell() { // Cout Outro
    cout << endl << farewell << endl;
}

bool menu::runAnOption(string option) { // Return True or False Depending on Option Value
    if (option == "1") { // Run Path 1
        menuCreateVector();
    } else if (option == "2") { // Run Path 2
        menuUpdateVector();
    } else if (option == "3") { // Run Path 3
        menuDeleteVector();
    } else if (option == "4") { // Run Path 4
        menuPrintVector();
    } else if (option == "5") { // Exit Menu
        return false;
    } else { // Default Path
        cout << endl << "Option is not listed, please choose a different option" << endl;
    }
    return true; // At this point, cll and dll are delete to reduce memory space consumption
}

void menu::menuCreateVector() { // Create A Vector
    string option;
    cout <<
        "\n\t****************\n"
        "\t*              *\n"
        "\t*  CREATE MENU *\n"
        "\t*              *\n"
        "\t*  1. Default  *\n"
        "\t*  2. Copy     *\n"
        "\t*              *\n"
        "\t****************\n"
        "\tChoose an option: ";
    getline(cin, option);

    if (option == "1") {    // Run Path 1
        menuCreateVectorByDefault();
    } else if (option == "2") { // Run Path 2
        menuCreateVectorByCopy();
    } else {    // Run Default Path
        cout << "\n\tOption is not listed.\n";
    }
}

void menu::menuCreateVectorByDefault() {
    Vector_double vd;
    v_list.push_back(vd);
    cout << "\n\tA Vector has been created by default\n";
}

void menu::menuCreateVectorByCopy() { // Create a Vector By Copy Constructor (Big-3)
    string input;
    int i;
    int v_size = v_list.size();
    if (v_size < 1) {
        cout <<
            "\n\tThere's no vector to be copied."
            "\n\tPlease initialize a vector by default first.\n";
    } else {
        menuPrintVectorAll();
        cout << "\n\tChoose a vector to be copied: ";
        getline(cin, input);
        try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        if (i < 0 || i >= v_size) {
            cout << "\n\tIndex is out of bound.\n";
        } else {
            Vector_double vd(v_list.at(i));
            v_list.push_back(vd);
            cout << "\n\tCopy construction is done.\n";
        }
    }
}

void menu::menuUpdateVector() { // Update A Vector
    if (v_list.size() == 0) {
        cout << "\n\tThere's no vector to be updated."
                "\n\tPlease initialize a vector by default first.\n";
        return;
    }
    string option;
    cout <<
        "\n\t*******************\n"
        "\t*                 *\n"
        "\t*   UPDATE MENU   *\n"
        "\t*                 *\n"
        "\t*  1. Assignment  *\n"
        "\t*  2. PopBack     *\n"
        "\t*  3. PushBack    *\n"
        "\t*  4. Insert      *\n"
        "\t*  5. Resize      *\n"
        "\t*  6. ShrinkToFit *\n"
        "\t*                 *\n"
        "\t*******************\n"
        "\tChoose an option: ";
    getline(cin, option);

    if (option == "1") {    // Run Path 1
        menuUpdateVectorByAssignment();
    } else if (option == "2") { // Run Path 2
        menuUpdateVectorByPopBack();
    } else if (option == "3") { // Run Path 3
        menuUpdateVectorByPushBack();
    } else if (option == "4") { // Run Path 4
        menuUpdateVectorInsert();
    } else if (option == "5") { // Run Path 5
        menuUpdateVectorResize();
    } else if (option == "6") { // Run Path 6
        menuUpdateVectorShrinkToFit();
    } else {    // Run Default Path
        cout << "\n\tOption is not listed.\n";
    }
}

void menu::menuUpdateVectorByAssignment() { // Update A Vector By Assignment Operator (Big-3)
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        int j;
        cout << "\tChoose a base Vector: ";
        getline(cin, input);
        try {j = stod(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        if (j < 0 || j >= v_size) {
            cout << "\tElement is out of bound.\n";
        } else {
            v_list.at(i) = v_list.at(j);
            cout << "\tUpdate is done.\n";
        }
    }
}

void menu::menuUpdateVectorByPopBack() { // Update A Vector By Pop Back
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        v_list.at(i).pop_back();
            cout << "\tUpdate is done.\n";
    }
}

void menu::menuUpdateVectorByPushBack() { // Update A Vector By Push Back
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        double j;
        cout << "\tEnter a double value: ";
        getline(cin, input);
        try {j = stod(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        v_list.at(i).push_back(j);
        cout << "\tUpdate is done.\n";
    }
}

void menu::menuUpdateVectorInsert() { // Update A Vector By Insert
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        int j;
        double k;
        cout << "\tChoose a position: ";
        getline(cin, input);
        try {j = stod(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        cout << "\n\tEnter a double value: ";
        getline(cin, input);
        try {k = stod(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        v_list.at(i).insert(j, k);
        cout << "\tUpdate is done.\n";
    }
}

void menu::menuUpdateVectorResize() { // Update A Vector By Resize
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        int j;
        cout << "\tEnter a new size: ";
        getline(cin, input);
        try {j = stod(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        v_list.at(i).resize(j);
        cout << "\tUpdate is done.\n";
    }
}

void menu::menuUpdateVectorShrinkToFit() { // Update A Vector By ShrinkToFit
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector to be updated: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        v_list.at(i).shrink_to_fit();
        cout << "\tUpdate is done.\n";
    }
}

void menu::menuDeleteVector() { // Delete A Vector
    string input;
    int i;
    int v_size = v_list.size();
    if (v_size < 1) {
        cout <<
            "\n\tThere's no vector to be deleted."
            "\n\tPlease initialize a vector by default first.\n";
    } else {
        menuPrintVectorAll();
        cout << "\n\tChoose a vector to be deleted: ";
        getline(cin, input);
        try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
        if (i < 0 || i >= v_size) {
            cout << "\n\tIndex is out of bound.\n";
        } else {
            v_list.erase(v_list.begin() + i);
            cout << "\n\tDeletion is done.\n";
        }
    }
}

void menu::menuPrintVector() { // Print A Vector
    if (v_list.size() == 0) {
        cout << "\n\tThere's no vector to be printed."
                "\n\tPlease initialize a vector by default first.\n";
        return;
    }
    string option;
    cout <<
        "\n\t*******************\n"
        "\t*                 *\n"
        "\t*    PRINT MENU   *\n"
        "\t*                 *\n"
        "\t*  1. Size        *\n"
        "\t*  2. Elements    *\n"
        "\t*  3. Stats       *\n"
        "\t*  4. All         *\n"
        "\t*                 *\n"
        "\t*******************\n"
        "\tChoose an option: ";
    getline(cin, option);

    if (option == "1") {    // Run Path 1
        menuPrintVectorSize();
    } else if (option == "2") { // Run Path 2
        menuPrintVectorElements();
    } else if (option == "3") { // Run Path 3
        menuPrintVectorStats();
    } else if (option == "4") { // Run Path 4
        menuPrintVectorAll();
    }  else {    // Run Default Path
        cout << "\n\tOption is not listed.\n";
    }
}

void menu::menuPrintVectorSize() { // Print A Vector Size
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector Size to be printed: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        cout << "Size of vector " << i << " : " << v_list.at(i).size() << endl;
    }
}

void menu::menuPrintVectorElements() { // Print A Vector Elements
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector Size to be printed: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        cout << "Elements of vector " << i << " : " << v_list.at(i);
    }
}

void menu::menuPrintVectorStats() { // Print A Vector Stats
    string input;
    int i;
    int v_size = v_list.size();
    menuPrintVectorAll();
    cout << "\tChoose a Vector Size to be printed: ";
    getline(cin, input);
    try {i = stoi(input);} catch (...) {cout << "\tInvalid Input.\n"; return;}
    if (i < 0 || i >= v_size) {
        cout << "\tIndex is out of bound.\n";
    } else {
        cout << "Stats of vector " << i << " : " << endl;
        v_list.at(i).printStats();
        cout << endl;
    }
}

void menu::menuPrintVectorAll() { // Print All Vectors
    int v_size = v_list.size();
    for (int i = 0; i < v_size; i++) {
        cout << "[" << i << "] : " << v_list.at(i);
    }
}
