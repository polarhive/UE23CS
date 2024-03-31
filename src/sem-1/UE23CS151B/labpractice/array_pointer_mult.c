#include <stdio.h>
void m_array(int *, int);
int main()
{
    int i, n, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); // Read the input and store it in the array
    }
    m_array(a, n);
    return 0;
}
void m_array(int *p, int n)
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        *(p + i) = *(p + i) * (m + n);
        printf("%d ", *(p + i));
    }
}