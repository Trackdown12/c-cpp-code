#include<iostream>
#include<string>
using namespace std;

class binary
    {
    string s;
        
    public:
        void read(void);
        void chk_bin(void);
        void display(void){
            cout<<"the binary number is"<<endl;
            for (int i = 0; i < s.length(); i++)
            {
                
                cout<<s.at(i);
            }
            cout<<endl;
        }
        void ones_compliment(void){
            for (int i=0;i<s.length();i++){
                if (s.at(i)=='0')
                {
                    s.at(i)='1';
                }
                else{
                    s.at(i)='0';
                }
            }
        }
    };
void binary :: read(void){
    cout<<"enter a binary number"<<endl;
    cin>>s;
}    
void binary :: chk_bin(void){
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"incorrect binary foramt at"<<i<<endl;
            exit(0);
        }
        
    }
    
}
int main(){
    binary b;
    b.read();
    b.chk_bin();
    b.display();
    b.ones_compliment();
    b.display();
    return 1;
}