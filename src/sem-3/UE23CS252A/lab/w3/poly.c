#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int coeff;
    int degree;
    struct Node *next;
} Node;

Node *createNode(int coeff, int degree)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->degree = degree;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **poly, int coeff, int degree)
{
    Node *newNode = createNode(coeff, degree);
    newNode->next = *poly;
    *poly = newNode;
}

// input polynomial terms
Node *input(int terms)
{
    Node *poly = NULL;
    int coeff, degree;
    for (int i = 0; i < terms; i++)
    {
        scanf("%d %d", &coeff, &degree);
        insert(&poly, coeff, degree);
    }
    return poly;
}

// sum two polynomials
Node *sum(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->degree == p2->degree)
        {
            int newCoeff = p1->coeff + p2->coeff;
            if (newCoeff != 0)
            {
                insert(&result, newCoeff, p1->degree);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->degree > p2->degree)
        {
            insert(&result, p1->coeff, p1->degree);
            p1 = p1->next;
        }
        else
        {
            insert(&result, p2->coeff, p2->degree);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insert(&result, p1->coeff, p1->degree);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insert(&result, p2->coeff, p2->degree);
        p2 = p2->next;
    }

    return result;
}

// evaluate a polynomial for a given x
int eval(Node *poly, int x)
{
    int result = 0;
    while (poly != NULL)
    {
        result += poly->coeff * pow(x, poly->degree);
        poly = poly->next;
    }
    return result;
}

// free memory
void destroy(Node *poly)
{
    Node *temp;
    while (poly != NULL)
    {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main()
{
    int m, n, x;
    scanf("%d %d", &m, &n);
    scanf("%d", &x);

    Node *poly1 = input(m);
    Node *poly2 = input(n);

    Node *resultPoly = sum(poly1, poly2);

    if (resultPoly == NULL)
    {
        printf("-1\n");
    }
    else
    {
        int result = eval(resultPoly, x);
        printf("%d\n", result);
    }

    destroy(poly1);
    destroy(poly2);
    destroy(resultPoly);

    return 0;
}
