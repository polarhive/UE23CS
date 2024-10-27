#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int val)
{
    if (root == NULL) {
        return newNode(val);  // If the root is NULL, create a new node
    }

    if (val < root->val) {
        root->left = insert(root->left, val);  // Recur for the left subtree
    } else {
        root->right = insert(root->right, val);  // Recur for the right subtree
    }
    
    return root;
}

// Helper function to perform the range sum calculation
int rangeSumFreqHelper(struct Node* root, int low, int high, int* freq)
{
    if (root == NULL) {
        return 0;  // Base case: if node is NULL, return 0
    }

    int sum = 0;

    // If current node's value is within range [low, high]
    if (root->val >= low && root->val <= high) {
        int idx = root->val + 10000;  // Shift the index to handle negative values
        freq[idx]++;  // Increment the frequency of the current temperature
        sum += root->val;  // Add the node's value to the sum
    }

    // Traverse the left subtree if the current node's value is greater than low
    if (root->val > low) {
        sum += rangeSumFreqHelper(root->left, low, high, freq);
    }

    // Traverse the right subtree if the current node's value is less than high
    if (root->val < high) {
        sum += rangeSumFreqHelper(root->right, low, high, freq);
    }

    return sum;
}

// Function to calculate the result for the given range
int rangeSumFreq(struct Node* root, int low, int high)
{
    // Create and initialize frequency array
    // Size is 20001 to handle range from -10000 to 10000
    int* freq = calloc(20001, sizeof(int));
    
    // Calculate result using helper function
    int sum = rangeSumFreqHelper(root, low, high, freq);
    
    // Free allocated memory
    free(freq);
    
    return sum;
}

// Function to free the BST
void freeTree(struct Node* root)
{
    if (root == NULL) {
    	return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int n, val, low, high;
    
    // Read number of nodes
    scanf("%d", &n);
    
    struct Node* root = NULL;
    
    // Read and insert nodes
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    // Read range
    scanf("%d %d", &low, &high);
    
    // Calculate and print result
    int result = rangeSumFreq(root, low, high);
    printf("%d\n", result);
    
    // Clean up
    freeTree(root);
    return 0;
}
