#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void solve(int** arr, int* visited, int index, int count, int total, int* min, int n, int* printer, int* result, int rIndex) {
    if (count == n - 1) {
        if (arr[index][0] <= 0) {
            return;
        }
        total += arr[index][0];
        if (total < *min) {
            *min = total;
            for (int i = 0; i < rIndex; i++) {
                result[i] = printer[i];
            }
            result[rIndex] = 0;
        }
        return;
    }

    for (int i = 1; i < n; i++) {
        if (arr[index][i] <= 0 || visited[i]) {
            continue;
        }
        visited[i] = 1;
        printer[rIndex] = i;
        solve(arr, visited, i, count + 1, total + arr[index][i], min, n, printer, result, rIndex + 1);
        visited[i] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int min = INT_MAX;
    int** arr = malloc(n * sizeof(int*));
    int* visited = calloc(n, sizeof(int));
    int* printer = malloc((n + 1) * sizeof(int));
    int* result = malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printer[0] = 0;
    solve(arr, visited, 0, 0, 0, &min, n, printer, result, 1);

    if (min == INT_MAX) {
        printf("Path does not exist\n");
    } else {
        printf("Minimum Cost: %d\n", min);
        printf("Optimal Path: ");
        for (int i = 0; i <= n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(visited);
    free(printer);
    free(result);

    return 0;
}

