#include<iostream>
#include<stdlib.h>
using namespace std;
class Queue{
    int queue[5];
    int f,r,count=0;
    public:
        Queue(){
            f=0;
            r=-1;
        }

        void enqueue(int a){
            if (count==5){
                cout<<"overflow";
                exit(0);
            }
            r=(r+1)%5;
            queue[r]=a;
            count++;
        }

        bool empty(){
            if (count==0){
                return true;
            }
            else{
                return false;
            }
        }
        void dequeue(){
            if (empty()){
                cout<<"underflow";
                exit(0);
            }
            cout<<"dequeued"<<queue[f]<<endl;
            f=(f+1)%5;
            count--; 
              
        }
        void front(){
            if (empty()){
                cout<<"undeflow";
                exit(0);
            }
            cout<<"front="<<queue[f]<<endl;
        }
        void rear(){
            if (empty()){
                cout<<"undeflow";
                exit(0);
            }
            cout<<"rear="<<queue[r]<<endl;
        }
        void print_Q(){
            if (empty()){
                cout<<"underflow";
                exit(0);
            }
            for (int i=0;i<count;i++){
                cout<<queue[(f+i)%5]<<"\t";
            }
            cout<<endl;
        }

};

int main(){
    Queue a;
    int choice,item;
    while (true){
        cout<< " please select something from below:" << endl;
        cout<< " 1:enqueue \n 2:dequeue \n 3:front \n 4:rear \n 5:print 6:exit" << endl;
        cout<<" enter choice:";
        cin>>choice;
        switch (choice){
            printf("hi");
            case 1:
                cout<<"enter element:";
                cin>>item;
                a.enqueue(item);
                break;
            case 2:
                a.dequeue();
                break;
            case 3:
                a.front();
                break;
            case 4:
                a.rear();
                break;
            case 5:
                a.print_Q();
                break;
            case 6:
                exit(0);
                break;
            default:
            cout<<"wrong choice !"<<endl;
        }
    }
    return 0;
}