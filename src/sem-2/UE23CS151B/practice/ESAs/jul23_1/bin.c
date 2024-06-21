#include <stdio.h>

int binary_search(int *array, int size, int value)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == value)
        {
            return mid;
        }
        else if (array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 10;

    int index = binary_search(array, size, value);
    if (index != -1)
    {
        printf("Element found at index: %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }
}
