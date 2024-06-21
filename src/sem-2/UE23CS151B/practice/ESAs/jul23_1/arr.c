#include <stdio.h>

int findSmallest(int arr[], int n)
{
    int smallest = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main()
{
    int arr[] = {9, 7, 5, 3, 10, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest = findSmallest(arr, n);
    printf("The smallest element in the array is: %d\n", smallest);
}
