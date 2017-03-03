//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the multiplication subclass. its takes to pointers and calculates the multiplication of those two strings
#ifndef Multiplication_h//set up
#define Multiplication_h //set up
#include <string> //include string
using namespace std; //using name space
class Multiplication{ //class body
    public: //public section
        Multiplication(); //setup
        void print(string &LEFT, string &RIGHT); //print function
        ~Multiplication(); //deconstructor
        string evaluate(string &LEFT, string &RIGHT);//evaluate function

}; //end body

#endif /* Multiplication_h */

