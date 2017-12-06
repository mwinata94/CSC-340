Assignment 5

Author  : Michael Winata

Main    : MichaelWinataAssignment5.cpp

Compiler: GNU GCC Compiler [-std=C++11]


When the main is compiled, user will be presented with an interactive

user interface to test the functionality of a custom version of vectors

as an ADT, named Vector_double, to manage a collection of doubles using

dynamic arrays.

This program is separated into 5 files (2 headers and 3 cpps).



The header files are as follow:



Vector_double.h        -> handles Vector_double Declaration

                       :  the Vector_double class contains the

                          design and functionality of a custom version

                          of a vector



mwMenu.h               -> handles menu Declaration

                       :  the menu class contains the interactive

                          user interface for running tests



The cpp files are as follow:



MichaelWinataAssignment5.cpp -> handles Main Definition

                             :  the main file creates a menu variable

                                and run said menu



Vector_double.cpp            -> handles Vector_double definition

                             :  the Vector_double class contains

                                a double pointer variable to store

                                the collection of doubles and two

                                integer variables to store the size

                                and capacity of the vector



mwMenu.cpp                   -> handles menu definition

                             :  the menu class contains three strings

                                to store the intro, description, and

                                outro of the menu and a vector of

                                Vector_double for testing purposes