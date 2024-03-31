#include <stdio.h>
int main()
{
    float n;
    int k;
    scanf("%f", &n);
    scanf("%d", &k);

    printf("%.0f\n", n);
    printf("%e\n", n);
    printf("%.*f\n", k, n);
    return 0;
}