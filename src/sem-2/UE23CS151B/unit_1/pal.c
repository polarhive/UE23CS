#include<stdio.h>
int main() {
    printf("%s","Enter your number n: \n");
    int n;
    int rem=0;
    int reverse=0;
    scanf("%d", &n);
    int o=n;

    while (n>0) {
        rem=n%10;
        reverse = reverse * 10 + rem;
        n=n/10;
    }

    if (o==reverse){
    printf("%s\n", "yes");
    }
    else{
    printf("%s\n", "no");
    }
    return 0;
}

