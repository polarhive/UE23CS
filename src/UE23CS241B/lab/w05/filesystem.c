#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ORDER 4  // B-Tree order (max 3 keys per node)

struct BTreeNode {
    int num_keys;             // Number of keys currently in the node
    int keys[ORDER-1];        // Array of keys
    struct BTreeNode *children[ORDER]; // Array of child pointers
    bool is_leaf;             // True if node is a leaf
};

// Function to create a new node
struct BTreeNode *createNode(bool is_leaf) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->num_keys = 0;
    newNode->is_leaf = is_leaf;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

int search(struct BTreeNode *root, int key) {
    if (!root) return 0;
    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }
    if (i < root->num_keys && root->keys[i] == key) {
        return 1;
    }
    if (root->is_leaf) {
        return 0;
    }
    return search(root->children[i], key);
}

void splitNode(struct BTreeNode *parent, int index) {
    struct BTreeNode *child = parent->children[index];
    struct BTreeNode *newNode = createNode(child->is_leaf);
    
    // New node will have ORDER/2 - 1 keys
    newNode->num_keys = ORDER/2 - 1;
    
    // Move the last ORDER/2 - 1 keys from child to newNode
    for (int i = 0; i < ORDER/2 - 1; i++) {
        newNode->keys[i] = child->keys[i + ORDER/2];
    }
    
    // If child is not a leaf, move the last ORDER/2 children to newNode
    if (!child->is_leaf) {
        for (int i = 0; i < ORDER/2; i++) {
            newNode->children[i] = child->children[i + ORDER/2];
        }
    }
    
    // Reduce number of keys in child
    child->num_keys = ORDER/2 - 1;
    
    // Shift parent's children to make room for the new node
    for (int i = parent->num_keys; i >= index+1; i--) {
        parent->children[i+1] = parent->children[i];
    }
    parent->children[index+1] = newNode;
    
    // Move parent's keys to make space for the middle key from child
    for (int i = parent->num_keys - 1; i >= index; i--) {
        parent->keys[i+1] = parent->keys[i];
    }
    // The middle key moves up to the parent
    parent->keys[index] = child->keys[ORDER/2 - 1];
    parent->num_keys++;
}

// Function to insert a key into a non-full node
void insertNonFull(struct BTreeNode *node, int key) {
    int i = node->num_keys - 1;
    
    if (node->is_leaf) {
        // Find the location to insert the key and shift keys as needed
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = key;
        node->num_keys++;
    } else {
        // Find the child that will have the new key
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;
        // If the found child is full, split it
        if (node->children[i]->num_keys == ORDER - 1) {
            splitNode(node, i);
            // After splitting, decide which of the two children is the correct one
            if (node->keys[i] < key)
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

// Inserts a key into the B-Tree
void insert(struct BTreeNode **root, int key) {
    // If tree is empty, create root
    if (*root == NULL) {
        *root = createNode(true);
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
    } else {
        // If root is full, tree grows in height
        if ((*root)->num_keys == ORDER - 1) {
            struct BTreeNode *newRoot = createNode(false);
            newRoot->children[0] = *root;
            splitNode(newRoot, 0);
            int i = 0;
            if (newRoot->keys[0] < key)
                i++;
            insertNonFull(newRoot->children[i], key);
            *root = newRoot;
        } else {
            insertNonFull(*root, key);
        }
    }
}

// Searches for a key in the B-Tree; returns 1 if found, 0 otherwise
int search(struct BTreeNode *root, int key) {
    if (root == NULL)
        return 0;
    int i = 0;
    // Find the first key greater than or equal to the target
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }
    // Check if the found key is equal to the target key
    if (i < root->num_keys && root->keys[i] == key)
        return 1;
    // If reached a leaf, the key is not present
    if (root->is_leaf)
        return 0;
    // Otherwise, search in the appropriate subtree
    return search(root->children[i], key);
}

// In-order traversal to display keys in sorted order
void display(struct BTreeNode *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->num_keys; i++) {
            // First display the subtree before the key if not a leaf
            if (!root->is_leaf)
                display(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        // Finally, display the subtree after the last key
        if (!root->is_leaf)
            display(root->children[i]);
    }
}

// Main driver function to process input and call respective operations
int main() {
    int t;
    char operation[10];
    int x;
    struct BTreeNode *root = NULL;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%s", operation);
        if (strcmp(operation, "INSERT") == 0) {
            scanf("%d", &x);
            insert(&root, x);
        } else if (strcmp(operation, "SEARCH") == 0) {
            scanf("%d", &x);
            printf("%s\n", search(root, x) ? "FOUND" : "NOT FOUND");
        } else if (strcmp(operation, "DISPLAY") == 0) {
            display(root);
            printf("\n");
        }
    }
    return 0;
}
