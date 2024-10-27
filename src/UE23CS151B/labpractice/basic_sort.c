#include <stdio.h>
void sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) > *(a + j))
            {
                int tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    sort(arr, n);
    for (int i = 0; i < n; ++i)
        printf("%d\n", arr[i]);
    return 0;
}