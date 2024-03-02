#include <stdio.h>
int main() {
    int a[5];
    printf("%s","enter the elements");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]); 

//        scanf("enter number: %d", &n); doesnt work
//        a[i]=n;
    
    }

    for (int j = 0; j < 5; j++) {
        printf("\t%d", a[j]);
    }
    return 0;
}
