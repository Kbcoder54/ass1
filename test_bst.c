#include <stdio.h>
#include <assert.h>


#include "bst.h"
#include "bst.c" //remove


int main() {
    /*Node *n1, *n2, *n3,*n4;
    n1 = addNode(NULL, 5);
    n2 = newNode(8);
    n3 = newNode(4);
    n4 = newNode(10);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    int c = nodeDepth(n1,n4);
    assert(c == 2);*/
   Node *rootNode, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *z;
  rootNode = addNode(NULL, 34);
  b = addNode(rootNode, 53);
  c = addNode(rootNode, 31);
  d = addNode(rootNode, 5);
  e = addNode(rootNode, 2);
  f = addNode(rootNode, 3);
  g = addNode(rootNode, 23);
  h = addNode(rootNode, 1);
  i = addNode(rootNode, 56);
  j = addNode(rootNode, 12);
  k = addNode(rootNode, 91);
  z = addNode(rootNode, 35);

  assert(numberLeaves(rootNode) == 5);
  removeSubtree(rootNode, 5);
  assert(nodeDepth(rootNode, k) == 3);
  assert(c->left == NULL);
  assert(c->right == NULL);
  assert(nodeDepth(b, k) == 2);
  assert(nodeDepth(i, k) == 1);
  assert(removeSubtree(rootNode, 34) == NULL);




    return 0;

}
