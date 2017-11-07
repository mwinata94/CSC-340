/*************************************
 * This cpp file defines the methods *
 *    declared in the header file    *
 *************************************/

#include "mwMenu.h"               // Header File
#include "mwMenuLL-implement.cpp" // Sub Menu for LinkedList

menu::menu() { // Default Constructor
    hi = "Hi, welcome!\n"; // Assigning Intro
    description = //Assigning Description
        "\n*******************************\n"
        "*                             *\n"
        "*             MENU            *\n"
        "*                             *\n"
        "*  1.CircularLinkedList Menu  *\n"
        "*  2.DoubleLinkedList Menu    *\n"
        "*  3.Close App                *\n"
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
        menuLL<mwCircularLinkedList> cll; // Create The Sub Menu
        cll.run(); // Run The Sub Menu
    } else if (option == "2") { // Run Path 2
        menuLL<mwDoubleLinkedList> dll; // Create The Sub Menu
        dll.run(); // Run The Sub Menu
    } else if (option == "3") { // Exit Menu
        return false;
    } else { // Default Path
        cout << endl << "Option is not listed, please choose a different option" << endl;
    }
    return true; // At this point, cll and dll are delete to reduce memory space consumption
}
