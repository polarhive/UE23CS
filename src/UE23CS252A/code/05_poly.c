#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the node structure for linked list representation of a polynomial
struct node
{
    int coeff;         // Coefficient of the term
    int px;            // Power of x
    int py;            // Power of y
    struct node *next; // Pointer to the next node (term)
};

// Function Prototypes
void insert_tail(int, int, int, struct node **); // Insert a term at the tail of the list
void display(struct node *);                     // Display the polynomial
int polyevaluate(struct node *);                 // Evaluate the polynomial at specific x and y values

int main()
{
    struct node *head; // Head pointer of the polynomial list
    head = NULL;       // Initialize the polynomial list as empty
    int cf, px, py, result;

    // Input loop for polynomial terms (coefficient, powers of x and y)
    while (1)
    {
        printf("\nEnter the coefficient..");
        scanf("%d", &cf);

        // Break the loop if the coefficient is 0
        if (cf == 0)
            break;

        printf("\nEnter the power of x..");
        scanf("%d", &px);

        printf("\nEnter the power of y...");
        scanf("%d", &py);

        // Insert the term into the polynomial list
        insert_tail(cf, px, py, &head);
    }

    // Display the polynomial
    printf("\nThe polynomial created...\n");
    display(head);

    // Evaluate the polynomial at specific x and y values
    printf("\nEvaluating the polynomial..\n");
    result = polyevaluate(head);

    // Print the result of evaluation
    printf("Result=%d", result);
}

// Function to evaluate the polynomial at given x and y values
int polyevaluate(struct node *p)
{
    int x, y, sum = 0;

    // Ask user for the values of x and y
    printf("\nEnter the value of x and y..");
    scanf("%d %d", &x, &y);

    // Traverse the linked list to evaluate the polynomial
    while (p != NULL)
    {
        // Calculate the term value: coeff * x^px * y^py
        sum = sum + (p->coeff * pow(x, p->px) * pow(y, p->py));
        p = p->next; // Move to the next term
    }

    // Return the final result of the polynomial evaluation
    return sum;
}

// Function to display the polynomial
void display(struct node *q)
{
    while (q != NULL)
    {
        // Display the coefficient with proper sign
        if (q->coeff > 0)
            printf("+%d", q->coeff);
        else
            printf("%d", q->coeff);

        // Display the power of x, if applicable
        if (q->px > 0)
        {
            if (q->px == 1)
                printf("X");
            else
                printf("X^%d", q->px);
        }

        // Display the power of y, if applicable
        if (q->py > 0)
        {
            if (q->py == 1)
                printf("Y");
            else
                printf("Y^%d", q->py);
        }

        // Move to the next term
        q = q->next;
    }
}

// Function to insert a term at the tail (end) of the polynomial list
void insert_tail(int cf, int px, int py, struct node **p)
{
    struct node *q, *temp;

    // Create a new node for the term
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = cf;
    temp->px = px;
    temp->py = py;
    temp->next = NULL; // It's the last node initially

    q = *p; // Start from the head of the list

    // If the list is empty, the new node becomes the head
    if (q == NULL)
        *p = temp;
    else
    {
        // Traverse to the last node
        while (q->next != NULL)
            q = q->next;

        // Add the new node to the end of the list
        q->next = temp;
    }
}
