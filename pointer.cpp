#include<iostream>
using namespace std;
int main(){
    int a=3;
    int* p=&a;
    //the address of a can be shown by this
    cout<<"the address of a is:"<<p<<endl;
    cout<<"the address of a is:"<<&a<<endl;
    //the value can be shown by
    cout<<"the value of a is:"<<*p<<endl;
    
    //pointer to pointer
    int** c= &p;
    cout<<"the address of p is"<<&p<<endl;
    cout<<"the value holded by c is"<<p<<endl;
    cout<<"the value of p is"<<*c<<endl;
    cout<<"the value at address of c is"<<**c<<endl;

    return 0;
}