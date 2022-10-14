
#include <stdio.h>
#include <assert.h> //remove
#include "bst.h"

struct _Node {
    int value;
    struct _Node *left;
    struct _Node *right;

};
void displaySubtree(Node *N){
    if(N == NULL){
        return;
    }
    displaySubtree(N->right);
    printf("%d\n",N->value);
    displaySubtree(N->left);


}
Node* addNode(Node *root, int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> value = value;
    temp -> left = NULL;
    temp -> right = NULL;

    if (root == NULL){
        return temp;
    }
    else{
        if(root -> value > value){
        root -> right = addNode(root->right,value);
        }
        else {
        root -> left = addNode(root->left,value);
        }
    }
        return root;
    //return root;



}
Node * removeNode(Node * root, int value){
    if (root == NULL){
        return root;
    }
    if(root->value > value){
        root -> right = removeNode(root->right,value);
    }
    else if(root -> value < value){
        root -> left = removeNode(root->left,value);
    }
    else{
        //Case 1:if both children are null
        if(root -> left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //Case 2:if one child is not null
        else if (root -> left == NULL || root->right == NULL){
            Node *temp = root -> left ? root -> left : root -> right; // we want the non null node
            free(root);
            return temp;
        }
        //Case 3:if both children are not null
        else if(root->left != NULL && root->right != NULL){
        //find the leftmost element in right sub tree as it contains the smallest value in that subtree
            Node *temp = root->right;
            while (temp->left != NULL){
                temp = temp -> left;
            }
            root -> value = temp -> value;
            root->right = removeNode(root->right, root->value);//repeating case 2
        }
    }
    return root;

}

int numberLeaves(Node * N){
    if(N == NULL){
            return 0;
    }
    if(N ->left == NULL && N -> right == NULL){
        return 1;
    }
    else{
        return numberLeaves(N->left) + numberLeaves(N->right);
    }



}
Node * removeSubtree(Node * root, int value){
    if(root!=NULL){
        removeSubtree(root->left,root->left->value);
        removeSubtree(root->right,root->right->value);
        free(root);
    }
    return root;



}



int main(){ //remove
    /*Node *a, *b,*c;

    a = addNode(NULL, 42);
    b = addNode(a,3);
    c = addNode(a,2);
    displaySubtree(a);
    c = removeNode(b,3);
    displaySubtree(c);
    thus c is equal to a
    assert(c == a);*/

    /*int num = numberLeaves(b);*/
    Node *a, *b;
  a = addNode(NULL, 42);
  b = removeNode(a, 42);
  assert(b == NULL);

  a = addNode(NULL, 1);
  b = addNode(a, 2);

  displaySubtree(a);
  int c = numberLeaves(a);
  assert(c == 1);

  //c = nodeDepth(a,b);
  //assert(c == 1);

  a = removeSubtree(b, 2);
  displaySubtree(a);


}



