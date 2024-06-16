#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p1 = (int*)malloc(sizeof(int));
    *p1 = 250;
    printf("%d ", *p1);
    int *p2 = p1;
    printf(" %d ", *p2);
    *p2 = 999;
    printf("%d ",*p1);
    printf("%d ",*p2);
    free(p1);
    p1 = NULL;
    p2 = NULL;
}
