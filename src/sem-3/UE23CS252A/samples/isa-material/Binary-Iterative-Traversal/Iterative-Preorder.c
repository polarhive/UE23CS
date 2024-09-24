#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {

    // Empty Tree
    if (root == NULL)
        return;

    // Recur on the left subtree
    inorderTraversal(root->left);

    // Visit the current node
    printf("%d ", root->data);

    // Recur on the right subtree
    inorderTraversal(root->right);
}

// Function to create a new node
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
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
