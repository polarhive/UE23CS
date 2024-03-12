#include <stdio.h>
int fact(int);
int main(){
    int n;
    printf("Enter value of n: \n");
    scanf("%d", &n);
    printf("The fact is %d\n", fact(n));
    return 0;
}
int fact(int n){
    if (n==0||n==1) 
        return 1;
    else 
        return n*fact(n-1);
}
