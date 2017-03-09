//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the arithmatic subclass. its takes the input string and puts it through a binary search returing smaller expressions until solved
//Commented by Josh Mitchell @joshmitcho
#include <iostream> //include
#include <string> //include
#include <cstdlib> //include
#include <sstream> //include
#include <iomanip> //include
#include "ArithmeticExpression.h" //set up
#include "Multiplication.h"//set up
#include "Addition.h" //set up
#include "Subtraction.h" //set up
#include "Division.h" //set up

using namespace std; //name space

ArithmeticExpression::ArithmeticExpression(){//class  def
    string evaluate(string &INPUT); //eval
}//end def


string ArithmeticExpression::evaluate(string &INPUT){//function def
    string *left; //pointer left
    string *right; //pointer right
    int bracket=0; // set bracket to zero
    for(int i=0;i<INPUT.size();i++){ //loop
        if(INPUT.at(i)=='('){ //if left brack
            bracket++; //increment
        }//end if
    } //end for

    if(bracket!=0){//if brackets are there
        int leftbracket=0;//set to zero
        for(int i=0;i<INPUT.size();i++){ //loop
            if(INPUT.at(i)=='('){//if left bracket
                leftbracket=i; //set to i
            }//end if
        }//end for
        int rightbracket=0; //set to zero
        bool first=true;//set to true
        for(int i=leftbracket;i<INPUT.size();i++){//loop
            if((INPUT.at(i)==')') && (first)){ //if true and right bracket
                rightbracket=i;//set to i
                first=false;//set to false
            } //end if
        }//end for
        int newsize = rightbracket-(leftbracket+1); //new size without set
        string temp=INPUT.substr(leftbracket+1,newsize); //substring create
        bool found=false;//if found will become true
        while(!found){ //while none are found
        found=true;//set to true
        int a=0;//set to zero


        for(int i=0;i<temp.size();i++){//loop
            if((((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0))&& found){//loop if * or / and true
                a=i;//set to i
                found=false;//set to false
            }//end if
        }//end loop


        if(found==false){//if false
            int b=0;//setg to zero
            int length=temp.size();//grabs length

            for(int i=1;i<a;i++){ //loop
                if(((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0)){
                    //if symbol
                    b=i+1; //set to index
                }//end if
            }//end loop
            int sizenew= a-b;//grab new size
            string A1=temp.substr(b,sizenew);//create substring
            left= &A1; //creat pointer
            bool fix=true; //set to true
            for(int i=a+2;i<temp.size();i++){//loop
                if((((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0))&&fix){
                    //if symbol
                    length=i;//set to i
                    fix=false;//set to false
                }//end if
            }//end for

            int size= length-(a+1);//create new size

            string A2=temp.substr(a+1,size);//create new substring that is rightside

            right= &A2; //set to pointer

            if(((temp.substr(a,1)).compare("*")==0)){//search for multiplication


                Multiplication myMultiplication;//grab class
                string newvalue = myMultiplication.evaluate(*left, *right);//grab at pointer
                int Length= temp.size()-length;//grabbing size
                int Length1=b-0;//grabbing size
                temp=temp.substr(0,Length1)+newvalue+temp.substr(length,Length);//creating substring of left solve and right
            }//end if

            else if(((temp.substr(a,1)).compare("/")==0)){//if division
                Division myDivision;//creat object
                string newvalue = myDivision.evaluate(*left, *right);//grab division
                int Length= temp.size()-length;//get size
                int Length1=b-0; //get size
                temp=temp.substr(0,Length1)+newvalue+temp.substr(length,Length);//create substring
            }//end else if
        }//end while
        }//end while
        //ADDITION AND SUBSTRACTION
        bool found1=false;//second use of found

        while(!found1){//while add or substract
        if (temp.size()>1){
            for(int k=0; k<(temp.size()-1);k++){
                if(temp.substr(k,2)=="--"){
                    temp=temp.substr(0,k)+"+"+temp.substr(k+2);
                }
            }
        }
        found1=true;//set to true
        int b=0;//accumulator
        for(int i=1;i<temp.size();i++){//loop
            if((((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0)) && found1){//if symbol
                b=i;//set to i
                found1=false; //set to false
            }//end if
        }//end for
        if(found1==false){ //if false
            int c=0;//set to zero
            int newsize=temp.size();//getting size


            for(int i=1;i<b;i++){//loop
                if(((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0)){
                    //if symbol
                    c=i+1; //set and add one
                } //end if
            }//end for
            int sizenew1=b-c;
            string A3=temp.substr(c,sizenew1);//creat string
            left=&A3;//set to left
            bool boolean=true;//set to true
            for(int i=b+1;i<temp.size();i++){//loop
                if((temp.substr(i,1)=="+" || temp.substr(i,1)=="-" || temp.substr(i,1)=="*" || temp.substr(i,1)=="/")&&boolean){
                        //if symbol
                    newsize=i; //set to i
                    boolean=false;//set to false
                }//end if
            }//end for


            int newlength=newsize-(b+1);//get size
            string A4=temp.substr(b+1,newlength);//substring
            right=&A4;//get right

            if(temp.substr(b,1)=="+"){ //iff add
                Addition myAddition; //create object
                string newvalue1 = myAddition.evaluate(*left, *right);// grab at pointers
                int sizes= c-0;//get size
                int size1=temp.size()-newsize;//get size
                temp=temp.substr(0,sizes)+newvalue1+temp.substr(newsize,size1);//create string
            }//end if

            else if(temp.substr(b,1)=="-"){ //else if minue
                Subtraction mySubtraction; //create item of class
                string newvalue1 = mySubtraction.evaluate(*left, *right);//send withpointers
                int sizes= c-0;//get size
                int size1=temp.size()-newsize;//get size
                temp=temp.substr(0,sizes)+newvalue1+temp.substr(newsize,size1);// substring of remainder of expression
            }//end else if

        }//end loop

        }//end loop
        int Lengthleft= leftbracket-0;//set to value
        int Lengthright=INPUT.size()-(rightbracket+1);//set to value
        INPUT=INPUT.substr(0,Lengthleft)+temp+INPUT.substr(rightbracket+1,Lengthright);//create new smaller strring
    }//end if



    else{//if there is no more brackets
        bool Found=false;//set to false
        while(!Found){//not not true
        Found=true;//set to true
        int a=0;//set to zero
        for(int i=0;i<INPUT.size();i++){//loop
            if((INPUT.at(i)=='*' || INPUT.at(i)=='/') && Found){//if symbol
                a=i;//set to i
                Found=false; //set false
            }//end if
        }//end for
        if(Found==false){ //if no mult or div
            int b=0;
            int newsize=INPUT.size();

            for(int i=1;i<a;i++){//loop
                if(INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/'){//if symbol
                    b=i+1;//set to value
                }//end if
            }//end for
            int lens=a-b;//size

            string A11=INPUT.substr(b,lens);//string with size
            left=&A11;//pointer

            bool fix2=true;//while trye
            for(int i=a+2;i<INPUT.size();i++){//loop
                if((INPUT.at(i)=='+'|| INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/')&&fix2){//if symbol
                    newsize=i;//set to i
                    fix2=false;//set false
                }//end if
            }//end for
            int lenss=newsize-(a+1);//size

            string A22=INPUT.substr(a+1,lenss);//substring
            right = &A22;//pointer

            if(INPUT.at(a)=='*'){//if mult
                Multiplication myMultiplication;//object create
                string Newvalue = myMultiplication.evaluate(*left, *right);//call
                int len1=b-0;//get size
                int len2=INPUT.size()-newsize;//get size
                INPUT=INPUT.substr(0,len1)+Newvalue+INPUT.substr(newsize,len2);//create string
            }//end if

            else if(INPUT.at(a)=='/'){//if division
                Division myDivision;//creat object
                string Newvalue = myDivision.evaluate(A11, A22);//eval
                int len1=b-0;//size
                int len2=INPUT.size()-newsize;//size
                INPUT=INPUT.substr(0,len1)+Newvalue+INPUT.substr(newsize,len2);//substring
            }//end else if


        }//end
        }//end
        //down here dealing with adding/sub

        bool Found1=false;// if false
        while(!Found1){//while false
        if (INPUT.size()>1){
            for(int k=0;k<(INPUT.size()-1);k++){
                if(INPUT.substr(k,2)=="--"){
                    INPUT=INPUT.substr(0,k)+"+"+INPUT.substr(k+2);
                }
            }
        }


        Found1=true;//set to true
        int a=0;//set to zero
        for(int i=1;i<INPUT.size();i++){//loop
            if((INPUT.at(i)=='+' || INPUT.at(i)=='-') && Found1){// if symbol
                a=i;//set to i
                Found1=false;//set false
            }//end if
        }// for
        if(Found1==false){// if false
            int b=0;//set zero
            int c=INPUT.size();// grab size

            for(int i=1;i<a;i++){//loop
                if(INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/'){//if symbol
                    b=i+1;//add
                }//end if
            }//end for

            int lengthh=a-b;//get size
            string A13=INPUT.substr(b,lengthh);//get string
            left=&A13;//get pointer

            bool fix3=true;//set true
            for(int i=a+1;i<INPUT.size();i++){//loop
                if((INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/')&& fix3){//if symbol
                    c=i;//set to i
                    fix3=false;//set false
                }//end if
            }//end for
            int llen=c-(a+1);//get size
            string A14=INPUT.substr(a+1,llen);//get string
            right =&A14;//pointer

            if(INPUT.at(a)=='+'){//if plus
                Addition myAddition;//object
                string value = myAddition.evaluate(A13, A14);//get value
                int len1=b-0;//get size
                int len2=INPUT.size()-c; //get size
                INPUT=INPUT.substr(0,len1)+value+INPUT.substr(c,len2);//get string
            }//end if

            else if(INPUT.at(a)=='-'){//else if sub
                Subtraction mySubtraction;//object
                string value = mySubtraction.evaluate(*left, *right);//evaluate
                int len1=b-0;//size
                int len2=INPUT.size()-c;//size
                INPUT=INPUT.substr(0,len1)+value+INPUT.substr(c,len2);//string
            }//end else


        }//end
    }//end

    }//end

    for(int i=1; i<INPUT.size();i++){//loop
        if ((INPUT.substr(i,1)=="+") || (INPUT.substr(i,1)=="-") || (INPUT.substr(i,1)=="*") || (INPUT.substr(i,1)=="/") || (INPUT.substr(i,1)==")")){//check symbol
            string *equation1;//pointer
            equation1=&INPUT;//pointer
            ArithmeticExpression test;//object
            test.evaluate(*equation1);//evaluate
            equation1=NULL;
            delete equation1;

        }//end if

    }//end for
    if(INPUT=="-0" && INPUT.size()==2){
        INPUT="0";
    }

    left=NULL;
    delete left;
    right=NULL;
    delete right;

    return INPUT;//returb input
}//end
ArithmeticExpression::~ArithmeticExpression(){//deconstructor
}


