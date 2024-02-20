#include<stdio.h>
int main() {
    printf("%s","Enter your 2 numbers m,n: \n");
    int m;
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    while (m!=n) {
        if (m>n) {m-=n;}
        else {n-=m;}
    }
    printf("%d\n", m);
    return 0;
}


