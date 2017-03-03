//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the addition subclass. its takes to pointers and calculates the addition of those two strings
#ifndef Addition_h//set up stuff
#define Addition_h //set up stuff
#include <string> //include string
using namespace std; // using name space

class Addition{//class
public: //public portion
    Addition(); //class type
    ~Addition();
    void print(string &LEFT, string &RIGHT); //print function
    string evaluate(string &LEFT, string &RIGHT); //evaluate function

}; //end class def

#endif /* Addition_h */
