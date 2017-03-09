//Name: Andres Hurtado Carreon, Erin Varey, Katie Monkhouse
//MacId: hurtada, vareye, monkhokf
//Student Number: 1429437, 1400605 , 1409778
//Description: This is the arithmatic subclass. its takes the input string and puts it through a binary search returing smaller expressions until solved
//Commented by Josh Mitchell @joshmitcho

//Include libraries for IO and string processing
#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <sstream> 
#include <iomanip> 
//Include other classes necessary for proper functioning
#include "ArithmeticExpression.h" 
#include "Multiplication.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Division.h" 

using namespace std;

ArithmeticExpression::ArithmeticExpression(){//class  def
    string evaluate(string &INPUT); //eval
}

//This master function takes in a string and parses it as an arithmetic expression
string ArithmeticExpression::evaluate(string &INPUT){
    string *left; //pointer denoting left side of the expression
    string *right; //pointer denoting right side of the expression
	//number of brackets, if it becomes negative at any time, the expression has mismatched brackets
    int bracket=0;	
    for(int i=0;i<INPUT.size();i++){ 
        if(INPUT.at(i)=='('){ //if the character inspected is a left bracket
            bracket++;
        }
    } 

    if(bracket!=0){//if brackets are there
        int leftbracket=0;	//position of left bracket
        for(int i=0;i<INPUT.size();i++){ 
            if(INPUT.at(i)=='('){//if the character inspected is a left bracket
                leftbracket=i; 
            }
        }
        int rightbracket=0; //position of right bracket
        bool first=true;
        for(int i=leftbracket;i<INPUT.size();i++){
            if((INPUT.at(i)==')') && (first)){ //if the character inspected is a right bracket
                rightbracket=i;
                first=false;
            } 
        }
		//create new set ignoring what's already been processed
        int newsize = rightbracket-(leftbracket+1); 
		
        string temp=INPUT.substr(leftbracket+1,newsize); //create a substring to store this set
        bool found=false;
        while(!found){ //while none are found
			found=true;
			int a=0;

			for(int i=0;i<temp.size();i++){
				//if the character inspected is a * or a /
				if((((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0))&& found){
					a=i;
					found=false;
				}
			}


			if(found==false){
				int b=0;
				int length=temp.size();//grabs length

				for(int i=1;i<a;i++){ 
					//if the character inspected is an operator (+, -, *, /)
					if(((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0)){
						b=i+1; 
					}
				}
				int sizenew= a-b;//create new size
				string A1=temp.substr(b,sizenew);//create substring of that size
				left= &A1; //creat pointer for the left side of the substring
				bool fix=true; 
				for(int i=a+2;i<temp.size();i++){
					//if the character inspected is an operator (+, -, *, /)
					if((((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0))&&fix){
						length=i;
						fix=false;
					}
				}

				int size= length-(a+1);//create new size

				string A2=temp.substr(a+1,size);//create new substring that is rightside

				right= &A2; 

				if(((temp.substr(a,1)).compare("*")==0)){//search for multiplication operator

					//evaluate multiplication product
					Multiplication myMultiplication;
					string newvalue = myMultiplication.evaluate(*left, *right);
					int Length= temp.size()-length;//create new size
					int Length1=b-0;//grabbing size
					temp=temp.substr(0,Length1)+newvalue+temp.substr(length,Length); //create substring
				}

				else if(((temp.substr(a,1)).compare("/")==0)){//else if division operator found
					//evaluate multiplication product
					Division myDivision;
					string newvalue = myDivision.evaluate(*left, *right);//grab division
					int Length= temp.size()-length;//create new size
					int Length1=b-0; //grabbing size
					temp=temp.substr(0,Length1)+newvalue+temp.substr(length,Length);//create substring
				} if
			}
        }
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
        found1=true;
        int b=0;//accumulator
        for(int i=1;i<temp.size();i++){
            if((((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0)) && found1){//if symbol
                b=i;
                found1=false; 
            }
        }
        if(found1==false){ //if false
            int c=0;
            int newsize=temp.size();//getting size


            for(int i=1;i<b;i++){
                if(((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0)){
                    //if symbol
                    c=i+1; //set and add one
                } 
            }
            int sizenew1=b-c;
            string A3=temp.substr(c,sizenew1);//creat string
            left=&A3;
            bool boolean=true;
            for(int i=b+1;i<temp.size();i++){
                if((temp.substr(i,1)=="+" || temp.substr(i,1)=="-" || temp.substr(i,1)=="*" || temp.substr(i,1)=="/")&&boolean){
                        //if symbol
                    newsize=i; 
                    boolean=false;
                }
            }


            int newlength=newsize-(b+1);//get size
            string A4=temp.substr(b+1,newlength);//substring
            right=&A4;//get right

            if(temp.substr(b,1)=="+"){ //iff add
                Addition myAddition; //create object
                string newvalue1 = myAddition.evaluate(*left, *right);// grab at pointers
                int sizes= c-0;//get size
                int size1=temp.size()-newsize;//get size
                temp=temp.substr(0,sizes)+newvalue1+temp.substr(newsize,size1);//create string
            }

            else if(temp.substr(b,1)=="-"){ //else if minue
                Subtraction mySubtraction; //create item of class
                string newvalue1 = mySubtraction.evaluate(*left, *right);//send withpointers
                int sizes= c-0;//get size
                int size1=temp.size()-newsize;//get size
                temp=temp.substr(0,sizes)+newvalue1+temp.substr(newsize,size1);// substring of remainder of expression
            } if

        }

        }
        int Lengthleft= leftbracket-0;
        int Lengthright=INPUT.size()-(rightbracket+1);
        INPUT=INPUT.substr(0,Lengthleft)+temp+INPUT.substr(rightbracket+1,Lengthright);//create new smaller strring
    }



    else{//if there is no more brackets
        bool Found=false;
        while(!Found){//not not true
        Found=true;
        int a=0;
        for(int i=0;i<INPUT.size();i++){
            if((INPUT.at(i)=='*' || INPUT.at(i)=='/') && Found){//if symbol
                a=i;
                Found=false; //set false
            }
        }
        if(Found==false){ //if no mult or div
            int b=0;
            int newsize=INPUT.size();

            for(int i=1;i<a;i++){
                if(INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/'){//if symbol
                    b=i+1;
                }
            }
            int lens=a-b;//size

            string A11=INPUT.substr(b,lens);//string with size
            left=&A11;//pointer

            bool fix2=true;//while trye
            for(int i=a+2;i<INPUT.size();i++){
                if((INPUT.at(i)=='+'|| INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/')&&fix2){//if symbol
                    newsize=i;
                    fix2=false;//set false
                }
            }
            int lenss=newsize-(a+1);//size

            string A22=INPUT.substr(a+1,lenss);//substring
            right = &A22;//pointer

            if(INPUT.at(a)=='*'){//if mult
                Multiplication myMultiplication;//object create
                string Newvalue = myMultiplication.evaluate(*left, *right);//call
                int len1=b-0;//get size
                int len2=INPUT.size()-newsize;//get size
                INPUT=INPUT.substr(0,len1)+Newvalue+INPUT.substr(newsize,len2);//create string
            }

            else if(INPUT.at(a)=='/'){//if division
                Division myDivision;//creat object
                string Newvalue = myDivision.evaluate(A11, A22);//eval
                int len1=b-0;//size
                int len2=INPUT.size()-newsize;//size
                INPUT=INPUT.substr(0,len1)+Newvalue+INPUT.substr(newsize,len2);//substring
            } if


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


        Found1=true;
        int a=0;
        for(int i=1;i<INPUT.size();i++){
            if((INPUT.at(i)=='+' || INPUT.at(i)=='-') && Found1){// if symbol
                a=i;
                Found1=false;//set false
            }
        }// for
        if(Found1==false){// if false
            int b=0;//set zero
            int c=INPUT.size();// grab size

            for(int i=1;i<a;i++){
                if(INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/'){//if symbol
                    b=i+1;//add
                }
            }

            int lengthh=a-b;//get size
            string A13=INPUT.substr(b,lengthh);//get string
            left=&A13;//get pointer

            bool fix3=true;//set true
            for(int i=a+1;i<INPUT.size();i++){
                if((INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/')&& fix3){//if symbol
                    c=i;
                    fix3=false;//set false
                }
            }
            int llen=c-(a+1);//get size
            string A14=INPUT.substr(a+1,llen);//get string
            right =&A14;//pointer

            if(INPUT.at(a)=='+'){//if plus
                Addition myAddition;//object
                string value = myAddition.evaluate(A13, A14);//get value
                int len1=b-0;//get size
                int len2=INPUT.size()-c; //get size
                INPUT=INPUT.substr(0,len1)+value+INPUT.substr(c,len2);//get string
            }

            else if(INPUT.at(a)=='-'){//else if sub
                Subtraction mySubtraction;//object
                string value = mySubtraction.evaluate(*left, *right);//evaluate
                int len1=b-0;//size
                int len2=INPUT.size()-c;//size
                INPUT=INPUT.substr(0,len1)+value+INPUT.substr(c,len2);//string
            }


        }//end
    }//end

    }//end

    for(int i=1; i<INPUT.size();i++){
        if ((INPUT.substr(i,1)=="+") || (INPUT.substr(i,1)=="-") || (INPUT.substr(i,1)=="*") || (INPUT.substr(i,1)=="/") || (INPUT.substr(i,1)==")")){//check symbol
            string *equation1;//pointer
            equation1=&INPUT;//pointer
            ArithmeticExpression test;//object
            test.evaluate(*equation1);//evaluate
            equation1=NULL;
            delete equation1;

        }

    }
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


