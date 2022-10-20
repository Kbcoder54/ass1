





#include <stdio.h>
#include <stdlib.h>

int count = 0;
int distance = 0;

struct Node {
  int value;
  struct Node *left, *right;
};

struct Node* newNode(int value) {
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->value = value;
  temp->left = temp->right = NULL;
  return temp;
}

struct Node* addNode(struct Node *root, int value) {
  if (root == NULL)
    return newNode(value);
  if (value == root->value)
    return NULL;
  if (value > root->value)
    root->right = addNode(root->right, value);
  else
    root->left = addNode(root->left, value);
  return root;
}

struct Node* removeNode(struct Node *root, int value) {
  if (root == NULL)
    return root;
  if (value > root->value)
    root->right = removeNode(root->right, value);
  else if (value < root->value)
    root->left = removeNode(root->left, value);
  else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }
    struct Node *temp = root->right;
    while (temp && temp->left != NULL)
        temp = temp->left;
    root->value = temp->value;
    root->right = removeNode(root->right, temp->value);
  }
  return root;
}

void displaySubtree(struct Node *root) {
  if (root != NULL) {
    displaySubtree(root->right);
    printf("%d\n", root->value);
    displaySubtree(root->left);
  }
}

int numberLeaves(struct Node* root) {
  if (root != NULL) {
    count++;
    numberLeaves(root->right);
    numberLeaves(root->left);
  }
  return count;
}

struct Node* removeSubtree(struct Node *root, int value) {
  if (root == NULL)
    return root;
  if (root->value == value) {
    if (root->left != NULL)
      removeSubtree(root->left, root->left->value);
    if (root->right != NULL)
      removeSubtree(root->right, root->right->value);
    free(root);
  }
  else {
    struct Node* temp = NULL;
    if (value > root->value)
      temp = removeSubtree(root->right, value);
    else if (value < root->value)
      temp = removeSubtree(root->left, value);
    if(root->right == temp)
      root->right = NULL;
    else if(root->left == temp)
      root->left = NULL;
    return temp;
  }
  return root;
}

int nodeDepth(struct Node *root, struct Node* N)
{
  if (root == NULL)
    return -1;
  if (root->value == N->value)
    return distance;
  distance++;
  int l = nodeDepth(root->left, N);
  return (l != -1)? l : nodeDepth(root->right, N);
}