#include <stdio.h>
void print_array(int *, int);
int main()
{
    int i, n, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); // Read the input and store it in the array
    }
    print_array(a, n);
    return 0;
}
void print_array(int *p, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", *(p + i)); // Print each element in reverse order
    }
}