#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
};

// new node with key and value mapping
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// new key-value pair into the BST
struct Node* insert(struct Node* root, int key, int value) {
    if (root == NULL) {
        return createNode(key, value);
    }
    if (key < root->key) {
        root->left = insert(root->left, key, value);
    } else if (key > root->key) {
        root->right = insert(root->right, key, value);
    }
    return root;
}

// get node with the minimum key value
struct Node* findMinNode(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// rm key-value pair from the BST
struct Node* removeNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        // found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // two children
        struct Node* temp = findMinNode(root->right);
        root->key = temp->key;
        root->value = temp->value;
        root->right = removeNode(root->right, temp->key);
    }
    return root;
}

// get key in the BST and return its value
int* get(struct Node* root, int key) {
    if (root == NULL) {
        printf("Key not found\n");
        return NULL;
    }

    if (key < root->key) {
        return get(root->left, key);
    } else if (key > root->key) {
        return get(root->right, key);
    } else {
        return &(root->value);  // Key found, return pointer to value
    }
}

// update value for a given key
void update(struct Node* root, int key, int newValue) {
    if (root == NULL) {
        return;
    }

    if (key < root->key) {
        update(root->left, key, newValue);
    } else if (key > root->key) {
        update(root->right, key, newValue);
    } else {
        root->value = newValue;
    }
}

// In-order traversal to print the dictionary in sorted order
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d,%d\n", root->key, root->value);
        inOrderTraversal(root->right);
    }
}

// Free all nodes in the BST
void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// driver code
int main() {
    struct Node* root = NULL;
    int n;

    // Read the number of operations
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input for number of operations\n");
        exit(EXIT_FAILURE);
    }

    // Process n operations
    for (int i = 0; i < n; i++) {
        int operation;
        if (scanf("%d", &operation) != 1) {
            fprintf(stderr, "Invalid operation code\n");
            exit(EXIT_FAILURE);
        }

        switch (operation) {
            case 1: {
                // Insert operation
                int key, value;
                if (scanf("%d %d", &key, &value) != 2) {
                    fprintf(stderr, "Invalid input for insert operation\n");
                    exit(EXIT_FAILURE);
                }
                root = insert(root, key, value);
                break;
            }
            case 2: {
                // Find minimum key
                struct Node* minNode = findMinNode(root);
                if (minNode != NULL) {
                    printf("%d\n", minNode->key);
                } else {
                    printf("BST is empty\n");
                }
                break;
            }
            case 3: {
                // Remove operation
                int key;
                if (scanf("%d", &key) != 1) {
                    fprintf(stderr, "Invalid input for remove operation\n");
                    exit(EXIT_FAILURE);
                }
                root = removeNode(root, key);
                break;
            }
            case 4: {
                // Get value
                int key;
                if (scanf("%d", &key) != 1) {
                    fprintf(stderr, "Invalid input for get operation\n");
                    exit(EXIT_FAILURE);
                }
                int* value = get(root, key);
                if (value != NULL) {
                    printf("%d\n", *value);
                }
                break;
            }
            case 5: {
                // Update value
                int key, newValue;
                if (scanf("%d %d", &key, &newValue) != 2) {
                    fprintf(stderr, "Invalid input\n");
                    exit(EXIT_FAILURE);
                }
                update(root, key, newValue);
                break;
            }
            case 6: {
                // Display BST
                if (root != NULL) {
                    inOrderTraversal(root);
                } else {
                    printf("BST is empty\n");
                }
                break;
            }
            default:
                fprintf(stderr, "Invalid operation code: %d\n", operation);
                exit(EXIT_FAILURE);
        }
    }

    // Free allocated memory
    freeBST(root);

    return 0;
}
