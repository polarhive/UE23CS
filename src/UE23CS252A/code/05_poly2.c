#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coeff;         // Coefficient of the term
    int px;            // Power of x
    int py;            // Power of y
    int flag;          // Used to check if the term is already added
    struct node *link; // Pointer to the next term
};

typedef struct node node_t;

struct list
{
    struct node *head; // Head of the linked list
};

typedef struct list list_t;

/* Function prototypes */
void init_list(list_t *);                  // Initializes a polynomial list by setting its head to NULL.
void create_polynomial(list_t *);          // Creates a polynomial by inserting terms from user input.
void display(list_t *);                    // Prints the polynomial.
void add(list_t *, list_t *, list_t *);    // Adds two polynomials.
void insert(list_t *, int, int, int);      // Inserts a term at the end of the polynomial list.
void append(list_t *, list_t *, list_t *); // Appends remaining terms after addition.

int main()
{
    struct list l1, l2, l3;
    init_list(&l1); // Initialize polynomial l1
    init_list(&l2); // Initialize polynomial l2
    init_list(&l3); // Initialize polynomial l3

    printf("Enter the first polynomial terms:\n");
    create_polynomial(&l1); // Create the first polynomial from user input

    printf("Enter the second polynomial terms:\n");
    create_polynomial(&l2); // Create the second polynomial from user input

    printf("First polynomial:\n");
    display(&l1); // Display the first polynomial

    printf("Second polynomial:\n");
    display(&l2); // Display the second polynomial

    add(&l1, &l2, &l3);    // Add the two polynomials and store the result in l3
    append(&l1, &l2, &l3); // Append any remaining terms from both polynomials to l3

    printf("\nThird polynomial (result):\n");
    display(&l3); // Display the result polynomial

    return 0;
}

/* Creates a polynomial by inserting terms from user input */
void create_polynomial(list_t *ptr_list)
{
    while (1)
    {
        int co;   // Coefficient
        int x, y; // Powers of x and y

        /* Pseudocode:
         * 1. Ask the user to input a coefficient.
         * 2. If the coefficient is 0, break the loop.
         * 3. Otherwise, ask for powers of x and y.
         * 4. Insert the term into the polynomial list.
         */
        printf("Enter the coeff: ");
        scanf("%d", &co);
        if (co == 0)
        {
            break; // Exit loop if coefficient is zero
        }
        printf("Enter powx powy: ");
        scanf("%d %d", &x, &y);
        insert(ptr_list, co, x, y); // Insert the term into the polynomial list
    }
}

/* Inserts a new term into the polynomial list at the end */
void insert(list_t *ptr_list, int co, int x, int y)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->coeff = co;  // Set the coefficient
    temp->px = x;      // Set the power of x
    temp->py = y;      // Set the power of y
    temp->flag = 1;    // Mark the term as not yet added to result
    temp->link = NULL; // No next node yet

    if (ptr_list->head == NULL)
    {
        ptr_list->head = temp; // Set the first term if the list is empty
    }
    else
    {
        node_t *p = ptr_list->head;
        while (p->link != NULL) // Traverse to the end of the list
        {
            p = p->link;
        }
        p->link = temp; // Add the new term at the end
    }
}

/* Displays the terms of a polynomial */
void display(list_t *ptr_list)
{
    node_t *pres;
    if (ptr_list->head == NULL)
    {
        printf("\nEmpty list.\n"); // If the list is empty, print a message
    }
    else
    {
        pres = ptr_list->head; // Start from the head of the list
        while (pres != NULL)   // Iterate through the list
        {
            printf("%d %d %d -> ", pres->coeff, pres->px, pres->py); // Print each term
            pres = pres->link;
        }
    }
    printf("\n");
}

/* Adds two polynomials */
void add(list_t *ptr_list1, list_t *ptr_list2, list_t *ptr_list3)
{
    node_t *i, *j;
    i = ptr_list1->head;
    j = ptr_list2->head;

    /* Pseudocode for addition:
     * 1. For each term in the first polynomial, iterate through the second polynomial.
     * 2. If matching terms (same powers of x and y) are found, add their coefficients.
     * 3. Mark the terms as added by setting their flag to 0 and insert the result into ptr_list3.
     */
    for (i = ptr_list1->head; i != NULL; i = i->link)
    {
        for (j = ptr_list2->head; j != NULL; j = j->link)
        {
            if (i->px == j->px && i->py == j->py) // Matching powers
            {
                int k = i->coeff + j->coeff; // Add the coefficients
                i->flag = 0;
                j->flag = 0;
                insert(ptr_list3, k, i->px, i->py); // Insert the result term into result list
            }
        }
    }
}

/* Appends the remaining terms from both polynomials to the result list */
void append(list_t *ptr_list1, list_t *ptr_list2, list_t *ptr_list3)
{
    node_t *i, *j;
    i = ptr_list1->head;
    j = ptr_list2->head;

    /* Pseudocode for appending:
     * 1. For each term in the first polynomial, if it wasn't added, append it to the result list.
     * 2. Do the same for each term in the second polynomial.
     */
    while (i != NULL)
    {
        if (i->flag == 1) // Term not added yet
        {
            insert(ptr_list3, i->coeff, i->px, i->py); // Append it to the result list
        }
        i = i->link;
    }

    while (j != NULL)
    {
        if (j->flag == 1) // Term not added yet
        {
            insert(ptr_list3, j->coeff, j->px, j->py); // Append it to the result list
        }
        j = j->link;
    }
}

/* Initializes a polynomial list by setting its head to NULL */
void init_list(list_t *ptr_list)
{
    ptr_list->head = NULL; // Set the head to NULL to initialize an empty polynomial
}
