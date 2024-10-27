// Write a program to print the maximum element in ‘n’ array. Make sure that array is
// passed as actual parameter and pointer is taken as a formal.

#include <stdio.h>
int maxArray(int[], int);
int main()
{
    int arr[50], i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // passing array to the function
    int max_element = maxArray(arr, n);
    printf("Max element in array = %d", max_element);
    return 0;
}
int maxArray(int *p, int n)
{
    int max_element = *p;
    for (int i = 1; i < n; i++)
    {
        if (*(p + i) > max_element)
        {
            max_element = *(p + i);
        }
    }
    return max_element;
}