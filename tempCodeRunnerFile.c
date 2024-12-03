#include <stdio.h>
#include <stdlib.h>
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
} *root = NULL;

struct tree *create(int value)
{
    struct tree *t = (struct tree *)malloc(sizeof(struct tree));
    if (!t)
    {
        printf("MEMORY ALLOCATION FAILED");
    }
    else
    {
        t->data = value;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
}

struct tree *insert(struct tree *root, int value)
{
    if (root == NULL)
    {
        return create(value);
    }
    else if (root->data >= value)
    {
        root->left = insert(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct tree *t)
{
    if (t == NULL)
    {
        return;
    }
    inorder(t->left);
    printf("%d\t", t->data);
    inorder(t->right);
}
void postorder(struct tree *t)
{
    if (t == NULL)
    {
        return;
    }
    postorder(t->left);
    postorder(t->right);
    printf("%d\t", t->data);
}

void preorder(struct tree *t)
{
    if (t == NULL)
        return;
    printf("%d\t", t->data);
    preorder(t->left);
    preorder(t->right);
}

void search(struct tree *t, int x)
{
    while (t != NULL)
    {
        if (t->data == x)
        {
            printf("element %d is found.\n", x);
            break;
        }
        else if (x > t->data)
        {
            t = t->right;
        }
        else
        {
            t = t->left;
        }
    }
    if (t == NULL)
    {
        printf("the element %d is not found.\n", x);
    }
}
struct tree *inorder_successor(struct tree *t)
{
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t;
}

void leafdel(struct tree *t, struct tree *parent)
{
    if (t == parent->left)
    {
        parent->left == NULL;
    }
    else
    {
        parent->right = NULL;
    }
    free(t);
    t = NULL;
}

void onechilddel(struct tree *t, struct tree *parent)
{
    if (t == parent->left)
    {
        if (t->left != NULL)
        {
            parent->left = t->left;
        }
        else if (t->right != NULL)
        {
            parent->left = t->right;
        }
    }
    else if (t == parent->right)
    {
        if (t->left != NULL)
        {
            parent->right = t->left;
        }
        else if (t->right != NULL)
        {
            parent->right = t->right;
        }
    }
    free(t);
    t = NULL;
}

void twochilddel(struct tree*t,struct tree *parent){
    struct tree * temp=inorder_successor(t->right);
    struct tree *tempParent=t->right;
    if (temp != tempParent) { 
        while (tempParent->left != temp) { 
            tempParent = tempParent->left; 
        } 
    } 
    t->data = temp->data;
    if (temp->right!=NULL){
        onechilddel(temp,tempParent);
    }
    else if(temp->right==NULL){
        leafdel(temp,tempParent*);
    }

}

void deletenode(struct tree *t, int x)
{
    if (t == NULL)
    {
        printf("EMPTY TREE\n");
        return;
    }
    struct tree *parent = NULL;
    while (t != NULL)
    {
        if (t->data == x)
        {
            break;
        }
        parent = t;
        if (x > t->data)
        {
            t = t->right;
        }
        else
        {
            t = t->left;
        }
    }
    if (t == NULL)
    {
        printf("element %d does not exist\n", x);
        return;
    }
    else if (t->left != NULL && t->right != NULL)
    {
       twochilddel(t,parent);
    }
    else if (t->left != NULL)
    {
        onechilddel(t,parent);
    }
    else if (t->right != NULL)
    {
        onechilddel(t,parent);
    }
    else
    {
        leafdel(t, parent);
    }
    printf("TREE inorder:\n");
    inorder(root);
    printf("\n");
}

void max(struct tree *t){
    while(t->right!=NULL){
            t=t->right;
        }
    printf("max element:%d\n",t->data);
}

void min(struct tree *t){
    while(t->left!=NULL){
        t=t->left;
    }
    printf("min element:%d\n",t->data);
}

int main()
{
    root = insert(root, 50);
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 25);
    insert(root, 60);
    insert(root, 70);
    insert(root, 55);
    insert(root, 53);
    search(root, 55);
    insert(root,65);
    insert(root,72);
    printf("root->data=%d\n", root->data);
    printf("inorder traversal\n");
    inorder(root);
    printf("\n");
    printf("postorder traversal\n");
    postorder(root);
    printf("\n");
    printf("preorder traversal\n");
    preorder(root);
    printf("\n");
    deletenode(root,60);
    printf("inorder successor=%d\n", inorder_successor(root->right)->data);
    max(root);
    min(root);
    //deletenode(root, 20);
    postorder(root);
    return 0;
}
