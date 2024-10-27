#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int n)
{
    if (n < 2)
    {
        return -1;
    }
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first)
        {
            second = arr[i];
        }
    }
    return (second == INT_MIN) ? -1 : second;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 1)
    {
        printf("-1\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", findSecondLargest(arr, n));
    return 0;
}
