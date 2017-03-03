//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the division subclass. its takes to pointers and calculates the division of those two strings
#include "Division.h"//set up
#include <iostream> //include io stream
#include <string> //include string
#include <cstdlib> //include cstdlib
#include <sstream> //include ss stream
using namespace std; //using namespace
Division::Division(){//set up
    string evaluate(string &leftside, string &rightside); //evaluate function
}; //end class

string Division::evaluate(string &leftside, string &rightside){ //function

    float LEFT=atof(leftside.c_str()); //left side
    float RIGHT=atof(rightside.c_str()); //right side
    float answer= LEFT/RIGHT; //divide them
    stringstream stuff; //string
    stuff << answer; //save answer to stuff
    string answer1=stuff.str(); // string of string
    return answer1;//return answer 1

}//end class
void Division::print(string &leftside, string &rightside){ //print function
    cout << leftside << "/" << rightside << endl; //print left and right
}//end definition
Division::~Division(){ //deconstructor
} //end

