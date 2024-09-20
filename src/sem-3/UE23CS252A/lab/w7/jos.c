#include <stdio.h>
int josephus(int n, int k) {
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = (result + k) % i;
    }
    return result + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", josephus(n, k));
    return 0;
}

