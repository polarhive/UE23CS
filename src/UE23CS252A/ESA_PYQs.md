# 21-Jul-2023 A

1.a. List the four Dynamic Memory Management functions in C. Explain anyone with a neat diagram and it’s prototype.

1.b. Explain dangling pointer and memory leak with a suitable code snippet.

1.c. Define the structure of a node to create a collection of nodes in a doubly linked list. The alias name for the node is NODE and this has been encapsulated as head pointer in a list structure as shown below. The head pointer is pointing to NULL if the list is empty.

```c
typedef struct list
{
	NODE *head;
}
DLIST;
```

Complete the implementation of insertFront() and getNode() functions as per the prototypes mentioned.

```c
void insertFront(DLIST *dli, int ele);
NODE* getNode(int ele);
```

---

2.a. List any two differences between an array and a linked list.
2.b. Convert the infix expression to prefix and postfix form:
`A-B/(C*D^E)`

2.c. Write the implementation of eval() function to evaluate the given postfix expression. Push and pop functions are implemented and ready to use as shown below. Client code is given for your reference.

```c
void push(STACK *s, float ele);
float pop(STACK* s);
int main()
{
	char postfix[100];
	printf("enter the valid postfix expression\n");
	scanf("%s", postfix);
	int result = eval(postfix);
	if (result != INT_MAX)
	printf("result is %d\n",result );
	return 0;
}
```

2.d. For a given Circular Queue, if the below implementations are mentioned, Fill the body of enqueue and isFull functions.

```c
#define MAX 5
typedef struct Queue
{
	int a[MAX];
	int front, rear;
}QUE;
void initQ(QUE *pq)
{
	pq->rear = pq->front = MAX-1;
}
void enqueue(QUE *pq, int ele){
	//Blank #1 // Fill this
}
int isFull(QUE *pq){
	//Blank #2 // Fill this
}
```

3.a. List and define the two conditions /requirements to be met to call the tree as Max-heap.

3.b. Define the listed terms with an example.
	i) Strictly Binary tree
	ii) Fully Binary tree

3.c. What is the advantage of implementing the tree as a Threaded Binary Search tree?
Define the structure of a node and a tree which is useful in the implementation of Right-in threaded binary tree.

3.d. Write the definition of createTree function to get the array implementation of Binary search tree for the given set of codes below.

```c
typedef struct bst_array
{ int info; int used; }NODE;
#include<stdio.h>
#include<stdlib.h>
#define MAX 40
void displayTree(NODE *t); void initTree(NODE t[]); void createTree(NODE *t);
int main()
{ NODE t[MAX]; initTree(t); createTree(t); displayTree(t); return 0; }
```

4.a. What is an AVL tree? Give an example tree. Also, write about different rotations to keep the tree balanced.

4.b. Write the recursive code to find the connectivity of the graph for a given client code.

```c
#include<stdio.h>
#define MAX 10
int dfs(int a[MAX][MAX],int n,int visited[], int source, int destination);
void readGraph(int a[MAX][MAX], int n);
int main()
{
int a[MAX][MAX] ;
int visited[MAX] = {0};
int n, source, destination;
printf("enter the number of nodes\n"); scanf("%d", &n);
printf("enter the values in adjacency matrix\n"); readGraph(a, n);
printf("enter the source and destination\n");
scanf("%d%d", &source, &destination);
if(dfs(a,n,visited, source, destination))
{ printf("path exists between %d and %d\n", source, destination); }
else printf(" No path exists between %d and %d\n", source, destination);
return 0;
}
```

4.c. Choose the BFS and DFS traversal for the graph given below. Node with key 1 is the source node. Also find the adjacent nodes of node 1.

![[Pasted image 20241211222407.png]]

5.a. Construct a trie for the following patterns: implicitly, horror, aging, aggressive, manner, absolute, apparently, manage.

5.b. Draw the 11-entry hash table that results from using the hash function h(i) = i mod 11
Given dataset contains - 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5. Show the hash table when collisions are handled by using (i) Chaining (ii) Linear Probing

5.c. Complete the body of display_of_length() for the following client code and the trie structure.

```c
typedef struct trie
{
int isLeaf;
struct trie *child[26];
}TRIE;
int main()
{
TRIE *root = createNode();
insert(root, "desi");
insert(root, "designer");
insert(root, "data");
insert(root,"ant");
char str[100];
printf("Patterns present in the trie data structure with length 4 are as below\n");
display_of_length (root,str,0,4);
return 0;
}
```

Expected output:

```
data
desi
```

---

# 21-Jul-2023

1.a. With a code snippet explain malloc(), calloc(), realloc() and free() functions.
Demonstrates which function reuses existing bytes to allocate new memory?

1.b. Write a C code snippet to create a circular singly linked list with the elements
14, 21, 11, 10, 18, and 19. Then, it will reverse the list and display the original and
reversed list.

1.c. Write a code snippet to implement a sparse matrix using an array of structures
in C

2.a. Convert the following expressions to postfix expressions. Show the clear steps
using stack data structure

```
i) (9-8)*4+(5/2)^2
ii) (9-1)*(4+1)^9
```

2.b. Write a C program that implements a double-ended queue (deque)

2.c. Develop a C program that demonstrates the push, pop, and display operations
of a stack for the given elements: 9, 8, 4, 4, 5, 5, 6, 2, 3, 0. Write the advantages of
stack data structure in the current scenario

3.a. Write a C code snippet to determine the height of a tree data structure

3.b. Develop a C program to evaluate binary expression tree for the following
expression i) ((9+8)*4)/6^2 ii) ((9-1)^1)*4*3

3.c. Implement priority queue using min max heap

4.a. Compare and contrast between BFS and DFS . Further list out the applications
of Graph in the current scenario

4.b. Build an AVL tree with the values 25, 21, 27, 15, 113, 71, 3, 89, 44, 76, 2, 1 .
What is total number of rotations performed (count double rotation as one
rotation example if one double rotation and one single rotation then it is total 2
rotations) What is the preorder, Inorder and postorder traversal of the resulting
tree. Further list applications of AVL tree in the present scenario

4.c. Demonstrate how do you implement a graph using adjacency matrix

5.a. Explain Separate Chaining & Open Addressing along with an example

5.b. Write a C program that demonstrates Open Addressing with Double Hashing
technique:

5.c. Write a C program that demonstrates rehashing in a hash table:

---

# 21-May-2023

1.a. Write a C program to calculate and print the 12th Fibonacci number

1.b. Write a C code snippet to create a circular doubly linked list with the elements
4, 2, 1, 11, 8, and 9. Then, it will reverse the list and display the original and
reversed lists

1.c. Write a function `ConvertTreeToList` which takes as parameter pointer to root
node of anon-empty binary search tree. This function should create a singly linked
list of all elements (data field from nodes) in the binary search tree, in ascending
order. (You should not use any sorting algorithm to sort the list after creating it).
Function should return pointer to the first node of the created SLL

> You can use the functions

```c
void InsertFront(node **phead,int ele)//to insert a node at front of singly
linked list, phead is pointer to head, head is pointer to first node in the list
void InsertEnd(node **phead,int ele ) // to insert a node at the end of singly linked
list
```

Node structure definition of BST

```c
typedef struct treenode
{
int data;
struct treenode *lchild; struct treenode *rchild;
}treenode;
Node structure definition of linked list
typedef struct Node
{
int data;
struct Node *link;
}Node;
Do not write code for InsertFront and InsertEnd functions
```

2.a. Convert the following expressions to postfix expressions. Show the clear steps
using stack data structure

```
i) (A+B)*D-E/F^E
ii) (X%Y)-(Z-W)^U
```

2.b. Write a C program that implements a priority queue using a binary heap

2.c. Write any 4 applications of stack in the current scenario. Further demonstrate
push and pop operations on stack for the following elements 6, 2, 3, 0

3.a. Define the following terms i) Forest ii) Depth of tree iii) Siblings iv) Leaf nodes

3.b.

Write a C function to evaluate an expression tree represented as a set of linked

nodes where leaf nodes represent operands and internal nodes operators. Node

structure is as follows

```c
struct tnode
{
struct tnode *left; struct tnode *right; char data
}
int evaluate(struct tnode *root)// root holds address of root node of the expression
tree
{ }
```

3.c. Demonstrate the implementation of threaded binary tree

4.a. Compare and contrast between BFS and DFS

4.b. Build an AVL tree with the values 15, 20, 24, 10, 13, 7,30. What is total number of
rotations performed (count double rotation as one rotation example if one double
rotation and one single rotation then it is total 2 rotations) What is the postorder
traversal of the resulting tree. Further list applications of AVL tree in the present
scenario.

4.c. Demonstrate how do you implement a graph using adjacency matrix

5.a. Explain linear probing technique used to handle collisions while constructing hash
tables. Consider a scenario in which all the given keys hash to same index position
would you prefer linear probing to resolve collisions? Justify your answer

5.b. Write a C program to implement linear probing

5.c. Write a C program to implement separate chaining

---

# 21-May-2024 A

1.a.

```c
struct node
{
int key;
struct node *link;
};
typedef struct node node_t;
struct list
{
node_t *head;
};
typedef struct list list_t;
```

Using the above structure declarations and given two singly lists in the ascending order, write a function to return the number of nodes that have the same keys across both the lists.

```
int to_check(list_t *, list_t *) : // function prototype to check if two lists are equal,
return 1 if equal and 0 if not equal
```

1.b. Given the following structure declarations

```c
struct node
{
int key;
struct node *next;
struct node *prev;
};
typedef struct node node_t;
struct dlist
{
node_t* head;
};
typedef struct dlist dlist_t;
```

Write a function to delete the first occurrence of a node given its value in a doubly linked list.

```c
void delete_node(dlist_t*, int) :delete the first occurance of a node given its
value
```

1.c. Implement stack of integers in C by using an array `int S{STACKSIZE`]. Where `S[0]`
is used to contain the index of the top element of the stack. `S[1]` through
`S[STACKSIZE-1]` contain the elements of the stack. Write the functions for push,
pop. Also check for stack overflow and underflow.

```
void push(int *S, int key) // implements push
int pop(int *S) // implements pop
```

1.d. Convert the following infix expression to post fix and prefix

```
A + ((( B - C) * ( D - E ) + F ) / G ) $ ( H - J)
Note : $ is the exponent operator
```

2.a. Given a Circular Queue of size MAX_SIZE, having n integers, Write a functions
to insert an element into the queue and delete element from the queue. The
following is the structure declaration and the function prototype to be used

```c
struct queue
{
int *cq;
int f,r,size;
};
typedef struct queue queue_t;
int qinsert(queue_t*,int); // inserts an integer
int qdelete(queue_t*); // deletes from the queu
```

2.b. Write a recursive function rsearch(tnode_t *root, int key) to search for a key
element in a binary search tree. use the following structure declarations.

```c
struct tnode
{
int data;
struct tnode *left;
struct tnode *right;
};
typedef struct tnode tnode_t;
struct tree
{
tnode_t *root;
};
typedef struct tree tree_t;
```

2.c. Write the inorder and post order traversal for the following binary tree

![[Pasted image 20241211224309.png]]

2.d. Create a binary search tree for the following numbers. 20, 30, 10, 18, 25, 40, 15, 12, 14, 13, 5 construct the tree after deletion of 10


3.a. Write a function to create a maximum heap using bottom up approach.
Create a maximum heap using bottom up approach for the following set of
elements 1,2,7,3,6,5,4,8,10

3.b. What is an AVL Tree? Insert the following keys in the order shown, to build
them into an AVL Tree A ,Z, B, Y, C, X, D, W,E


3.c. Given an undirected graph represented as adjacency matrix, write a function
using DFS to find the number of connected components. You need to write the
DFS function
![[Pasted image 20241211224400.png]]
For example , There are three connected components in the above graph.


3.d.

![[Pasted image 20241211224421.png]]

Starting from vertex 0 , list the vertices by the applying the Depth first search and Breadth First Search

4.a. Construct a 11-entry hash table using the hash function` h(i) = (2i+5) mod 11` to
hash keys 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5.

Show the hash table after collisions are handled by using

(i) Separate Chaining

(ii) Linear Probing.

4.b. Write a function to insert words consisting of characters of lower case into a
trie. Consider the following structure of the trie node

```c
struct trienode
{
struct trienode *child[26];
int endofword;
}
Function prototype : insert(struct trienode *root, char *key)
```

4.c. Create a B tree of order 5 by inserting the following keys in sequence :
`a, g, f, b, k, d, h, m, j, e, s, i, r, x, c, l, n, t, u, p` Draw the resultant tree after deleting the root element.

4.d. What does it mean for a directed graph to be strongly connected or weakly
connected?

---

# 21-May-2024 A

1.a. What is a Linked List? Write the structure definition for a node of a singly linked
list and provide a C function to count the number of nodes in a single linked list

1.b. Write a C function to sort the linked list. (Hint: swap only data part of the node
and not the node themselves)
Ex : 4→2→1 → 5. After sorting : 1→2→4→5

1.c. Given a pointer to the first node of a doubly linked list, write a C function to
insert a node with data x after a node with data y. The function should take care of
all the boundary conditions. Mention any two applications of Doubly linked list

2.a. Convert the following infix expression to its equivalent postfix and prefix
expressions. `(A+B)*C-(D-E)*(F+G)`

2.b. Write a C function rem_left() that removes an element from the left of a
double-ended queue implemented using a doubly linked list. (front and rears are
pointers to the first and last node of the queue) (your code should handle all
boundary conditions)

2.c. Consider the following functions for a stack of integers
push: pushes an element into the stack, Pop: deletes the element from the stack.
peep: returns the top element of the stack.

Show the contents of the stack S after each of the following operations (Assume we start with an empty stack)

`push(S,1),push(S,2),pop(S),peep(S),push(S,3),push(S,4),pop(S),pop(S),peep(S)`

3.a. Draw a Binary Search Tree by inserting the following keys in the given order
44, 17, 88, 32, 28, 65, 54, 29, 82, 76, 97
(i). Redraw after adding 80 and 35. (ii) Redraw after 44 is removed from the BST
obtained in (i)

3.b. Binary Tree node structure is defined as

```c
struct TreeNode {
int data;
struct TreeNode* left;
struct TreeNode* right;
};
```

Provide C code for iterative inorder traversal of the Binary Tree

3.c. The height of the tree is the path from the root to the deepest leaf node. Write
a C function to find the height of a binary tree
a) implemented by an array
b) implemented by linked nodes

4.a. What is a heap? Create a maximum heap using bottom up approach for the
following set of elements 1,2,7,3,6,5,4,8,10

4.b. What do you mean by the balance factor of a node in an AVL Tree?
Insert the following elements into an initially empty AVL tree. Show the rotations
and all the intermediate trees.
73,11,56,97,88,45,55,61

4.c. Assume a graph is represented using Adjacency matrix representation.
Write a C function to traverse the graph using Depth First Search Traversal (DFS).
Trace the function to traverse the given graph using DFS

![[Pasted image 20241211223505.png]]

5.a. Let us consider a simple hash function as “key mod 7” and a sequence of keys
as 50, 700, 76, 85, 92, 73, 101. Give the hash table contents when collisions are
handled using linear probing

5.b. Define the node of a Trie Tree and write a C function to insert a word in a Trie
tree. Assume the alphabet set is {A to Z}

5.c. Write C function to print all the words of specific length stored in a Trie Tree.

---

# 22-May-2024

1.a. Write a program to find the length of a doubly linked list.
Ex : 1<->3 <->2<->8<->7<->6 should print 6. If the list is empty, print 0. Handle the
boundary conditions. Assume the following structure definition:

```c
struct Node
{
int data;
struct Node* prev;
struct Node* next;
};
```

1.b. Write a C function to convert an infix expression to prefix using stack

1.c. Write a function to insert a node from the front of a circular list

```c
struct node
{
int data;
struct node *next;
}
void front_insert(struct node **p, int x)
{
//TO DO
}
```

1.d. With steps, convert infix to postfix and prefix form:

```
A-B/(C*D^E)
```

2.a. . A circular Queue is implemented using an array and is defined as follows

```c
typedef struct Queue
{
int front, rear,capacity;
int *array;
}Queue;
Provide C code for the following functions
int Isfull(Queue *PQ) // PQ is pointer to Queue type variable
int sempty(Queue *PQ)
int Insert(Queue *PQ, int ele)// successful insertion return 1 and 0 otherwise
int Delete( Queue *PQ)// return the deleted element and -1 for unsuccessful
deletion
```

2.b. Construct a Binary Search Tree for the following

```
16,17,12,19,13,15,21,14,8,11,22.
Traverse in inorder & postorder
```

2.c. Write a Program to create an expression tree.

2.d. Mention the AVL tree traversal mechanism

3.a. With step construct a B-Tree of order 4 for the following : 23,45,78,67,45,22,18.

3.b. With steps, construct a maximum heap for the following list using top down
approach: 1 , 5, 4, 2, 3, 7, 9, 8.

3.c. Write a C program to implement DFS for a digraph using Adjacency List

4.a.
i)Explain the different ways of representing a graph with a suitable example: 2Marks
ii)How does the BFS graph traversal work? Explain with a simple example: 4Marks


4.b.
1. Construct a trie for the following patterns:

```
implicity, sample, horror, simple, aging, aggressive, manner, absolute, aparently, manage, system, present
```

2. Mention any 4 applications of Trie Trees?

4.c Write a function to insert element into hash.

4.d. Consider the following:

```
input = 19,26, 13, 68,18
hash functiom h(k)= k mode 6
```

By applying separate chaining, draw hash table

---
