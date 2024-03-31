#include <stdio.h>
void readArray(int arr[], int n);
void reverseArray(int arr[], int n);
void printArray(int arr[], int n);
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    readArray(arr, n);
    reverseArray(arr, n);
    // printf("Reversed Array is\n");
    printArray(arr, n);
    return 0;
}
void readArray(int arr[], int n)
{
    int *p;
    p = arr;
    for (int i = 0; i < n; i++)
        scanf("%d", p++);
}
void reverseArray(int arr[], int n)
{
    int *lp, *rp;
    lp = arr;
    rp = &arr[n - 1];
    while (lp < rp)
    {
        *lp = *lp ^ *rp;
        *rp = *rp ^ *lp;
        *lp = *lp ^ *rp;
        lp++;
        rp--;
    }
}
void printArray(int arr[], int n)
{
    int *p;
    p = arr;
    for (int i = 0; i < n; i++)
        printf("%d ", *p++);
}