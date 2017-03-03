//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the division subclass. its takes to pointers and calculates the division of those two strings
#ifndef Division_h//set up
#define Division_h //set up

#include <string> //include string
using namespace std; //using name space

class Division{ //divison class
public://public section
    Division(); //set up
    void print(string &LEFT, string &RIGHT);//print function
    string evaluate(string &LEFT, string &RIGHT); //evaluate function
    ~Division(); //deconstructor

};//end class

#endif /* Division_h */
