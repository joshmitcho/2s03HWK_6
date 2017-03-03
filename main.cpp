//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the main class that takes an input checks for errors and calculates
#include "ArithmeticExpression.h" // including class
#include "Multiplication.h" //including classes
#include "Addition.h" //including classes
#include "Subtraction.h" //including classes
#include "Division.h" //including classes
#include <iostream> //including iostream
#include <string> // including string
#include <iomanip> //including iomanip
#include <cstdlib> //including cstdlib
#include <algorithm> //including algorithm
#include <sstream> //including ss stream
#include <cmath>
using namespace std; //using name space

int main() { // main function
    string expressionToIncrement;
    string addToNewString;
    string tempString;

    bool moose= true; //setting moose to true
    string input; //initializing input
    while (input != "#"){ //if the input is not a #
        cout << "Please enter an expression" << endl; //ask for expression
        getline(cin, input); //creates string of input
        bool cat = false; //setting cat to false
        if (input.at(0) == '#'){ //if user enters #
            moose=false; //set moose to false
        } //end if
    //Error checks
    //bracket count
        int leftbracket=0; //setting left bracket to zero
        int rightbracket=0; //setting right bracket to zero
        for(int i=0; i<input.length()-1;i++){ //for loop to interate through input
            if (input.at(i)== '(') // if its left bracket
                leftbracket=leftbracket+1; //add one
        } //end loop

        for(int j=0; j<input.length();j++){ // for loop to iterate through input
            if (input.at(j) == ')') //if right bracket
                rightbracket=rightbracket+1; //add one
        } //end loop
        if (leftbracket != rightbracket){ //if # of left brack = # of right bracket
            moose = false; //set moose to false
            cout<< "Expression is not well formed" << endl; //give error
        } //end if
        for (int i=0; i<input.length()-1; i++){ //loop
            if ((input.at(i)== '+' || input.at(i)== '-' || input.at(i)== '*' || input.at(i)== '/')&& (input.at(i+1)== '+' || input.at(i+1)== '-' || input.at(i+1)== '*' || input.at(i+1)== '/')){
                 //if input is symbol
                 moose = false; //set to false
                 cout<< "Expression is not well formed" << endl; //give error
            } //end if
        } //end for

       if (input.at(0)== '+' || input.at(0)== '-' || input.at(0)== '*' || input.at(0)== '/'){ //if symbol at start of string
            moose= false; //set to false
            cout << "Expression is not well formed" << endl; //error
        }//end if
        for (int i =0; i<input.length()-1; i++){ //loop
            if (i == input.length()-1){ //if last index
                if (input.at(i)== '+' || input.at(i)== '-' || input.at(i)== '*' || input.at(i)== '/'){ //if symbol
                    moose=false; //set false
                    cout << "Expression is not well formed" << endl; //error
                }// end if
            }//end if
        } //end for
        bool spaces =true; //set spaces to true
        int spacecount=0;//set to zero
        string noterror= "noterror"; //set to not error
        for (int i=0; i<input.length()-1; i++){// loop
            if (input.at(i) == ' '){//if space
                spacecount++;//increment
            }//end if
        }//end for
        if (spacecount != 0){ // if spaces
            for (int i=0; i<input.length()-1;){ //loops
                if (input.at(i)== ' '){ //if space
                    if (input.at(i+1) == ' '){//if next is space
                        i++; //increment i
                    }// end if
                    else{ //else
                        if (input.at(i+1)== '0' || input.at(i+1)== '1' || input.at(i+1)== '2' || input.at(i+1)== '3' || input.at(i+1)== '4' || input.at(i+1)== '5' ||
                            input.at(i+1)== '6' || input.at(i+1)== '7' || input.at(i+1)== '8' || input.at(i+1)== '9'){
                                //if a nuber
                                noterror="error"; // set to error
                                i++; //increment i
                            } // end if
                    } // end else
                } // end if
                else{ //else
                    i++; //incrememnt i
                } //end else
            }// end for

        } //end if
        for (int i=0; i<input.length()-1; i++){ //loop
            if (input.at(i) == ')' && input.at(i+1)== '('){ //if 2 besides each other
                    moose= false; //set to false
                    cout << "Expression is not well formed" << endl; //error

            }//end if
        } //end for
        for (int i=0; i<input.length()-1; i++){ //loop
            if (input.at(i) == '(' && input.at(i+1)== ')'){ //if besides each other
                    moose= false; // set to false
                    cout << "Expression is not well formed" << endl; //error

            }//end if
        }//end for
        if (noterror== "error"){  //if there is error
            moose= false; //set false
            cout << "Expression is not well formed" << endl; //error
        } //end if

        string input1 = ""; //set to empty
        int length = input.length(); //get length
        for(int i=0; i<length;i++){ //loop
            if((input.substr(i,1))!=" "){ //if space
                input1+=input.substr(i,1);//incrememnt
            }//end if
        } //end for
        moose=true; //set to true
        if (input.at(0) == '@'){ // if @ symbol
            cat = true; //set to true
            moose = false; //set false
        }//end if
        string oldinput="";//empty string

        while(moose){//while true
            string *equation;//pointer equation
            equation=&input1;//address of pointer
            ArithmeticExpression test;//creating object
            string answer1 = test.evaluate(*equation);//evaluate at pointer
            float answer2= atof(answer1.c_str()); //convert to int
            cout << input;//print expression inputted
            cout << "=" << fixed << setprecision(2) << answer2 << endl; //print answer
            moose=false; // set to false
            oldinput=input;// set to input
            equation=NULL;
            delete equation;
        }//end while


    }//end while

    return 0;//return 0
}//end main
