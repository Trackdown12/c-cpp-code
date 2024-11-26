#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * pre;
    int data;
    struct node*next;
};
struct node * head;
struct node * tail;
void peek_tail(){
    if (tail==NULL){
        printf("NULL\n");
        return;
    }
    printf("%d\n",tail->data);
}
void head_tail(){
    if (head==NULL){
        printf("NULL\n");
        return;
    }
    printf("%d\n",head->data);
}
void display(){
    if (head==NULL){
        printf("underflow\n");
        return;
    }
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    if (temp==NULL){
        printf("NULL\n");
    }
}

void insert_spec(int value, int index){
    if (head==NULL && index!=0){
        printf("index out of range!!! no list exists\n");
        return;
    }
    struct node *temp=head;
    for (int i=0;i<=index;i++){
        if (i==index){
            struct node *n=(struct node*)malloc(sizeof(struct node));
            n->data=value;
            if (head==NULL){
                n->pre=head;
                n->next=tail;
                head=n;
                tail=n;
                break;
            }
            else{
                if (temp==tail){
                    n->pre=tail;
                    n->next=NULL;
                    tail=n;
                    break;
                }
                else{
                    n->pre=temp->pre;
                    n->next=temp;
                    n->pre->next=n;
                    temp->pre=n;
                    break;
                }
            }
    }
    if (temp==NULL){
        printf("index out of range");
        break;
    }
    temp=temp->next;
}
}
int main(){
    peek_tail();
    insert_spec(12,0);
    insert_spec(12,0);
    display();
    return 0;
}