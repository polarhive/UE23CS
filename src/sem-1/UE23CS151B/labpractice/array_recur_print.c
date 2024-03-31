#include <stdio.h>
void printArray(int arr[], int start, int len)
{
    if (start >= len)
        return;
    printf("%d\n", arr[start]);
    printArray(arr, start + 1, len);
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printArray(arr, 0, n);
    return 0;
}