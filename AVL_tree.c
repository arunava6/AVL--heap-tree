#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
int max(int a,int b);
// Calculate height
int height(struct node *N){
    if(N==NULL)
    return 0;
    return N->height;
}
int max(int a,int b){
    return(a>b)?a:b;
}
// create Node
struct node *newnode(int key){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return (node);
}
// Right node
struct node *rightrotate(struct node *y){
    struct node *x=y->left;
    struct node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
//Left node
struct node *leftrotate(struct node *x){
    struct node *y=x->right;
    struct node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
// Get the balance factor
int balance_factor(struct node *N){
    if(N==NULL)
    return 0;
    return height(N->left)-height(N->right);
}
// Insert Node
struct node *insertNode(struct node *node,int key){
    //Find the correct position to insert the node 
    if(node==NULL)
    return(newnode(key));
    if(key<node->key)
    node->left=insertNode(node->left,key);
    else if(key>node->key)
    node->right=insertNode(node->right,key);
    else
    return node;
    // Update the balnace factor of each node
    // Balance the Tree
    node->height=1+max(height(node->left),height(node->right));
    int balance=balance_factor(node);
    if(balance>1 && key<node->left->key)
    return rightrotate(node);
    if(balance< -1 && key>node->right->key)
    return leftrotate(node);
    if(balance>1 && key>node->left->key){
    node->left=leftrotate(node->left);
    return rightrotate(node);
    }
    if(balance< -1 && key<node->right->key){
    node->right=rightrotate(node->right);
    return leftrotate(node);
    }
    return node;
}
struct node *minvalue(struct node* node){
    struct node* current=node;
    while(current->left!=NULL)
    current=current->left;
    return current;
}
// print the tree
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node *root=NULL;
    root=insertNode(root,2);
    root=insertNode(root,1);
    root=insertNode(root,7);
    root=insertNode(root,4);
    root=insertNode(root,5);
    root=insertNode(root,3);
    root=insertNode(root,8);
    preorder(root);
    return 0;
}