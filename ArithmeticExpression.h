//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the arithmatic subclass. its takes the input string and puts it through a binary search returing smaller expressions until solved
#ifndef ArithmeticExpression_h//set up
#define ArithmeticExpression_h//set up

#include <string> //using string
using namespace std; //namespace

class ArithmeticExpression{// class def
    public: //public portion
        ArithmeticExpression(); //setup
        string evaluate(string &EXPRESSION); //eval function
        ~ArithmeticExpression();//deconstructor


}; //end def


#endif /* ArithmeticExpression_h */
