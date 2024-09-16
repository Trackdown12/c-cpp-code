#include <iostream>/*this is to  import iostream header file for standard input output*/
#include <stdlib.h>/*stands for  standard library header file used for  memory managemen and process control as we have used exit(0) to exit function and while loop which will work ifinitely otherwise*/
#define n 100 /*defining macros n=100*/
using namespace std;
int a[n];/*declared array*/
int rear =-1;/*declared a global variable rear so that we can use it in our queue for inserting element or checking last element. it is initialized as -1 which shows queue is empty right now */
int front=-1;/*declared a global variable front so that we can use it in our queue for inserting element or checking first element. it is initialized as -1 which shows queue is empty right now */

void enqueue(int b)/*here we have declared and defined a function with void return type that will insert element at the end of the queue*/
{
    if (rear == n - 1)/*checking condition overflow */
    {
        cout << "overflow" << endl;
        exit(0);/*it will terminate function immediately if condition is true */
    }
    if (front == -1 && rear == -1)/*it will check whether queue is empty or not bcoz we have to increase front value too while inserting first element */
    {/*this part will increase both front and rear by 1 if condition is true*/
        front++;
        rear++;
    }
    else/*this part will just increase rear element by 1 if condition is false */
    {
        rear++;
    }
    a[rear] = b;/*inserting element to the end of queue*/
}

int dequeue()/*declared and defined a function with int return type to delete element from the start of queue*/
{
    int data;/*declared a temporary local variable data*/
    if (front > rear || front == -1)/*checking condition of underflow*/
    {
        cout << "underflow" << endl;
        exit(0);/*terminating function immediately if condition is true*/
    }
    data = a[front];/*storing the value of rear element to  show the removed element later*/
    front++;/*increasing front by 1 which shows that last element is now not the part of queue as elements of array can be overwritten but here when we will print queue later we will just print from front to rear which will refer that every deleted element  is not a part of queue  */
    return data;/*returning deleted element*/
}

void peek()/*declared and defined a function with void retun type which will show front and rear element of queue*/
{
    if (front > rear || front == -1)/*checking underflow condition it will work as same as in dequeue */
    {
        cout << "underflow" << endl;
        exit(0);
    }
    cout << " front=" << a[front] << endl;/*printing front value of queue*/
    cout << " rear=" << a[rear] << endl;/*printing rear value of queue*/
}

void print()/*declared and defined a function with void retun type which will print whole queue*/
{
    if (front > rear || front == -1)/*checking underflow condition it will work as same as in dequeue */
    {
        cout << "underflow" << endl;
        exit(0);
    }
    for (int i = front; i <= rear; i++)/*using loop to print queue*/
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main()/*main function*/
{
    int choice, item;/*declartion of variable of int data type*/
    while (true)/*using infinite loop bcoz we don't know when to exit  */
    {
        cout << " please select something from below:" << endl;
        cout << " 1:enqueue \n 2:dequeue \n 3:peek \n 4:print \n 5:exit" << endl;
        cout << " Enter your choice: ";
        cin >> choice;
        switch (choice)/*using switch case as it has less complexity when the no. of cases are definite as it uses algo of jump table and binary tree */
        {
        case 1:/*case 1 to insert element*/
            cout << "enter element to insert:";
            cin >> item;
            enqueue(item);
            break;
        case 2:/*case 2 to delete element*/
            cout <<"deleted item:"<< dequeue() << endl;
            break;
        case 3:/*case 3 to peek front and rear element*/
            peek();
            break;
        case 4:/*case 4 to print every element present in queue */
            print();
            break;
        case 5:/*case 5 to exit loop or stop the functioning of queue*/
            exit(0);
            break;
        default:/*default msg in case of user choose out of index choice  */
            cout<<" invalid input,please check the list of operation you can perform"<<endl;
            break;
        }
        
    }/*end of switch-case statement */

    return 0;
}/*end of main function*/