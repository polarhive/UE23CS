#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    scanf("%d+%di", &a, &b);
    float r = sqrt(pow(a, 2) + pow(b, 2));
    float t = acos(a / r);
    printf("%.2f(cos(%.2f)+isin(%.2f))\n", r, t, t);
    printf("%.2fe^(%.2fi)", r, t);
    return 0;
}