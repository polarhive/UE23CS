#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Directions for up, down, left, right
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to perform BFS and calculate the minimum time to corrupt all servers
int minTimeToCorrupt(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    int queue[MAX_SIZE * MAX_SIZE][3];
    int front = 0, rear = 0;
    int time = 0;

    // queue all initially corrupted servers
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
            {
                queue[rear][0] = i;
                queue[rear][1] = j;
                queue[rear][2] = 0; // initial time for corrupted servers
                rear++;
            }
        }
    }

    // Perform BFS
    while (front < rear)
    {
        int x = queue[front][0];
        int y = queue[front][1];
        int currentTime = queue[front][2];
        front++;

        // Check adjacent cells in all directions
        for (int d = 0; d < 4; d++)
        {
            int newX = x + directions[d][0];
            int newY = y + directions[d][1];

            // Check if the new position is within bounds and has a functional server
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1)
            {
                grid[newX][newY] = 2; // Corrupt this server
                queue[rear][0] = newX;
                queue[rear][1] = newY;
                queue[rear][2] = currentTime + 1;
                rear++;
                time = currentTime + 1; // Update time
            }
        }
    }

    // Check if there's any functional server left
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1; // Not all servers can be corrupted
            }
        }
    }

    return time;
}

int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int grid[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = minTimeToCorrupt(grid, rows, cols);
    printf("%d\n", result);

    return 0;
}
