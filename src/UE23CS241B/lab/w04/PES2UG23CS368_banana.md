# DAA: Banana Problem

> Name: Nathan Matthew Paul
> SRN: PES2UG23CS368
> Section: 4F
> Date: 2025-02-20

> [!Question]
>The Quick Courier In the town of Graphville, there is a quick courier named
>Lexi who needs to deliver packages to several businesses located in various
>districts. Graphville is well-connected, but Lexi wants to ensure the route
>taken is not only efficient but also predictable in order, so her dispatch
>team can easily track her progress.

> Lexi decides to always take the lexicographically smallest path that visits
> each district exactly once and returns to the starting district. As a budding
> programmer, you are tasked with helping Lexi find this path using a program.
>
> Input Format- The first line contains an integer n (2 ≤ n ≤ 10), the number of
> districts.
>
> Each of the next n lines contains n integers, where the j-th integer in the
> i-th line represents the travel cost from district i to district j. If the
> number is -1, it means that the path between the two districts does not exist.
>
> Output Format- Output the lexicographically smallest path (as a sequence of
> district indices) that visits each district exactly once and returns to the
> starting district. If the path does not exist, return -1

---

# Code

```c
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
		return -1;
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
```

# Testcases (Output)

## Testcase: 1

![[Pasted image 20250220150654.png]]

## Testcase: 2

![[Pasted image 20250220150728.png]]

## Testcase: 3

![[Pasted image 20250220150758.png]]

## Testcase: 4

![[Pasted image 20250220150828.png]]
