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
					//Create substring of remainder of expression
					temp=temp.substr(0,Length1)+newvalue+temp.substr(length,Length);
				}

				else if(((temp.substr(a,1)).compare("/")==0)){//else if division operator found
					//evaluate multiplication product
					Division myDivision;
					string newvalue = myDivision.evaluate(*left, *right);//grab division
					int Length= temp.size()-length;//create new size
					int Length1=b-0; //grabbing size
					//Create substring of remainder of expression
					temp=temp.substr(0,Length1)+newvalue+temp.substr(length,Length);
				} if
			}
        }
        //ADDITION AND SUBSTRACTION
        bool found1=false;//create second found flag

        while(!found1){//while adding or substracting
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
			//if the character inspected is an operator (+, -, *, /)
            if((((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0)) && found1){
                b=i;
                found1=false; 
            }
        }
        if(found1==false){
            int c=0;
            int newsize=temp.size();//getting size


            for(int i=1;i<b;i++){
				//if the character inspected is an operator (+, -, *, /)
                if(((temp.substr(i,1)).compare("+")==0) || ((temp.substr(i,1)).compare("-")==0) || ((temp.substr(i,1)).compare("*")==0) || ((temp.substr(i,1)).compare("/")==0)){

                    c=i+1; //set and add one
                } 
            }
            int sizenew1=b-c;
            string A3=temp.substr(c,sizenew1);//create string
            left=&A3;
            bool boolean=true;
            for(int i=b+1;i<temp.size();i++){
				//if the character inspected is an operator (+, -, *, /)
                if((temp.substr(i,1)=="+" || temp.substr(i,1)=="-" || temp.substr(i,1)=="*" || temp.substr(i,1)=="/")&&boolean){

                    newsize=i; 
                    boolean=false;
                }
            }


            int newlength=newsize-(b+1);//create new size
            string A4=temp.substr(b+1,newlength);//create substring of newLength
            right=&A4;//create pointer for right side of new string

            if(temp.substr(b,1)=="+"){ //if addition operator found
				//Evaluate sum
                Addition myAddition;
                string newvalue1 = myAddition.evaluate(*left, *right);// grab at pointers
                int sizes= c-0;//get size
                int size1=temp.size()-newsize;//get size
				//Create substring of remainder of expression
                temp=temp.substr(0,sizes)+newvalue1+temp.substr(newsize,size1);
            }

            else if(temp.substr(b,1)=="-"){ //else //if subtraction operator found
				//Evaluate Difference
                Subtraction mySubtraction;
                string newvalue1 = mySubtraction.evaluate(*left, *right);
                int sizes= c-0;//get size
                int size1=temp.size()-newsize;//get size
				//Create substring of remainder of expression
                temp=temp.substr(0,sizes)+newvalue1+temp.substr(newsize,size1);
            } if

        }

        }
        int Lengthleft= leftbracket-0;
        int Lengthright=INPUT.size()-(rightbracket+1);
		//Create substring of remainder of expression
        INPUT=INPUT.substr(0,Lengthleft)+temp+INPUT.substr(rightbracket+1,Lengthright);
    }



    else{//if there are no more brackets
			bool Found=false;
			while(!Found){
				Found=true;
				int a=0;
				for(int i=0;i<INPUT.size();i++){
					//if multiplication or division operator found
					if((INPUT.at(i)=='*' || INPUT.at(i)=='/') && Found){
						a=i;
						Found=false;
					}
				}
				if(Found==false){
					int b=0;
					int newsize=INPUT.size();

					for(int i=1;i<a;i++){
						//if the character inspected is an operator (+, -, *, /)
						if(INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/'){
							b=i+1;
						}
					}
					int lens=a-b;//size

					string A11=INPUT.substr(b,lens);//string with size
					left=&A11;//pointer

					bool fix2=true;
					for(int i=a+2;i<INPUT.size();i++){
						//if the character inspected is an operator (+, -, *, /)
						if((INPUT.at(i)=='+'|| INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/')&&fix2){
							newsize=i;
							fix2=false;
						}
					}
					int lenss=newsize-(a+1);
					string A22=INPUT.substr(a+1,lenss);
					right = &A22;

					//if the character inspected is a multiplication operator (*)
					if(INPUT.at(a)=='*'){
						//Evaluate product
						Multiplication myMultiplication;
						string Newvalue = myMultiplication.evaluate(*left, *right);
						int len1=b-0;//get size
						int len2=INPUT.size()-newsize;//get size
						//Create substring of remainder of expression
						INPUT=INPUT.substr(0,len1)+Newvalue+INPUT.substr(newsize,len2);
					}
					
					//if the character inspected is a division operator (/)
					else if(INPUT.at(a)=='/'){
						//Evaluate quotient
						Division myDivision;
						string Newvalue = myDivision.evaluate(A11, A22);
						int len1=b-0;//size
						int len2=INPUT.size()-newsize;//size
						//Create substring of remainder of expression
						INPUT=INPUT.substr(0,len1)+Newvalue+INPUT.substr(newsize,len2);
					} if


				}
			}

			bool Found1=false;
			while(!Found1){
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
				//if the character inspected is an addition or subtraction operator (+, -)
				if((INPUT.at(i)=='+' || INPUT.at(i)=='-') && Found1){
					a=i;
					Found1=false;
				}
			}
			if(Found1==false){
				int b=0;
				int c=INPUT.size();// grab size

				for(int i=1;i<a;i++){
					//if the character inspected is an operator (+, -, *, /)
					if(INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/'){
						b=i+1;
					}
				}

				int lengthh=a-b;//create new size
				string A13=INPUT.substr(b,lengthh);//create substring of new size
				left=&A13;//create pointer to left side of new substring

				bool fix3=true;
				for(int i=a+1;i<INPUT.size();i++){
					//if the character inspected is an operator (+, -, *, /)
					if((INPUT.at(i)=='+' || INPUT.at(i)=='-' || INPUT.at(i)=='*' || INPUT.at(i)=='/')&& fix3){
						c=i;
						fix3=false;
					}
				}
				int llen=c-(a+1);//create new size
				string A14=INPUT.substr(a+1,llen);//create substring of new size
				right =&A14;//create pointer to the right side of new substring

				//if the character inspected is an addition operator (+)
				if(INPUT.at(a)=='+'){
					//Evaluate sum
					Addition myAddition;//object
					string value = myAddition.evaluate(A13, A14);
					int len1=b-0;//get size
					int len2=INPUT.size()-c; //get size
					//Create substring of remainder of expression
					INPUT=INPUT.substr(0,len1)+value+INPUT.substr(c,len2);
				}

				//if the character inspected is a subtraction operator (-)
				else if(INPUT.at(a)=='-'){
					//Evaluate difference
					Subtraction mySubtraction;
					string value = mySubtraction.evaluate(*left, *right);
					int len1=b-0;//size
					int len2=INPUT.size()-c;//size
					//Create substring of remainder of expression
					INPUT=INPUT.substr(0,len1)+value+INPUT.substr(c,len2);
				}


			}
		}

    }

    for(int i=1; i<INPUT.size();i++){
		//if the character inspected is an operator or a right bracket (+, -, *, /, ))
        if ((INPUT.substr(i,1)=="+") || (INPUT.substr(i,1)=="-") || (INPUT.substr(i,1)=="*") || (INPUT.substr(i,1)=="/") || (INPUT.substr(i,1)==")")){
            string *equation1;
            equation1=&INPUT;
			
			//evaluate entire expression
            ArithmeticExpression test;
            test.evaluate(*equation1);
			
			//deallocate memory
            equation1=NULL;
            delete equation1;

        }

    }
    if(INPUT=="-0" && INPUT.size()==2){
        INPUT="0";
    }

	//Deallocate memory
    left=NULL;
    delete left;
    right=NULL;
    delete right;

    return INPUT;
}
//Deallocate memory
ArithmeticExpression::~ArithmeticExpression(){}


