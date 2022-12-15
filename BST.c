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
treeNode *createNode(int);
treeNode *insert(treeNode*, int);
treeNode *findMax(treeNode*);
treeNode *findMin(treeNode*);
treeNode *delete(treeNode*, int);
treeNode *search(treeNode*, int);
int main(){
    treeNode *root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 8);
    insert(root, 9);
    insert(root, 5);
    insert(root, 6);
    insert(root, 3);
    preOrderTraverse(root);
    printf("\n");
    delete(root, 8);
    delete(root, 20);
    preOrderTraverse(root);
    printf("\n");
    inOrderTraverse(root);
    printf("\n");
    postOrderTraverse(root);
    printf("\n");
    int a =30;
    (search(root, a) != NULL) ? printf("%d key found\n", a) : printf("%d key not found\n", a);
    a = 20;
    (search(root, a) != NULL) ? printf("%d key found\n", a) : printf("%d key not found\n", a);
    // if(search(root, 20) !=NULL)
    //     printf("%d key found\n", 20);
    // else
    //     printf("%d key not found\n", 20);
}
treeNode *createNode(int data){
    treeNode *node = malloc(sizeof(treeNode));
    if(node != NULL){
        node->data=data;
        node->left=node->right= NULL;
    }
    return node;
}
treeNode *insert(treeNode *root, int data){
    if(root == NULL)
        return createNode(data);
    if(data < root->data)
       root->left= insert(root->left, data);
    if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}
treeNode *findMax(treeNode *root){
    if(root->right == NULL)
        return root;
    else
        return findMax(root->right);
}
treeNode *findMin(treeNode *root){
    if(root->left == NULL)
        return root;
    else
        return findMax(root->left);
}
treeNode *delete(treeNode *root, int key){
    if(root == NULL)
        return NULL;
    else if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else{
        //case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //case 2: single child
        else if(root->left == NULL){
            treeNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            treeNode *temp = root;
            root = root->left;
            free(temp);
        }
        //case 3: 2 children
        else{
            //from left side
            treeNode *temp = findMax(root->left);
            root->data = temp->data;
            root->left = delete(root->left, temp->data);
            /*
            //from right side
            treeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            */
        }
    }
    return root;        
}
treeNode *search(treeNode *root, int key){
    if(root == NULL)
        return NULL;
    else if(key == root->data)
        return root;
    else if(key < root->data)
        return search(root->left , key);
    else
        return search(root->right, key);
}