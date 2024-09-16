#include<iostream>
using namespace std;
struct student
{
    /* data */
    string name;
    int roll_no;
    float percentage;
};

int main(){
    student vinay;
    vinay.name="Vinay Kumar";
    vinay.roll_no=45;
    vinay.percentage=74.45;
    cout<<"the name is:"<<vinay.name;
    return 0;
}