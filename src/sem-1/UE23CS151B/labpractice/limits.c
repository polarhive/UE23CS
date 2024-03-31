/*
Take an integer (say A) and a long long integer(say B) as input and perform
following operations:
• Subtract A from max value of INT allowed in 'C'.
• Subtract B from max value of LONG LONG INT allowed in 'C'.
*/

#include <stdio.h>
#include <limits.h>
int main()
{
    int A;
    long long B;
    scanf("%d", &A);
    scanf("%lld", &B);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    int result1 = INT_MAX - A;
    long long result2 = LLONG_MAX - B;
    printf("INT_MAX - A = %d\n", result1);
    printf("LLONG_MAX - B = %lld\n", result2);
    return 0;
}