#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Adjacency matrix representation
int adj[MAX_NODES][MAX_NODES];

// Function to add an edge in the graph
void addEdge(int u, int v)
{
    adj[u][v] = 1;
}

// detect DFS cycle
bool dfs(int v, bool visited[], bool recStack[], int numNodes)
{
    visited[v] = true;
    recStack[v] = true;

    // Recur for all vertices adjacent to this vertex
    for (int i = 0; i < numNodes; i++)
    {
        if (adj[v][i])
        {
            if (!visited[i] && dfs(i, visited, recStack, numNodes)) return true;
            else if (recStack[i]) return true; // A cycle is found
        }
    }

    recStack[v] = false;
    return false;
}

// Function to check if the graph contains a cycle
bool isCyclic(int numNodes)
{
    bool visited[MAX_NODES] = {false};
    bool recStack[MAX_NODES] = {false};

    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i] && dfs(i, visited, recStack, numNodes)) return true;
    }
    return false;
}

int main()
{
    int u, v, numNodes = 0;

    // Initialize the adjacency matrix
    for (int i = 0; i < MAX_NODES; i++)
    {
        for (int j = 0; j < MAX_NODES; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Read edges until a negative integer is entered
    while (1)
    {
        scanf("%d %d", &u, &v);
        if (u < 0 || v < 0)
        {
            break; // Stop input if negative number is entered
        }
        addEdge(u - 1, v - 1); // Convert to 0-based index

        // Update the number of nodes
        if (u > numNodes) numNodes = u;
        if (v > numNodes) numNodes = v;
    }

    // Check for cycle in the graph
    if (isCyclic(numNodes)) printf("The graph contains a cycle.\n");
    else printf("The graph does not contain a cycle.\n");
    
    return 0;
}
