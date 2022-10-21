
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct _Node {
    int value;
    struct _Node *left;
    struct _Node *right;

};
static Node* realRoot;


void displaySubtree(Node *N){//displays the entire subtree in ascending order
    if(N == NULL || N->value == NULL){//if N is NULL return nothing
        return;
    }
    displaySubtree(N->right);//recursively go through the right subtree i.e visits all the nodes in the right subtree of N
    printf("%d\n",N->value);//print the value in Node N
    displaySubtree(N->left);//recursively go through the left subtree i.e visits all the nodes in the left subtree of N


}
//creates a new node dynamically and returns it
Node* newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp!=NULL){
       temp -> value = data;
       temp -> left = NULL;
       temp -> right = NULL;
    }

    return temp;


}

int Contains(Node *root,int value){
    static int flag = 0;
    Node* temp = root;
    /*if (!temp)
    {
        return;
    }*/
    Contains(temp->left, value);
    if(temp->value == value)
    {
        printf("\nElement present in the binary tree.\n");
        flag = 1;
    }
    Contains(temp->left, value);
    return flag;
    /*while (temp != NULL){
        // checking condition and passing right subtree & recusing
        if (value > temp->value)
            temp = temp->right;

        // checking condition and passing left subtree & recusing
        else if (value < temp->value)
            temp = temp->left;
        else
            temp = NULL;
            return 1;
            // if the value is found return 1

    }
    return 0;*/
}



Node* addNode(Node *root, int value){
    //Creating a new node element
    Node* newnode = newNode(value);
    //trailing pointer to search where the new node will inserted
    Node* x = root;
    //maintains the x pointer and is the current node pointer
    Node* y = NULL;
    while (x != NULL) {//traversing the tree (running a loop starting from the root and running until it is NULL)
            //while x is not NULL until we find the position where leaf will be inserted


        y = x;
        if (value < x->value){//traverses the right if value is less than root value
            x = x->right;
        }
        else if (value > x->value){//traverses the right if value is more than root value
            x = x->left;
        }
        else{//PENDING
            y = NULL;
            newnode = NULL;
            break;
        }
    }

    //if the tree is empty i.e the current node(y) is still empty we assign the new node to it
    //thus the new node is the root node
    if (y == NULL){
        realRoot = newnode;
        y = newnode;
    }

    else if (value > y->value){//if the value of the current node(y) is greater than the value thats to be added recursively go through the left
        y->left = newnode;
    }

    else if (value < y-> value){//if the value of the current node(y) is smaller than the value thats to be added recursively go through the right
        y->right = newnode;
    }


    return newnode;//returning the leaf node


}

Node * removeNode(Node * root, int value){//removes node with given value
    if(root == NULL){//if root is NULL return NULL
        return NULL;
    }
    if(value < root->value){//if Value is greater than root value traverse through right subtree
        root->right = removeNode(root->right,value);
    }
    else if(value > root -> value){//if value is lesser than root value traverse through left subtree
        root->left = removeNode(root ->left,value);
    }
    else{
        Node* temp = NULL;
        if(root->left == NULL && root->right == NULL){//Case1 : if the root to be deleted has no children
            free(root);
            return NULL;
        }
        //Case2: if the root has at least one child
        else if(root->left==NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        //replace with rightmost node in left subtree
        temp = root -> left;
        while(temp && temp->right!=NULL){
            temp = temp->right;
        }
        root -> value = temp->value;
        root -> left = removeNode(root->left,temp->value);
    }
    return root;



}





//checks number of leaves in subtree
int numberLeaves(Node * N){
    if(N == NULL){//if Node is NULL return zero
        return 0;
    }
    if(N ->left == NULL && N -> right == NULL){//if both left child and right child of N are NULL i.e if N dosent have any children then return 1
        return 1;
    }
    else{//else recursively go through the left and right subtrees
        return numberLeaves(N->left) + numberLeaves(N->right);
    }



}
void deleteTree(Node* N){//function to recursively traverse the tree through post traversal and delete each node
    if(N!=NULL){
        deleteTree(N->left);
        deleteTree(N->right);
        N -> value = NULL;
        N -> right = NULL;
        N -> left = NULL;

    }

}
Node * removeSubtree(Node * root, int value){//removes subtree with given value

    if(root!=NULL){
        if(root->value = value){
            deleteTree(root);

        }
        else if(value > root->value){
            root -> left = removeSubtree(root->left,value);
        }
        else{
            root -> right = removeSubtree(root->right,value);
        }
        //return root;
    }
    return realRoot;


}


int nodeDepth (Node * R, Node * N){//checks the depth from Node R to Node N

    if(N == NULL || R==NULL){//if either node R or N is null return -1
        return -1;

    }
    int depth = 0;
    int found = 0;
    int nVal = N->value;
    Node* curr = R;
        while(R!=NULL){
        if(nVal > R -> value){
            R = R -> left;
            depth++;
        }
        else if(nVal < R -> value){
            R = R -> right;
            depth++;
        }
        else{
            found = 1;
            R = NULL;
        }
    }
    if(found == 0){
        return -1;
    }
    else{
        return depth;
    }

    }










