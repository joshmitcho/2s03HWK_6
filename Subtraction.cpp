//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605, 1409778
//Description: This is the subtraction subclass. its takes to pointers and calculates the subtraction of those two strings
#include "Subtraction.h"// setup
#include <iostream> //include
#include <string> //include
#include <cstdlib> //include
#include <sstream> //include
using namespace std; //using namespace
Subtraction::Subtraction(){ //set up
    string evaluate(string &leftside, string &rightside); //function evaluate
    void print(string answer); //function print
}; // end set up

string Subtraction::evaluate(string &leftside, string &rightside){ // evaluate definition
    float LEFT=atof(leftside.c_str()); //left side
    float RIGHT=atof(rightside.c_str()); //right side
    float answer= LEFT-RIGHT; //calculation
    stringstream stuff; //string stuff
    stuff << answer; //set answer  to stuff
    string answer1=stuff.str(); //convert to string
    return answer1; //return value

} //end def
void Subtraction::print(string &leftside, string &rightside){ //print function
    cout << leftside << "-" << rightside << endl; //print
} //end def
Subtraction::~Subtraction(){ //deconstructor
} //deconstructor

