#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newTreeNode(val);
    }

    // insert into correct position
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// find the Kth smallest element in the BST
void findKth(struct TreeNode* node, int* k, int* result) {
    if (node == NULL) {
        return;
    }

    // left subtree (in-order traversal)
    findKth(node->left, k, result);

    // have we have reached the kth smallest element
    (*k)--;
    if (*k == 0) {
        *result = node->val;
        return;
    }

    // the right subtree
    findKth(node->right, k, result);
}

// Function to find the kth smallest element in the BST
int kthSmallest(struct TreeNode* root, int k) {
    int result = -1;
    findKth(root, &k, &result);
    return result;
}

// Main function
int main() {
    int n, val, k;

    // Taking input from the user to construct the BST
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    // Reading the values to create the BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    // Taking input for k
    scanf("%d", &k);

    // Finding the kth smallest treasure
    int result = kthSmallest(root, k);
    printf("%d\n", result);

    // Freeing allocated memory (optional for simplicity)
    // You may implement a function to free the entire tree if needed

    return 0;
}
