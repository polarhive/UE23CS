#include <stdio.h>
int average(int *, int);
int main()
{
    int arr[50], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    average(arr, n);
}
int average(int *p, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(p + i);
    }
    float a = sum / n;
    printf("The average of elements is : %f", a);
    return 0;
}