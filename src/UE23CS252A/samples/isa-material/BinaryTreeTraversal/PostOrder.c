#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to perform postorder traversal
void postorderTraversal(struct Node* node) {
  
    // Base case
    if (node == NULL)
        return;
  
    // Recur on the left subtree
    postorderTraversal(node->left);
  
    // Recur on the right subtree
    postorderTraversal(node->right);
  
    // Visit the current node
    printf("%d ", node->data);
}

struct Node* newNode(int data) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    postorderTraversal(root);
    return 0;
}
