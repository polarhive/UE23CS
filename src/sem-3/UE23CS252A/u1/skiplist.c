#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
    struct NODE *prev;
    struct NODE *down; // Pointer to the next level below
} NODE;

typedef struct SKIPLIST
{
    NODE *head; // Pointer to the top-left node
    int levels; // Number of levels in the skip list
} SKIPLIST;

NODE *createNode(int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->down = NULL;
    return newNode;
}

SKIPLIST *createSkipList()
{
    SKIPLIST *skipList = (SKIPLIST *)malloc(sizeof(SKIPLIST));
    skipList->head = createNode(0); // dummy node as the head
    skipList->levels = 1; // initialize with one level
    return skipList;
}

int main()
{
    SKIPLIST *skipList = createSkipList();

    // TODO: Perform operations on the skip list

    return 0;
}
