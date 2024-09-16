#include<stdio.h>
#include<stdlib.h>
#define n 10
int stack[n];
int top=-1;
void push(int value){
   if(top==n-1){
    printf("overflow");
    exit(0);
   }
   top++;
   stack[top]=value; 
}
int pop(){
    int data;
    if(top==-1){
    printf("underflow");
    exit(0);   
   }
   data=stack[top];
   top--;
   return data;
}
void print(){
    int i;
    if(top==-1){
    printf("underflow");
    exit(0);   
   }
   printf("the stack is\n");
   for (i=top;i>=0;i--){
    printf("%d\n",stack[i]);
   }
}
int peek(){
    if(top==-1){
    printf("underflow");
    exit(0);   
   }
   return stack[top];
}
int main(){
    int choice,item;
    while(1){
        printf("1.push\n 2.pop\n 3.print\n 4.peek\n 5.exit\n");
        printf("select choice:");
        scanf("%d",&choice);
        if(choice==1){
            printf("enter item:");
            scanf("%d",&item);
            push(item);
        }
        else if(choice==2){
            printf("deleted item is %d",pop());
        }
        else if(choice==3){
            print();
        }
        else if(choice==4){
            printf("top of stack is %d",peek());
        }
        else if(choice==5){
            exit(0);
        }
        else{
            printf("invalid input");
        }
    }
    return 0;
}