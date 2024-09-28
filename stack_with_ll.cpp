//implementation of stacks using linked list so that memory will be allocated dynamically
#include<iostream>
#include<stdlib.h>
using namespace std;
//creating a structure  
//stack will be created like this [value:address]. lets suppose stack which have three values
//[value3:address of 2nd node]         : [value3] 
//[value2:address of 2nd node]         : [value2]
//[value1:NULL]                        : [value1]
struct stack{
    int value;//value to be ushed in stack
    struct stack * next;//a structure stack type pointer to store the address of next structure  
};
struct stack*top=NULL;// a structure stack type top pointer initially holding null value shows stack is empty

bool empty(){// a bool return type function to check whether the stack is empty or not
    if (top==NULL){//condition{if top has nothing it means it is empty}
        return true;
    }
    return false;
}



// *** it is based on structure so remember the actual concept as it is so coinfusing at first*****
void push(int x){//void return type function to push the element into stack
    stack* n;//a stack type pointer initialised to allocate memory
    n=(stack*)malloc(sizeof(stack));//allocating memory for stack
    if (!n){//checking overflow
        cout<<"overflow"<<endl;
        return;
    }
    n->value=x;//putting value into stack
    n->next=top;//pushing address of current top into address of the newly allocated top here a link have been created between two nodes 
    top=n;//assinging newly formed structure as top

}

int pop(){//pop function
    if (empty()){//checking underflow 
        cout<<"underflow"<<endl;
        return -1;
    }
    stack* n;//same as above  & will be used to show the popped value
    n=top;//putting top into n coz we have to delete top later and show the deleted value too
    top=top->next;//shifting the top 
    int x=n->value;//storing value of the n which have the value of the top before deletion
    free(n);//freeing memory
    return x;//returning popped value
}
 
void display(){// funtion to display stack
    if (empty()){//checking underflow
        cout<<"underflow"<<endl;
        return;
    }
    stack *n=top;//assinging topinto n so that we can manipulate n without harming top
    while(n!=NULL){// as the node have null value we will traverse linked list until address in n becomes null
        cout<<n->value<<endl;//printing value
        n=n->next;//changing n via address
    }
}

void peek(){//function to show top value
    if (empty()){//checking underflow
        cout<<"underflow"<<endl;
        return;
    }
    cout<<"top="<<top->value<<endl;//printing value in the top as top is a struct stack type pointer too
}
// main program 
int main(){
    int choice,item;
    while(1){
        cout<<"1:push"<<endl;
        cout<<"2:pop"<<endl;
        cout<<"3:peek"<<endl;
        cout<<"4:display"<<endl;
        cout<<"5:exit"<<endl;
        cout<<"enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter element";
            cin>>item;
            push(item);
            break;
        
        case 2:
            cout<<"popped:"<<pop()<<endl;
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"!invalid input!"<<endl;
            break;
        }
    }
}