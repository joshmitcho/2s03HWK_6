//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the multiplication subclass. its takes to pointers and calculates the multiplication of those two strings
#include "Multiplication.h"//set up
#include <iostream> //include
#include <string> //include
#include <cstdlib> //include
#include <sstream> //include
using namespace std; //using namespace
Multiplication::Multiplication(){ //set up
    string evaluate(string &leftside, string &rightside); //evaluate function
}; //end class def

string Multiplication::evaluate(string &leftside, string &rightside){ //function
    float LEFT=atof(leftside.c_str()); //eft side
    float RIGHT=atof(rightside.c_str()); //right side
    float answer= LEFT*RIGHT; //multiply
    stringstream stuff; //stuff stringstream
    stuff << answer; // saving answer to stuff
    string answer1=stuff.str(); //creating string of it
    return answer1; //return answer1

} //end class
void Multiplication::print(string &leftside, string &rightside){ //print function
    cout << leftside << "*" << rightside << endl; //print nultiplied expression
} //end class
Multiplication::~Multiplication(){ //deconstructor
}//end class



