#include<stdlib.h>
#include<iostream>
using namespace std;
int a[10];
int front=-1,rear=-1;
bool empty(){
    if (front>rear ||front==-1){
        return true;
    }
    else return false;
}

void insert_Front(int b){
    if (front==0){
        cout<<"front overflow"<<endl;
        return;
    }
    if (front==-1){
        front=0;
        rear=0;
    }
    else{
    front--;
    }
    a[front]=b;
}

void insert_Rear(int b){
    if (rear==9){
        cout<<"rear overflow"<<endl;
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else{
        rear++;
        }
    a[rear]=b;
}

void front_pop(){
    if (empty()){
        cout<<"underflow"<<endl;
        return;
    }
    cout<<"popped item:"<<a[front]<<endl;
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }
}

void rear_pop(){
    if (empty()){
        cout<<"underflow"<<endl;
        return;
    }
    cout<<"popped item:"<<a[rear]<<endl;
    rear--;
    if (front>rear){
        front=-1;
        rear=-1;
    }
}

void display(){
    if (empty()){
        cout<<"underflow"<<endl;
        return;
    }
    cout<<"************************DISPLAYING QUEUE************************"<<endl;
    for (int i=front;i<=rear;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int choice,item;
    while(1){
        cout<<"1:front_push"<<endl;
        cout<<"2:rear_push"<<endl;
        cout<<"3:front_pop"<<endl;
        cout<<"4:rear_pop"<<endl;
        cout<<"5:display"<<endl;
        cout<<"6:exit"<<endl;
        cout<<"enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter element:";
            cin>>item;
            insert_Front(item);
            break;
        
        case 2:
            cout<<"enter element:";
            cin>>item;
            insert_Rear(item);
            break;
        case 3:
            front_pop();
            break;
        case 4:
            rear_pop();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"!invalid input!"<<endl;
            break;
        }
    }
    return 0;
}