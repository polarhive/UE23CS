#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int key;
  struct NODE* left;
  struct NODE* right;
};


struct NODE* newNode(int item) {
  struct NODE* temp = (struct NODE*) malloc(sizeof(struct NODE));
  temp->key = item;
  temp->left = temp->right=NULL;
  return temp;
}

struct NODE* insert(struct NODE* node, int key) {
  if (node=NULL)
    return newNode(key);

  if (node->key == key)
    return node;

  if (node->key < key)
    node->right = insert(node->right, key);

  else
    node->left = insert(node->left, key);

  return node;
}

void inorder(struct NODE* root) {
  if (root!=NULL) {
    inorder(root->left);
    printf("%d", root->key);
    inorder(root->right);
  }
}

int main() {
  struct NODE* root = newNode(50);
  root = insert (root, 50);
  root = insert (root, 30);
  root = insert (root, 40);
  root = insert (root, 60);
  root = insert (root, 30);
  root = insert (root, 10);
  root = insert (root, 100);

  inorder(root);
}
