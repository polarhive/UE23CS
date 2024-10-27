#include <stdio.h>

int binary_search(int *array, int key, int start, int end);

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int result = binary_search(arr, key, 0, n - 1);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", key, result);
    }
    else
    {
        printf("Element %d not found\n", key);
    }

    return 0;
}

int binary_search(int *array, int key, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;

    if (array[mid] == key)
    {
        return mid;
    }
    else if (array[mid] < key)
    {
        return binary_search(array, key, mid + 1, end);
    }
    else
    {
        return binary_search(array, key, start, mid - 1);
    }
}
