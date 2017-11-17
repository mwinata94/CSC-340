Assignment 4

Author  : Michael Winata

Main    : MichaelWinataAssignment4.cpp

Compiler: GNU GCC Compiler (-std=c++11)

When the main file is compiled, user will be prompted to input 
values to unit test each assignment problem.

The main file contains 4 functions, such as:

bool isPalindrome(const string&) : a recursive function to
                                   determine whether a string
                                   is a palindrome or not.
                                -> return true if the string
                                   is a palindrome;
                                   else return false.
                                -> cases:
                                   a) Whitespace is removed
                                   b) Case-sensitive

int digitSum(int)                : a recursive function to
                                   find the sum of all digits
                                   of an integer.
                                -> return the sum of all digits
                                   of an integer.
                                -> cases:
                                   a) negative digit returns 
                                   negative sum

int waysToClimb(int)             : a recursive function to
                                   find of the number of 
                                   possible ways to climb a
                                   number of staircases.
                                -> return the number of
                                   possible ways to climb the
                                   number of staircases.
                                -> cases:
                                   a) 0 staircase returns 0
                                   b) negative staircase returns
                                   0

int main()                       : the main function of the
                                   program; prompt the user
                                   for inputs to unit test
                                   the three functions above,
                                   and then display the result 
                                   of the unit tests.
                                -> return 0.