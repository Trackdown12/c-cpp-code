#include<iostream>
using namespace std;
int main(){
    int a=3;
  //***************for loop*********************************
  //  for ( int i = 1; i <= 10; i++)
  //  {
  //      cout<<"3 * "<<i<<" = "<< a*i<<endl;
  //      
  //  }
    //example of infinite loop
    /*for (int i=1;34<40;i++){
        cout<<i<<endl;
    }*/
  //***************while loop*********************
//  int i=1;
//  while (i<=10)
//  {
//    cout<<a*i<<endl;
//    i++;
//  }
// ******************do-while loop********
int i=1;
do
{
  cout<<a*i<<endl;
  i++;
} while (i<=10);
 
    
    return 0;
}