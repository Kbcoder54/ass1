
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //remove
#include <assert.h> //remove
#include "bst.h"
//might need to remove
struct _Node {
    int value;
    struct _Node *left;
    struct _Node *right;

};
static Node* realRoot;//might need to remove
void displaySubtree(Node *N){
    if(N == NULL){
        return;
    }
    displaySubtree(N->right);
    printf("%d\n",N->value);
    displaySubtree(N->left);


}
Node* newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp!=NULL){
       temp -> value = data;
       temp -> left = NULL;
       temp -> right = NULL;
    }

    return temp;


}

int Contains(int value){
    Node* temp = realRoot;
    while (temp != NULL){
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
    return 0;

}
Node* addNode(Node *root, int value){
    Node* newnode = newNode(value);



    Node* x = root;//NULL
    Node* y = NULL;
    //Node* temp = newNode(value);

    while (x != NULL) {
        y = x;
        if (value < x->value){
            x = x->right;
        }
        else if (value > x->value){
            x = x->left;
        }
        else{
            y = NULL;
            break;
        }
    }

    if (y == NULL){
        realRoot = newnode;
        y = newnode;
    }

    else if (value > y->value){
        y->left = newnode;
    }

    else if (value < y-> value){
        y->right = newnode;
    }

    return newnode;

    /*Node * temp = newNode(value);


   Node *i = root;
   Node *j = NULL;
   while(i!=NULL){
        j = i;
       if(i->value > value){
          i = i->right;
       }
       else if(i->value < value){
          i = i->left;
       }
       else{
          j = NULL;
          break;
       }
   }

   if(j==NULL){
      j = temp;
      realRoot = newNode(value);
   }
   else if(j->value < value){
      j->left = temp;
   }
   else if(j->value > value){
      j->right = temp;
   }

   return temp;*/





    /*Node *p;
    if(root == NULL)
        p = newNode(value);
        return newNode(value);

    if(root->value > value)
        root->right = addNode(root->right,value);

    else if(root->value < value)
        root->left = addNode(root->left,value);

    return p;*/
    /*if (root == NULL){
        return newNode(value);
    }
    Node *curr = root;
    while(true){
        if(curr->value > value){
            if(curr -> right != NULL){
                curr = curr -> right;
            }
            else{
                curr = newNode(value);
                break;
            }
        }
        else{
            if(curr -> left != NULL){
                curr = curr -> left;
            }
            else{
                curr -> left = newNode(value);
                break;
            }
        }

    }
    return curr;*/



    /*Node *p = newNode(value);
    if(root == NULL){
        realRoot = p;
        return p;
    }
    while(root!=NULL){
        if(value > root -> value){
        root -> left = addNode(root->left,value);
    }
    else if(value < root -> value){
        root -> right = addNode(root->right,value);
    }
    else{
        if(Contains(value)== 1){
            return NULL;
            root = NULL;
        }
        else{
            return p;
        }
    }
    }*/
}

Node * removeNode(Node * root, int value){
    if(root == NULL){
        return NULL;
    }
    if(value < root->value){
        root->right = removeNode(root->right,value);
    }
    else if(value > root -> value){
        root->left = removeNode(root ->left,value);
    }
    else{
        Node* temp = NULL;
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
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
        /*Node *temp = root -> right;
        while(temp && temp->left!=NULL){
            temp = temp->left;
        }*/
        temp = root -> left;
        while(temp && temp->right!=NULL){
            temp = temp->right;
        }
        root -> value = temp->value;
        root -> left = removeNode(root->left,temp->value);
    }
    return root;
    /*Node* curr = root;
    Node* prev = NULL;
    while(curr != NULL && curr->value != value){
        if(value > curr -> value){
            curr = curr ->left;
        }
        else{
            curr = curr->right;
        }
    }
    if(curr == NULL){
        return root;
    }
    if(curr -> left == NULL || curr -> right == NULL){
        Node* newcurr;
        if(curr->left == NULL){
            newcurr = curr -> right;
        }
        else{
            newcurr = curr -> left;
        }
        if(prev == NULL){
            return newcurr;
        }
        if(curr == prev->left){
            prev->left = newcurr;
        }
        else{
            prev->right = newcurr;
        }
        free(curr);
    }
    else{
        Node* p = NULL;
        Node* temp;
        temp = curr -> right;
        while(temp->left!=NULL){
            p = temp;
            temp = temp -> left;
        }
        if(p != NULL){
            p -> left = temp -> right;
        }
        else{
            curr -> right = temp -> right;
        }
        curr -> value = temp -> right;
        curr -> value = temp -> value;
        free(temp);
    }
    return realRoot;*/
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
Node * removeSubtree(Node * root, int value){//gives stack error
    if(root==NULL){
        return NULL;
    }
    else if(value < root -> value){
        root->right = removeSubtree(root->right,value);
    }
    else if(value > root -> value){
        root->left = removeSubtree(root->left,value);
    }
    else{
        root = NULL;
        free(root);
    }
    return root;



}
bool partofsubtree(Node* N,int value){ //remove
    if(N==NULL){
        return false;
    }
    if(N->value == value){
        return true;
    }
    bool node1 = partofsubtree(N->left,value);
    if(node1){
        return true;
    }
    bool node2 = partofsubtree(N->right,value);
    if(node2){
        return true;
    }
    return false;


}
int sub(Node *R,int value){
    if(R == NULL){
        return 0;
    }
    else if(R->value == value){
        return 1;
    }
    else if(R->value > value){
        return sub(R->right,value);
    }
    else{
        return sub(R->left,value);
    }


}
int min(int a, int b){
    if(a > b) return b;
    return a;
}
int nodeDepth (Node * R, Node * N){
    /*if(R == NULL){
        return 0;
    }
    int left_depth= nodeDepth(R->left,N->left);
    int right_depth= nodeDepth(R->right,N->right);
    if(left_depth > right_depth)
        return left_depth +1;
    else
        return right_depth +1;*/
    /*if(R == NULL){
        return 0;
    }
    if(R->left == NULL && R->right == NULL){
        return 1;
    }*/
    /*if(R->left == 0)
        return nodeDepth(R->right,N -> right)+1;
    if(R -> right ==0)
        return nodeDepth(R->right,N -> right) + 1;*/
    /*int l = nodeDepth(R->right,N -> right),r = nodeDepth(R->right,N -> right);
    return l > r ? r+1 : l+1;*///find the min


    /*int depth = 0;
    if(R==NULL){
        return depth;
    }
    if(R -> value == N -> value){
        depth = -1;
        return depth;
    }
    if(R -> value == N -> value){
        return depth;
    }
    else{
        while (R != NULL){

        if (N -> value > R->value){
            R = R->right;
            depth++;
        }
        else if (N -> value < R->value){
            R = R->left;
            depth++;
        }
        else{
            return depth;
        }

     }
    }*/
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










