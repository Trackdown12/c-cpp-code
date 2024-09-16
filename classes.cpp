#include<iostream>
using namespace std;
class employee{
    private:
        int a,b,c;
    public:
        int d,e;
         void setData(/*int a1,int b1,int c1*/);
         //******can be used to set data inside classs*******
    //  void setData(int a1,int b1,int c1){
    //      a=a1;
    //      b=b1;
    //      c=c1;
    //   }
        //******can be set to print inside the class
        void getData();
    //  void getData(){
    //      cout<<"the value of a is:"<<a<<endl;
    //      cout<<"the value of b is:"<<b<<endl;
    //      cout<<"the value of c is:"<<c<<endl;
    //      cout<<"the value of d is:"<<d<<endl;
    //      cout<<"the value of e is:"<<e<<endl;
    //        
    //  }    
};
//******can be used to set data outside classs*******
void employee :: setData(/*int a1,int b1, int c1*/){
  //  a=a1;
  //  c=c1;
  //  b=b1;
  cout<<"enter value for a"<<endl;
  cin>>a;
  cout<<"enter value for b"<<endl;
  cin>>b;
  cout<<"enter value for c"<<endl;
  cin>>c;
  
}
//******can be used to print data outside classs*******
void  employee :: getData(){
            cout<<"the value of a is:"<<a<<endl;
            cout<<"the value of b is:"<<b<<endl;
            cout<<"the value of c is:"<<c<<endl;
            cout<<"the value of d is:"<<d<<endl;
            cout<<"the value of e is:"<<e<<endl;
              
        } 
int main(){
    employee vinay;
    vinay.d=34;
    vinay.e=324;
    vinay.setData(/*1,2,3*/);
    vinay.getData();
    return 0;
}