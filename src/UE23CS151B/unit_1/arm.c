#include<stdio.h>
int main() {
    printf("%s","Enter your number n: \n");
    int n;
    int t;
    int rem=0;
    int sum=0;
    scanf("%d", &n);
    t=n;

    while (n>0) {
        rem=n%10;
        sum+=(rem)*(rem)*(rem);
        n=n/10;
    }

    if(sum==t){
    printf("%s\n", "yes");
    }
    else{
    printf("%s\n", "no");
    }
    return 0;
}

