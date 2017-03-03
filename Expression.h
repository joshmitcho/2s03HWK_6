//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437,1400605 , 1409778
//Description: This is the expression subclass. it's virtual and uses pointers to point to the correct class
#ifndef EXPRESSION_H//set up
#define EXPRESSION_H //set up
#include <string>//include
using namespace std; // using name space

class Expression //class expression
{ //open
    public: //public portion
        Expression(); //set up
        virtual void print(string &leftside, string &rightside); //print function
        virtual string increment(); //increment function
         virtual string evaluate(string &leftside, string &rightside); //evaluate function
}; //end

#endif // EXPRESSION_H
