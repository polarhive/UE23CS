#include<stdio.h>
int main() {
    printf("%s","Enter your number n: \n");
    int n;
    int sum=0;
    scanf("%d", &n);

    while (n>0) {
        sum += n; 
        n--;
    }

    printf("%d", sum);
    
    return 0;
}
