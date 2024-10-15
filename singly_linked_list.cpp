#include<iostream>
#include<stdlib.h>
//************singly linked list***************/
struct node{
    int data;
    struct node *next;
};

struct node * head=NULL;
struct node * tail=NULL;

void insert_front(int value){
    node *n=(node*)malloc(sizeof(node));
    if (!n){
        printf("overflow \n");
        return;
    }
    n->data=value;
    n->next=head;
    head=n;
    if ( tail==NULL){
        
        tail=n;
        
    }
    
}

void insert_back(int value){
    node *n=(node*)malloc(sizeof(node));
    if (!n){
        printf("overflow \n");
        return;
    }
    n->data=value;
    n->next=NULL;
    if (head==NULL){
        head=n;
        tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}


int pop_front(){
    if (head==NULL){
        printf("overflow");
        return -1;
    }
    node * temp=head;
    int value=head->data;
    head=head->next;
    free(temp);
    return value;
}

int pop_back(){
    if (head == NULL){
        printf("underflow:");
        return -1;
    }
    int value=tail->data;
    if (head==tail){
        free(tail);
        head=NULL;
        tail=NULL;
    }
    else{
        node *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        free(tail);
        tail=temp;
        tail->next=NULL; 
    }
    return value;
}

void display(){
    if (head==NULL){
        printf("underflow\n");
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void peek_head(){
    if(head==NULL){
        printf("undeflow\n");
        return; 
    }
    printf("head = %d\n",head->data);
}

int search(int value){
    if (head== NULL){
        printf("underflow");
        return -1;
    }
    node * temp=head;
    int index=0;
    while(temp!=NULL){
        if (temp->data==value){
            printf("present at index:");
            return index;
        }
        temp=temp->next;
        index++;
    }
    return -1;
}

void peek_tail(){
    if(head==NULL){
        printf("undeflow\n");
        return; 
    }
    printf("tail = %d\n",tail->data);
}

void reverse(){
    node* pre=NULL;
    node* cur=head;
    node* next=NULL;
    tail=cur;
    if (head==NULL){
        printf(" ***reverse not possible***\n");
    }
    else{
        printf("****reverse successfull****\n");
    }
    while(cur!= NULL){
        next=cur->next;
        cur->next=pre;
        //updation
        pre=cur;
        cur=next;
    }
    head=pre;
}

void insert_pos(int value,int index=0){
    node *n=(node*)malloc(sizeof(node));
    if(!n){
        printf("overflow\n");
        return;
    }
    n->data=value;
    n->next=NULL;
    if (index==0 || head==NULL){
        n->next=head;
        head=n;
        if(tail==NULL){
            tail=n;
        }
    }
    else{
        node *temp=head;
    for(int ind=0;ind<index-1;ind++){
        if (temp==NULL){
            printf("!!invalid position!!");
            free(n);
            return;
        }
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    if (n->next==NULL){
        tail=n;
    }
    }     
}

void index(int ind){
    if(head==NULL){
        printf("underflow\n");
        return;
    }
    node* temp=head;
    for(int i=0;i<=ind;i++){
        if(temp==NULL ){
            printf("out of index\n");
            break;
            return;
        }
        if (i==ind){
            printf("at index %d : %d\n",ind,temp->data);
            break;
        }
        temp=temp->next;
    }
    
}

void delete_pos(int index){
    if(head==NULL){
        printf("underflow\n");
        return;
    }
    if (index == 0) {
        printf("Item deleted at index %d: %d\n", index, head->data);
        node *temp = head;
        head = head->next;
        free(temp);
        if (head == NULL) { // If the list becomes empty
            tail = NULL;
        }
        return;
    }
    node * temp=head;
    node * prev=head;
    int i=0;
    while(temp!=NULL && i<index){
       prev = temp;
        temp = temp->next;
        i++;
    }

    // If we reached the end and the index is out of bounds
    if (temp == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    // Perform deletion
    printf("Item deleted at index %d: %d\n", index, temp->data);
    prev->next = temp->next; // Link previous node to next node
    free(temp);

    // Update tail if necessary
    if (prev->next == NULL) {
        tail = prev; // Update tail if last node is deleted
    }
}

void delete_list(){
    if(head==NULL){
        printf("underflow\n");
        return;
    }
    node * temp=head;
    node * pre=NULL;
    while(temp!=NULL){
        node * pre=temp;
        temp=temp->next;
        printf("deleting nodes :%d\n",pre->data);
        free(pre);
    }
    free(temp);
    head=tail=NULL;
}

int main(){
    int choice,item,pos;
    while(1){
        printf("1:push front\n");
        printf("2:pop back\n");
        printf("3:peek head\n");
        printf("4:peek tail\n");
        printf("5:display\n");
        printf("6:exit\n");
        printf("7:push back\n");
        printf("8:pop front\n");
        printf("9:search\n");
        printf("10:reverse\n");
        printf("11:insert at any position(value,index)\n");
        printf("12:index\n");
        printf("13:delete at index\n");
        printf("14:delete list\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter element:");
            scanf("%d",&item);
            insert_front(item);
            printf("\n");
            break;
        case 2:
            printf("popped:%d\n",pop_back());
            break;
        case 3:
            peek_head();
            break;
         case 4:
            peek_tail();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        case 7:
            printf("enter element:");
            scanf("%d",&item);
            insert_back(item);
            printf("\n");
            break;
        case 8:
            printf("popped:%d\n",pop_front());
            break;
        case 9:printf("enter element:");
            scanf("%d",&item);
            printf("%d\n",search(item));
            break;
        case 10:
            reverse();
            break;
        case 11:
            printf("enter element:");
            scanf("%d",&item);
            printf("enter pos:");
            scanf("%d",&pos);
            insert_pos(item,pos);
            printf("\n");
            break;    
        case 12:
            printf("enter index :");
            scanf("%d",&item);
            index(item);
            break;
        case 13:
            printf("enter index :");
            scanf("%d",&item);
            delete_pos(item);
            break;
        case 14:
            delete_list();
            break;
        default:
            printf("!invalid input!\n");
            break;
        }
    }
}