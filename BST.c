//implementation of binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct binTreeNode{
    int data;
    struct binTreeNode *left;
    struct binTreeNode *right;
} treeNode;
void preOrderTraverse(treeNode *root){
    if(root!=NULL){
    printf("%d ", root->data);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
    }
}
void inOrderTraverse(treeNode *root){
    if(root!=NULL){
    inOrderTraverse(root->left);
    printf("%d ", root->data);
    inOrderTraverse(root->right);
    }
}
void postOrderTraverse(treeNode *root){
    if(root!=NULL){
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    printf("%d ", root->data);
    }
}
treeNode *insert(treeNode*, int);
int main(){
    treeNode *root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 8);
    insert(root, 9);
    insert(root, 5);
    preOrderTraverse(root);
    printf("\n");
    inOrderTraverse(root);
    printf("\n");
    postOrderTraverse(root);
    printf("\n");
}
treeNode *insert(treeNode *root, int data){
    if(root == NULL){
        root = malloc(sizeof(treeNode));
        root->data=data;
        root->left= root->right= NULL;
        return root;
    }
    if(data < root->data)
       root->left= insert(root->left, data);
    if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}