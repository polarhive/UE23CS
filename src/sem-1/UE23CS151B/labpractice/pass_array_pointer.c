// Write a program to calculate the sum of all ‘ n’ elements in the given array. Make sure
// that array is passed as a parameter to user defined function.
#include <stdio.h>
int calculateSum(int num[], int n);
int main()
{
    int result, num[50], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    // num array is passed to calculateSum()
    result = calculateSum(num, n);
    printf("Result = %d", result);
    return 0;
}
int calculateSum(int num[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += num[i];
    }
    return sum;
}