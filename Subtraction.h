//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the subtraction subclass. its takes to pointers and calculates the subtraction of those two strings
#ifndef Subtraction_h// set up
#define Subtraction_h //set up
#include <string> //include strinbg
using namespace std; //using namespace
class Subtraction{ //class body
public: //public portion
    Subtraction(); // class
    void print(string &LEFT, string &RIGHT); //print function
    ~Subtraction(); //deconstructor
    string evaluate(string &LEFT, string &RIGHT); //evaluate function

}; // end class def

#endif /* Subtraction_h */
