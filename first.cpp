#include<iostream>
using namespace std;
 int main()
 { //***************if else statements*************
 /*  int age;
   cout<<"enter your age";
   cin>>age;
   if(age>18){
      cout<<"yes your are eligible";
   }
   else if (age==18)
   {
      cout<<"you are eligible too";
   }
   else{
      cout<<"get lost buddy";
   }*/
   //***************** switch case statement*************
   char opr;
   int a=6,b=3;
   cout<<"enter the operator you want"<<endl;
   cin>>opr;
   switch(opr)
   {
      case '+':
         cout<<"the sum is"<<a+b;
         break;
      case '-':
         cout<<"the sub is"<<a-b;
         break;
      case '*':
         cout<<"the mul is"<<a*b;
         break;
      case '/':
         cout<<"the div is"<<a/b;
         break;
      case '%':
         cout<<"the rem is"<<a%b;
         break;            
      default:
         cout<<"error bro, next time change your operator";
         break;   
   }
   
   return 0;
 }