#include <stdio.h>
#define MAX 100
int MaxElem(int[]);
int n;
int main()
{
    int arr1[MAX], hstno, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    hstno = MaxElem(arr1); // call the function MaxElem to return the largest element
    printf("%d", hstno);
    return 0;
}
int MaxElem(int arr1[])
{
    static int i = 0, hstno = -9999;
    if (i < n)
    {
        if (hstno < arr1[i])
            hstno = arr1[i];
        i++;
        MaxElem(arr1); // calling the function MaxElem itself to compare with further element
    }
    return hstno;
}