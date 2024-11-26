#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *pre;
    struct node *next;
};
struct node * head=NULL;
struct node * tail=NULL;

void insert_beg(int value){
    struct node * n =(struct node*)malloc(sizeof(struct node));
    if (!n){
        printf("overflow\n");
        return;
    }
    n->pre=NULL;
    n->data=value;
    n->next=head;
    if (head!=NULL){
        head->pre=n;
    }
    else{
        tail=n;
    }
    head=n;
}

void insert_pos(int value, int index) {
    struct node *temp = head;
    
    for (int i = 0; i <= index; i++) {
        if (i == index) {
            struct node *n = (struct node*)malloc(sizeof(struct node));
            n->data = value;
            
            if (head == NULL) {
                // If the list is empty
                n->next = NULL;
                n->pre = NULL;
                head = tail = n;
            } else {
                // Insert in a non-empty list
                n->pre = temp->pre;
                n->next = temp;
                
                if (temp->pre != NULL) {
                    temp->pre->next = n;
                } else {
                    head = n;
                }
                temp->pre = n;
                
                if (temp->next == NULL) {  
                    // Updating the tail if inserting at the end
                    tail = n;
                }
            }
            break;
        }
        
        if (temp == NULL) {
            printf("Index out of range\n");
            break;
        }
        
        temp = temp->next;
    }
}

void insert_end(int value){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    n->pre=tail;
    if (tail!=NULL){
        tail->next=n;
    }
    tail=n;
    if (head==NULL){
        head=n;
    }
}

void pop_front(){
    if (head==NULL){
        printf("underflow\n");
        return;
    }
    struct node*temp=head;
    printf("popped:%d\n",temp->data);
    head=head->next;
    free(temp);
    if (head==NULL){
        tail=NULL;
        return;
    }
    head->pre=NULL;
}
void popback(){
    if (head==NULL){
        printf("underflow \n");
        return;
    }
    struct node *temp=tail;
    if(head==tail){
        printf("hi");
        head=NULL;
    }
    tail=tail->pre;
    tail->next=NULL;

    
    free(temp);

}


void display_forward(){
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

void display_back(){
    if (head==NULL){
        printf("underflow\n");
        return;
    }
    struct node *temp=tail;
    printf("NULL ");
    while(temp!=NULL){
        printf("<-%d",temp->data);
        temp=temp->pre;
    }
    printf("\n");
}



void peek_head(){
    if (head==NULL){
        printf("undeflow\n");
        return;
    }
    printf("head=%d\n",head->data);
}

void peek_tail(){
    if (head==NULL){
        printf("underflow\n");
        return;
    }
    printf("tail=%d\n",tail->data);
}

int main(){
    insert_beg(10);
    peek_head();
    popback();
    peek_head();
    display_forward();
    

    return 0;
} 