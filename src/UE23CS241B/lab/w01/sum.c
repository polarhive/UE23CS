/* Sum Sequences:
 *
 * In the Labyrinth of Numbers, a magical lock requires the adventurer to
 * determine the number of possible sequences of positive integers that sum up
 * to a given number N. 
 *
 * The sequence must use only positive integers.
 *
 * The order of integers in the sequence matters. For example, (2+1 is
 * considered different from 1+2). Your task is to calculate the total number
 * of such sequence using recursion.
 */

#include <stdio.h>

int res[101]; // (1 ≤ N ≤ 100)

int totalCombinations(int n) {
    if (n == 0) {
        return 1;
    }
    if (res[n] != -1) {
        return res[n];
    }
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += totalCombinations(n - i);
    }
    res[n] = total;
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 100; i++) {
        res[i] = -1;
    }
    int result = totalCombinations(n);
    printf("%d\n", result);
    return 0;
}
