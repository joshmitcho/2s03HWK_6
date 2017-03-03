//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the addition subclass. its takes to pointers and calculates the addition of those two strings
#include "Addition.h" //set up
#include <iostream> //include io strea
#include <string> //include string
#include <cstdlib> //include cstdlib
#include <sstream> //include ssstream
using namespace std; //uisng name space
Addition::Addition(){ //set up of class
    string evaluate(string &leftside, string &rightside); //function used
}; //end class
string Addition::evaluate(string &leftside, string &rightside){ //function evaluate

    float LEFT=atof(leftside.c_str()); //int of left
    float RIGHT=atof(rightside.c_str()); //int of right
    float answer= LEFT+RIGHT; //add them together
    stringstream stuff;// variable stuff
    stuff << answer; // setting to answer
    string answer1=stuff.str(); //setting to string of string
    return answer1; //return this value

}//end class
void Addition::print(string &leftside, string &rightside){ // print function definition
    cout << leftside << "+" << rightside << endl;//print left and right with symbol
}//end function
Addition::~Addition(){// deconstructor
}//end deconstructor
