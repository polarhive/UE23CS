
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct stack
{
	node_t *top;
};

typedef struct stack stack_t;

void init(stack_t*);
void push(stack_t *, int);
int pop(stack_t*);
void display(stack_t*);
