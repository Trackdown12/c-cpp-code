#include<iostream>
using namespace std;
class complex{
    int a;
    int b;
    public:
        void setdata(int x, int y){
            a=x;
            b=y;
        }
        void getdata(void){
            cout<<a<<b<<endl;
        }
        complex add(complex c){
            complex temp;
            temp.a=a+c.a;
            temp.b=b+c.b;
            return temp; 
        }
};
int main(){
    complex c1,c2,c3;
    c1.setdata(3,4);
    c2.setdata(4,6);
    c3=c2.add(c1);
    c3.getdata();
    return 0;
}