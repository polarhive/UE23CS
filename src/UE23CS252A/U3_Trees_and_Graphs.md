# BST (Binary Search Tree)

A **Binary Search Tree** is a type of binary tree where every node has at most two children, and these children follow the binary search property.

> [!Important] Property
> - The value of all the nodes in the left subtree is **less than** the value of the current node.
> - The value of all the nodes in the right subtree is **greater than** the value of the current node.

This property allows for efficient searching, insertion, and deletion operations in **O(log n)** time, where `n` is the number of nodes in the tree, provided the tree is balanced.

``` mathematica
        10
       /  \
      5    20
     / \   / \
    3   7 15  25

```

Operations like searching for a value, inserting a new value, or deleting an existing node can be performed efficiently due to the BST property.

---

## Using Array

Binary Search Trees are typically implemented using pointers, as they allow for dynamic memory allocation. However, it is possible to represent a complete binary tree as an array, which requires prior knowledge of the tree's maximum size.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int bst[MAX_SIZE];
int size = 0;

void insertArray(int value) {
    int index = 0;
    while (bst[index] != 0) {
        if (value < bst[index])
            index = 2 * index + 1;
        else
            index = 2 * index + 2;
    }
    bst[index] = value;
    size++;
}

void displayArray() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bst[i] != 0)
            printf("%d ", bst[i]);
    }
    printf("\n");
}
```

```c
insertArray(10);
insertArray(5);
insertArray(15);
displayArray();
```

---

## Using Linked

The linked approach to BSTs is more common and allows for dynamic memory allocation and flexibility.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
```

```c
Node* root = NULL;
root = insert(root, 10);
insert(root, 5);
insert(root, 15);
```

---

## Finding Height, Depth, Number of Nodes, and Leaves

The height of a tree is the length of the longest path from the root to a leaf. Depth is the distance from the root node to the target node.

```c
int findHeight(Node* node) {
    if (node == NULL)
        return -1;
    else {
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

int countNodes(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(Node* node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}
```

```c
printf("Height of tree: %d\n", findHeight(root));
printf("Total nodes: %d\n", countNodes(root));
printf("Total leaves: %d\n", countLeaves(root));
```

---

## Node Deletion in a BST

1. **Node is a leaf** (no children): Simply remove the node from the tree.
2. **Node has one child**: Remove the node and link its child directly to the node's parent.
3. **Node has two children**: Find the in-order successor (the smallest node in the right subtree), replace the node’s value with the in-order successor’s value, and then delete the in-order successor.

> [!Info]
> The helper function `minValueNode` finds the in-order successor of a node, which is used in the deletion process when the node has two children.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Helper function to find the minimum value node in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    // The minimum value node is the left-most node
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node in a BST
Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL)
        return root;

    // Recursively find the node to delete
    if (key < root->data) {
        // Key is in the left subtree
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        // Key is in the right subtree
        root->right = deleteNode(root->right, key);
    } else {
        // Node with the key found

        // Case 1: Node is a leaf (no children)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has only one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the in-order successor (smallest node in the right subtree)
        Node* temp = minValueNode(root->right);
        // Replace the data of the node to be deleted with successor's data
        root->data = temp->data;
        // Delete the in-order successor in the right subtree
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
```

- **Case 1: Node is a Leaf (No Children)**
  When the node to be deleted has no children, we simply free the memory allocated for that node and return `NULL` to its parent, effectively removing the node from the tree.

  ```c
  if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
  }
  ```

- **Case 2: Node Has One Child**
  When the node has only one child, we remove the node and directly connect its only child to the parent of the node. If the left child is `NULL`, the right child is linked to the parent. Conversely, if the right child is `NULL`, the left child is linked.

  ```c
  else if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp;
  } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp;
  }
  ```

- **Case 3: Node Has Two Children**
  When the node has two children, we:
  1. Find the **in-order successor** (the smallest node in the right subtree) using the `minValueNode` function.
  2. Copy the in-order successor’s value to the node to be deleted.
  3. Delete the in-order successor from the right subtree.

  The in-order successor is chosen because it maintains the BST property after deletion.

  ```c
  Node* temp = minValueNode(root->right);
  root->data = temp->data;
  root->right = deleteNode(root->right, temp->data);
  ```

```c
int main() {
    Node* root = NULL;
    // Assume insert() function is defined to build the tree
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);

    printf("Deleting node with value 10\n");
    root = deleteNode(root, 10);
    // Inorder traversal to show remaining tree
    inorderRecursive(root);
    return 0;
}
```

In this example, we delete the node with the value `10` and then perform an inorder traversal to see the remaining structure of the tree.

---

## Traversal Using Iteration

BST traversal using iteration can be done using Inorder, Preorder, and Postorder traversals. Here’s an example of an iterative Inorder traversal using a stack.

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

Node* stack[MAX_STACK_SIZE];
int top = -1;

void push(Node* node) {
    if (top < MAX_STACK_SIZE - 1)
        stack[++top] = node;
}

Node* pop() {
    if (top >= 0)
        return stack[top--];
    return NULL;
}

void inorderIterative(Node* root) {
    Node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}
```

```c
inorderIterative(root);
```

---

## Traversal using Recursion

```c
void inorderRecursive(Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

void preorderRecursive(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

```

---

# Expression Tree

An **Expression Tree** is a binary tree in which each internal node represents an operator (e.g., `+`, `-`, `*`, `/`), and each leaf node represents an operand (a constant or variable). Expression Trees are useful for evaluating mathematical expressions in a structured manner.

> [!Important]
> In an expression tree:
> - Each leaf node represents a number or variable.
> - Each internal node represents an operator.
> - The evaluation of the tree involves traversing it in postorder (left, right, root) to apply operators in the correct order.

To build and evaluate an expression tree, we’ll define:

1. A **Node** structure representing an operand or operator.
2. Functions to **build** an expression tree from postfix notation.
3. A **postorder traversal** function for evaluation.

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build an expression tree from postfix expression
Node* buildExpressionTree(char postfix[]) {
    Node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else if (isOperator(postfix[i])) {
            Node* node = createNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}

// Function to evaluate the expression tree
int evaluate(Node* root) {
    if (root == NULL) return 0;
    if (!isOperator(root->data)) return root->data - '0'; // Assuming single-digit operands

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    switch (root->data) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

// Function to print the tree in inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
```

```c
int main() {
    char postfix[] = "23*54*+9-";
    Node* root = buildExpressionTree(postfix);

    printf("Inorder traversal of the expression tree: ");
    inorder(root);
    printf("\n");

    printf("Evaluated result: %d\n", evaluate(root));
    return 0;
}
```

In this example, the postfix expression `"23*54*+9-"` is converted to an expression tree, and the result is evaluated.

---

# Threaded Binary Tree

A **Threaded Binary Tree** is a binary tree variant that enables efficient inorder traversal without using a stack or recursion. In a threaded binary tree:

> [!Important]
> - **Left threads** point to the inorder predecessor if the left child is absent.
> - **Right threads** point to the inorder successor if the right child is absent.

This approach reduces memory usage and allows traversal without extra storage by utilizing null pointers as links.

For simplicity, here’s an implementation of a single-threaded binary tree (right-threaded):

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadedNode {
    int data;
    struct ThreadedNode *left, *right;
    int rightThread; // 1 if right points to inorder successor
} ThreadedNode;

// Function to create a new node
ThreadedNode* createThreadedNode(int data) {
    ThreadedNode* node = (ThreadedNode*)malloc(sizeof(ThreadedNode));
    node->data = data;
    node->left = node->right = NULL;
    node->rightThread = 0;
    return node;
}

// Insert function for a right-threaded binary tree
ThreadedNode* insert(ThreadedNode* root, int key) {
    ThreadedNode* parent = NULL;
    ThreadedNode* current = root;

    while (current != NULL) {
        if (key == current->data) return root;

        parent = current;
        if (key < current->data) {
            if (current->left == NULL) break;
            current = current->left;
        } else {
            if (current->rightThread) break;
            current = current->right;
        }
    }

    ThreadedNode* newNode = createThreadedNode(key);
    if (parent == NULL) {
        root = newNode;
    } else if (key < parent->data) {
        parent->left = newNode;
        newNode->right = parent;
        newNode->rightThread = 1;
    } else {
        newNode->right = parent->right;
        newNode->rightThread = parent->rightThread;
        parent->right = newNode;
        parent->rightThread = 0;
    }
    return root;
}

// Inorder traversal of a threaded binary tree
void inorder(ThreadedNode* root) {
    ThreadedNode* current = root;
    while (current != NULL) {
        // Move to leftmost node
        while (current->left != NULL) current = current->left;

        // Print current node
        printf("%d ", current->data);

        // Find inorder successor using threads
        while (current->rightThread) {
            current = current->right;
            printf("%d ", current->data);
        }

        current = current->right;
    }
}
```

```c
int main() {
    ThreadedNode* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);

    printf("Inorder traversal of the threaded binary tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
```

In this example, we build a right-threaded binary tree and perform an inorder traversal. Right threads help in accessing the inorder successor efficiently.

These implementations provide a foundation for Expression Trees and Threaded Binary Trees, with efficient traversal and manipulation techniques.

---

# Heap Tree

> [!Info]
> A **Heap Tree** is a specialized binary tree that satisfies the *heap property*, which can be one of the following:
> 1. **Max-Heap**: Each parent node is greater than or equal to its child nodes. The maximum element is at the root.
> 2. **Min-Heap**: Each parent node is less than or equal to its child nodes. The minimum element is at the root.

## Properties of a Heap

1. **Shape Property**: A heap is a *complete binary tree*, meaning all levels are fully filled except possibly the last, which is filled from left to right.
2. **Heap Property**: For a max-heap, each parent node is greater than or equal to its children, while for a min-heap, each parent node is less than or equal to its children.
3. **Array Representation**: Heaps are typically stored as arrays, making them efficient for accessing parent and child nodes.

> [!Example]
>    - For a node at index `i`:
>      - **Parent** is at index `(i - 1) / 2`
>      - **Left child** is at index `2 * i + 1`
>      - **Right child** is at index `2 * i + 2`

---

# Heap Construction Using Array

## Bottom-Up Heap Construction (Heapify)

In bottom-up heap construction, we start from the last non-leaf node and apply the `heapify` operation to ensure each subtree satisfies the heap property. This method is efficient with a time complexity of `(O(n))`.

```c
#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Heapify function to maintain heap property
void heapify(int arr[], int n, int i) {
    int largest = i;  // Root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Bottom-up construction of max-heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
```

## Top-Down Heap Construction (Insert)

In top-down heap construction, we add elements one by one, placing them at the end of the heap array, then "bubble up" to ensure the heap property is maintained. This method is useful when building a heap incrementally.

```c
void insert(int arr[], int *n, int key) {
    int i = (*n)++;
    arr[i] = key;

    // Bubble up to maintain the max-heap property
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
```

```c
int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);
    printf("Max-Heap constructed (Bottom-Up): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int heap[10] = {0};
    int heapSize = 0;
    insert(heap, &heapSize, 20);
    insert(heap, &heapSize, 15);
    insert(heap, &heapSize, 30);
    printf("Heap after Top-Down insertions: ");
    for (int i = 0; i < heapSize; i++) printf("%d ", heap[i]);
    printf("\n");

    return 0;
}
```

---

# Priority Queue Using Min and Max Heap

A **Priority Queue** is a data structure where each element has a priority, and the element with the highest priority is served before others. Priority queues can be implemented using heaps:

> [!Important]
>
> - **Max-Heap** for maximum priority queues (highest element at the root).
> - **Min-Heap** for minimum priority queues (smallest element at the root).

## Max-Heap Priority Queue (Insertion and Deletion)

For a max-heap, the maximum element is always at the root. We insert by adding to the end of the array and bubble up to maintain the heap property. To remove the maximum, we replace the root with the last element and heapify down.

```c
#include <stdio.h>

void insertMaxHeap(int arr[], int *n, int key) {
    int i = (*n)++;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMax(int arr[], int *n) {
    if (*n <= 0) return -1;
    if (*n == 1) return arr[--(*n)];

    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}
```

## Min-Heap Priority Queue (Insertion and Deletion)

For a min-heap, the minimum element is always at the root. We insert by adding to the end of the array and bubble up to maintain the heap property. To remove the minimum, we replace the root with the last element and heapify down.

```c
void insertMinHeap(int arr[], int *n, int key) {
    int i = (*n)++;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMin(int arr[], int *n) {
    if (*n <= 0) return -1;
    if (*n == 1) return arr[--(*n)];

    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}
```

```c
int main() {
    int maxHeap[10];
    int minHeap[10];
    int maxSize = 0, minSize = 0;

    // Max-Heap Priority Queue
    insertMaxHeap(maxHeap, &maxSize, 40);
    insertMaxHeap(maxHeap, &maxSize, 30);
    insertMaxHeap(maxHeap, &maxSize, 50);
    printf("Max-Heap Priority Queue: ");
    for (int i = 0; i < maxSize; i++) printf("%d ", maxHeap[i]);
    printf("\nDeleted max element: %d\n", deleteMax(maxHeap, &maxSize));

    // Min-Heap Priority Queue
    insertMinHeap(minHeap, &minSize, 20);
    insertMinHeap(minHeap, &minSize, 15);
    insertMinHeap(minHeap, &minSize, 10);
    printf("Min-Heap Priority Queue: ");
    for (int i = 0; i < minSize; i++) printf("%d ", minHeap[i]);
    printf("\nDeleted min element: %d\n", deleteMin(minHeap, &minSize));

    return 0;
}
```

This example demonstrates basic insertions and deletions in min-heap and max-heap priority queues.

---

# Balanced Trees

> [!Info]
> A **Balanced Tree** is a type of binary tree where the height difference between the left and right subtrees of any node is within a certain limit, often a single level. Balanced trees ensure that the tree does not become skewed, which maintains efficient operations, particularly for insertion, deletion, and search, which operate in \(O(\log n)\) time.

## Why Balance Matters

Without balancing, a binary search tree (BST) can degrade to a linked list with \(O(n)\) operations. Balanced trees, like AVL trees, prevent this by automatically adjusting the structure during insertions and deletions.

---

# AVL Trees

An **AVL Tree** (named after its inventors, Adelson-Velsky and Landis) is a self-balancing binary search tree where the height difference between the left and right subtrees (known as the balance factor) of any node is at most 1. This property ensures logarithmic height, making AVL trees efficient for searching, insertion, and deletion.

> [!Info] Properties of AVL
>
> 1. **Binary Search Tree Property**: Left child values are smaller than the parent, and right child values are larger.
> 2. **Balance Factor**: The difference in height between the left and right subtrees of a node is calculated as:
>    - `balance_factor = height(left_subtree) - height(right_subtree)`
> 3. **Self-Balancing**: After each insertion or deletion, the tree checks balance factors and performs rotations if needed to maintain the balance.

---

# AVL Tree Rotations

> AVL tree rotations are used to maintain the balance of the tree by rearranging nodes. There are four types of rotations to correct specific imbalance cases:

## 1. Left Rotation (Single Rotation)

Left Rotation is used to correct a **Right-Heavy** imbalance (when the right subtree of a node is higher than the left). It is commonly used in **Right-Right (RR) Imbalance** situations.

```c
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root after rotation
}
```

## 2. Right Rotation (Single Rotation)

Right Rotation is used to correct a **Left-Heavy** imbalance (when the left subtree of a node is higher than the right). It is commonly used in **Left-Left (LL) Imbalance** situations.

```c
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root after rotation
}
```

## 3. Left-Right Rotation (Double Rotation)

Left-Right Rotation is a combination of a left rotation followed by a right rotation. It is used to correct a **Left-Right (LR) Imbalance**, where a node’s left subtree is right-heavy.

```c
Node* leftRightRotate(Node* node) {
    node->left = leftRotate(node->left); // First left rotation on left child
    return rightRotate(node);            // Then right rotation on node itself
}
```

## 4. Right-Left Rotation (Double Rotation)

Right-Left Rotation is a combination of a right rotation followed by a left rotation. It is used to correct a **Right-Left (RL) Imbalance**, where a node’s right subtree is left-heavy.

```c
Node* rightLeftRotate(Node* node) {
    node->right = rightRotate(node->right); // First right rotation on right child
    return leftRotate(node);                // Then left rotation on node itself
}
```

---

# Insertion in an AVL Tree

After inserting a new node, the AVL tree checks for imbalances by calculating balance factors and performs the necessary rotations to restore balance.

```c
Node* insert(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
```

```c
int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the constructed AVL tree is:\n");
    inorderTraversal(root);

    return 0;
}
```

In this example, the tree remains balanced after each insertion, thanks to rotations, maintaining efficient performance.

---

# Splay Tree

A **Splay Tree** is a self-adjusting binary search tree that performs splaying operations on nodes to maintain a roughly balanced structure. Whenever a node is accessed (searched, inserted, or deleted), it is brought to the root through a series of rotations known as *splaying.* This ensures that recently accessed elements are quicker to reach, making splay trees particularly useful for applications with non-uniform access patterns.

## Properties of a Splay Tree

1. **Self-Adjusting**: The tree adjusts its structure by splaying nodes upon access, moving them to the root.
2. **No Balance Factor or Height Constraints**: Unlike AVL or Red-Black trees, splay trees don’t enforce strict balance criteria.
3. **Amortized (O(log n)) Time Complexity**: While individual operations may take longer, the amortized time for access, insertion, or deletion is (O(log n)), making splay trees efficient over time.

---

# Splay Operations (Rotations)

There are three types of rotations in a splay tree to move a node to the root, depending on its position relative to its parent and grandparent nodes. Each rotation type is aimed at moving the target node up the tree to eventually reach the root.

## 1. Zig Rotation (Single Rotation)

**Zig** is a single rotation performed when the target node is a child of the root. This is similar to a single left or right rotation in a binary search tree.

- **Right Zig**: Performed when the target node is the left child of the root.
- **Left Zig**: Performed when the target node is the right child of the root.

```c
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
```

## 2. Zig-Zig Rotation (Double Rotation)

**Zig-Zig** is a double rotation used when the target node and its parent are both left or both right children of their respective parents.

- **Right Zig-Zig**: Performed when the target node is the left child of its parent, and the parent is also the left child of the grandparent.
- **Left Zig-Zig**: Performed when the target node is the right child of its parent, and the parent is also the right child of the grandparent.

```c
Node* zigZigRight(Node* x) {
    x = rightRotate(x);       // First rotation on the grandparent
    x = rightRotate(x);       // Second rotation on the parent
    return x;
}

Node* zigZigLeft(Node* x) {
    x = leftRotate(x);        // First rotation on the grandparent
    x = leftRotate(x);        // Second rotation on the parent
    return x;
}
```

## 3. Zig-Zag Rotation (Double Rotation)

**Zig-Zag** is a double rotation used when the target node is a left child, and its parent is a right child, or vice versa.

- **Right Zig-Zag**: The target node is the right child of the parent, and the parent is the left child of the grandparent.
- **Left Zig-Zag**: The target node is the left child of the parent, and the parent is the right child of the grandparent.

```c
Node* zigZagRight(Node* x) {
    x->left = leftRotate(x->left);  // First rotation on the parent
    return rightRotate(x);          // Second rotation on the grandparent
}

Node* zigZagLeft(Node* x) {
    x->right = rightRotate(x->right);  // First rotation on the parent
    return leftRotate(x);              // Second rotation on the grandparent
}
```

---

# Splay Operation

The **splay** function brings a target node to the root of the tree. The function recursively applies the appropriate rotations based on the node’s position relative to its parent and grandparent.

```c
Node* splay(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data) {
        if (root->left == NULL) return root;

        if (key < root->left->data) {   // Zig-Zig case (Left Left)
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->data) {  // Zig-Zag case (Left Right)
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) return root;

        if (key > root->right->data) {   // Zig-Zig case (Right Right)
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->data) {  // Zig-Zag case (Right Left)
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}
```

---

# Operations on a Splay Tree

## Insertion

When inserting a new node, we first splay the tree to bring the closest node to the root. Then we insert the new node in the appropriate position and make it the new root.

```c
Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    root = splay(root, key);

    if (root->data == key) return root;  // If already exists, return

    Node* newNode = createNode(key);

    if (key < root->data) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}
```

## Deletion

For deletion, we first splay the target node to the root. If the node exists, we then split the tree into two subtrees (left and right). The left subtree becomes the new root, with the right subtree reattached to it.

```c
Node* delete(Node* root, int key) {
    if (root == NULL) return NULL;

    root = splay(root, key);

    if (root->data != key) return root;  // Key not found

    Node* temp;
    if (root->left == NULL) {
        temp = root->right;
    } else {
        temp = splay(root->left, key);
        temp->right = root->right;
    }

    free(root);
    return temp;
}
```

## Searching

In a splay tree, searching for a node involves splaying it to the root if it exists. If the key is found, it’s returned as the new root.

```c
Node* search(Node* root, int key) {
    return splay(root, key);
}
```

```c
int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    root = search(root, 20);  // Brings node with key 20 to the root
    printf("Root after search: %d\n", root->data);

    root = delete(root, 20);
    printf("Root after deletion of 20: %d\n", root->data);

    return 0;
}
```

In this example, the tree reorganizes itself with each operation, keeping frequently accessed nodes closer to the root.

---

# Graphs

> [!NOTE]
> A **graph** is a collection of nodes (or vertices) connected by edges (or arcs). Graphs are used to model pairwise relationships between objects, making them fundamental in representing networks, social graphs, and more.

1. **Vertices (Nodes)**: The fundamental units or points in a graph.
2. **Edges (Links)**: The connections between vertices, which can be directed or undirected.
3. **Degree**: The number of edges incident to a vertex.
4. **Weight**: A value associated with each edge, typically used in weighted graphs to represent the cost or distance between nodes.
5. **Connectedness**: A graph is connected if there is a path between every pair of vertices.
6. **Directed and Undirected**: In a directed graph (digraph), edges have a direction; in an undirected graph, edges do not.
7. **Cycle**: A cycle is a path that starts and ends at the same vertex without traversing any edge more than once.

---

## Types of Graphs, Applications, and Representations

1. **Undirected Graph**: No direction is associated with edges (edges represent bidirectional relationships).
2. **Directed Graph (Digraph)**: Edges have a direction, represented as arrows.
3. **Weighted Graph**: Edges have weights (values), commonly used for problems like shortest paths.
4. **Bipartite Graph**: The graph's vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.
5. **Complete Graph**: Every pair of distinct vertices is connected by a unique edge.

> [!Example]
> - **Social Networks**: Modeling relationships and interactions.
> - **Routing Algorithms**: Used in GPS systems, internet traffic management.
> - **Recommendation Systems**: Suggesting products or services based on user behavior.
> - **Computer Networks**: Representing communication between devices.
>
> > Graphs are commonly used to model network topologies, where the nodes represent devices (e.g., computers, routers) and the edges represent communication links. Graph traversal techniques such as DFS and BFS are used to explore the network, find the shortest path, or detect loops.

---

## Representing Graphs

> [!Info]
> Graphs can be represented in two primary ways:
>
> 1. **Adjacency Matrix**: A 2D matrix where each cell (i, j) represents an edge between vertices i and j.
> 2. **Adjacency List**: A collection of lists where each vertex has a list of adjacent vertices.

### Using Adjacency Matrix

An adjacency matrix for a graph with (V) vertices is a ( V times V ) matrix where:

- `matrix[i][j] = 1` if there is an edge between vertex `i` and vertex `j`.
- `matrix[i][j] = 0` otherwise.

For example, the adjacency matrix for the following graph:

``` mathematica
  1--2
  |  |
  4--3
```

Would look like this (undirected graph):

``` mathematica
    1  2  3  4
1  [0, 1, 0, 1]
2  [1, 0, 1, 0]
3  [0, 1, 0, 1]
4  [1, 0, 1, 0]
```

### Using Adjacency List

An adjacency list stores for each vertex a list of its adjacent vertices. For the same graph, the adjacency list representation would be:

``` mathematica
1 -> [2, 4]
2 -> [1, 3]
3 -> [2, 4]
4 -> [1, 3]
```

---

## Graph Traversal Algorithms

Graph traversal is the process of visiting each vertex in the graph. This is crucial for searching, pathfinding, or analysis tasks.

### Depth First Search (DFS)

**DFS** explores as far as possible along each branch before backtracking. It uses a stack (or recursion) to explore a vertex and then move to the deepest possible vertex before backtracking.

**DFS Algorithm**:
1. Choose a starting vertex and mark it as visited.
2. Visit all adjacent vertices that haven’t been visited.
3. Recursively visit the neighbors of the current vertex.
4. If all neighbors are visited, backtrack to the previous vertex.

**DFS Example:**

For a graph:

``` mathematica
    1
   / \
  2   3
  |   |
  4   5
```

Starting from vertex `1`, the traversal is: `1 -> 2 -> 4 -> 3 -> 5`.

```c
void DFS(int v, bool visited[], int adjMatrix[V][V]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i])
            DFS(i, visited, adjMatrix);
    }
}
```

---

### Breadth First Search (BFS)

**BFS** explores the graph level by level, visiting all neighbors of a vertex before moving to the next depth level. It uses a queue to manage the vertices to visit.

**BFS Algorithm**:
1. Insert the starting vertex into the queue and mark it as visited.
2. While the queue is not empty:
   - Dequeue a vertex.
   - Visit all unvisited adjacent vertices and enqueue them.
3. Repeat until the queue is empty.

**BFS Example:**

For the same graph:

``` mathematica
    1
   / \
  2   3
  |   |
  4   5
```

Starting from vertex `1`, the traversal is: `1 -> 2 -> 3 -> 4 -> 5`.

```c
void BFS(int start, int adjMatrix[V][V]) {
    bool visited[V] = { false };
    Queue q;
    enqueue(q, start);
    visited[start] = true;

    while (!isEmpty(q)) {
        int node = dequeue(q);
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                enqueue(q, i);
                visited[i] = true;
            }
        }
    }
}
```

---

## Connectivity of a Graph

A graph is **connected** if there is a path between every pair of vertices. If a graph is not connected, it consists of multiple disconnected components.

**Check for connectivity**:

1. Perform a DFS or BFS from an arbitrary vertex.
2. If all vertices are visited, the graph is connected.
3. If some vertices are unreachable, the graph is disconnected.

---

## Finding Path in a Network

To find a path between two vertices in a graph (e.g., in a network), BFS is typically used, as it guarantees the shortest path in an unweighted graph.

**Path Finding Example:**
For the graph:

``` mathematica
   1--2
   |  |
   4--3
```

To find a path between `1` and `3`, use BFS, and the shortest path would be `1 -> 2 -> 3`.

```c
void findPath(int start, int target, int adjMatrix[V][V]) {
    bool visited[V] = { false };
    int parent[V];
    Queue q;
    enqueue(q, start);
    visited[start] = true;

    while (!isEmpty(q)) {
        int node = dequeue(q);

        for (int i = 0; i < V; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = node;
                enqueue(q, i);
            }
        }
    }

    // Trace the path from target to start using the parent array
    int node = target;
    while (node != start) {
        printf("%d <- ", node);
        node = parent[node];
    }
    printf("%d\n", start);
}
```
