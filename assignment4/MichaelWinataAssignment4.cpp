/*******************************************
 * File    : MichaelWinataAssignment4      *
 * Author  : Michael Winata                *
 * Compiler: GNU GCC Compiler (-std=c++11) *
 *******************************************/

#include <iostream>                    // Standard Library
#include <string>                      // Standard Library
#include <algorithm>                   // Standard Library

using namespace std;                   // Standard Namespace

// Function Headers
bool isPalindrome(const string&);      // Problem #1
int digitSum(int);                     // Problem #2
int waysToClimb(int);                  // Problem #3

// Main
int main() {                           // Main Function

    string str;                        // Unit Test Variable For Problem #1
    int i;                             // Unit Test Variable For Problem #2
    int j;                             // Unit Test Variable For Problem #3

    string str_no_white_space;         // Unit Test Variable For Problem #1 W/O White Space

    // Print Assignment Description
    cout
        << "File : MichaelWinataAssignment4:\n"
        << "Topic: Recursion\n";


    // Print Test Description For Problem #1
    cout
        << "\n-- Testing isPalindrome() --\n"
        << "Enter a string: ";

    // Take User Input For Problem #1
    getline(cin, str);

    // Remove White Space
    str_no_white_space = str;
    str_no_white_space.erase(
        remove(
            str_no_white_space.begin(),
            str_no_white_space.end(),
            ' '
        ),
        str_no_white_space.end()
    );

    // Print Test Result For Problem #1
    cout
        << "\n-- Testing Result --\n"
        << str << (isPalindrome(str_no_white_space) ? " is " : " is not ") << "a Palindrome\n";

    // Print Test Description For Problem #2
    cout
        << "\n-- Testing digitSum() --\n"
        << "Enter an integer: ";

    // Take User Input For Problem #2
    while (true)
        try {
            getline(cin, str);
            i = stoi(str);
            break;
        } catch (...) {
            cout
                <<"Input was not an integer.\n"
                <<"Enter an integer: ";
        }

    // Print Test Result For Problem #2
    cout
        << "\n-- Testing Result --\n"
        << "digitSum of " << i << " is " << digitSum(i) << endl;

    // Print Test Description For Problem #3
    cout
        << "\n-- Testing waysToClimb() --\n"
        << "Enter an integer: ";

    // Take User Input For Problem #3
    while (true)
        try {
            getline(cin, str);
            j = stoi(str);
            break;
        } catch (...) {
            cout
                <<"Input was not an integer.\n"
                <<"Enter an integer: ";
        }

    // Print Test Result For Problem #3
    cout
        << "\n-- Testing Result --\n"
        << "waysToClimb of " << j << " is " << waysToClimb(j) << endl;



    return 0;                          // Mandatory Return Value

}

// Function Definitions
bool isPalindrome(const string& str) { // Problem #1

    int i = 0;                         // First Character Index
    int j = str.size() - 1;            // Last Character Index

    if (str[i] != str[j])              // Negative Result Path
        return false;
    else if (j < 3)                    // Positive Result Path
        return true;
    else                               // Recursive Path
        return isPalindrome(str.substr(1, j - 1));

}

int digitSum(int i) {                  // Problem #2

    if (i < -9)                        // Negative Recursive Path
        return (i % 10) + digitSum(i / 10);
    if (i > 9)                         // Positive Recursive Path
        return (i % 10) + digitSum(i / 10);
    else                               // Constant Result Path
        return i;

}

int waysToClimb(int i) {               // Problem #3

    if (i < 1)                         // Safety Result Path
        return 0;
    else if (i < 4)                    // Constant Result Path
        return i;
    else                               // Recursive Path
        return waysToClimb(i - 1) + waysToClimb(i - 2);

}
