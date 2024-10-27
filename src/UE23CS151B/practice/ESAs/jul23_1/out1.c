#include <stdio.h>
int main()
{
    int arr[6] = {10, 7, 11, 18};
    int *arrp[10];
    arrp[9] = &arr[3];
    printf("%d ", *arrp[9]);
    arrp[11] = &arr[5];
    printf("%d\n", *arrp[11]);
}
