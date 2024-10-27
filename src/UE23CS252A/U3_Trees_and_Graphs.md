# BST (Binary Search Tree)

A **Binary Search Tree (BST)** is a type of binary tree where every node has at most two children, and these children follow the binary search property. This property ensures that:

- For any given node:
    - The value of all the nodes in the left subtree is **less than** the value of the current node.
    - The value of all the nodes in the right subtree is **greater than** the value of the current node.

This property allows for efficient searching, insertion, and deletion operations in **O(log n)** time, where `n` is the number of nodes in the tree, provided the tree is balanced.

### Example:

Consider the following **BST**:

``` mathematica
        10
       /  \
      5    20
     / \   / \
    3   7 15  25

```

In this tree:

- The root node is `10`.
- All values in the left subtree (`5, 3, 7`) are less than `10`.
- All values in the right subtree (`20, 15, 25`) are greater than `10`.

Operations like searching for a value, inserting a new value, or deleting an existing node can be performed efficiently due to the BST property.

---

# Graphs

Graph traversal is the process of visiting each node (or vertex) in a graph. Traversing a graph is more complex than traversing a list or tree because of several factors:

1. A graph may have **no fixed starting node** (no "root"). Therefore, traversal can begin from **any node**. Additionally, there may be nodes that are not reachable from the starting node.
2. There can be multiple paths to reach the same node.
3. There is no natural order for visiting the adjacent nodes.
4. A node may have **multiple predecessors**, making it possible to visit a node before all of its predecessors are visited.

### Two Standard Algorithms for Traversing Graphs

- **Depth First Search (DFS)**: DFS explores as far as possible along each branch before backtracking.
- **Breadth First Search (BFS)**: BFS explores all neighbors at the present depth before moving to nodes at the next depth level.

---

# DFS

**Depth-First Search (DFS)** traverses a graph in a depthward motion. It uses a **stack** (or recursion) to remember vertices to visit after hitting a dead end. The process begins at an arbitrary vertex and explores each unvisited adjacent vertex until all vertices have been visited.

> Consider the following graph:

``` mathematica
  A---B---D
  |   |
  C   E
```

If we start at `A` and apply DFS, the traversal would look like:

- Start at `A`, mark as visited.
- Visit `B` (adjacent to `A`), mark as visited.
- Visit `D` (adjacent to `B`), mark as visited.
- Backtrack to `B` (since no unvisited adjacent vertices of `D`).
- Visit `E` (adjacent to `B`), mark as visited.
- Backtrack to `A` and visit `C`, mark as visited.
- All nodes are now visited.

> DFS follows the path deeply before backtracking, exploring all possible paths from a vertex before moving to a new start vertex.

---

## Algorithm

1. Select a node `u` as the starting vertex, push `u` onto the stack, and mark it as visited.
2. While the stack is not empty:
    - For vertex `u` on top of the stack, find the next immediate adjacent vertex `v`:
        - If `v` is adjacent:
            - If `v` is not visited:
                - Push `v` onto the stack and mark it as visited.
            - Else, ignore `v`.
        - Else, remove `u` from the stack.
3. If the graph is disconnected, repeat steps 1 and 2 for any unvisited vertex.

## Example

``` mathematica
   1
  / \
 2   3
 |   |
 4   5

```

For DFS starting at `1`, the traversal is: `1 -> 2 -> 4 -> 3 -> 5`

``` mathematica
Initial stack: [1]
Visit 1, push adjacent 2, 3 -> stack: [1, 2]
Visit 2, push adjacent 4 -> stack: [1, 2, 4]
Visit 4, no more adjacent -> pop 4 -> stack: [1, 2]
Pop 2, pop 1, move to 3 -> stack: [3]
Visit 3, push adjacent 5 -> stack: [3, 5]
Visit 5 -> done
```

---

# BFS

**Breadth-First Search (BFS)** traverses the graph level by level, exploring neighbors at the current depth before moving deeper. BFS uses a **queue** to manage the vertices yet to be processed. The process starts at a given vertex and visits all its neighbors, then processes the neighbors of each vertex in turn.

> Consider the same graph:

``` mathematica
  A---B---D
  |   |
  C   E
```

Starting at `A`, BFS would visit nodes in this order:

- Start at `A`, mark as visited.
- Visit neighbors of `A`: `B`, `C`.
- Next, visit neighbors of `B`: `D`, `E`.
- Finally, visit `C`.

## Algorithm

1. Insert source `u` into the queue.
2. Mark `u` as visited.
3. While the queue is not empty:
    - Remove a vertex `u` from the front of the queue.
    - Find all vertices `v` adjacent to `u`.
        - If `v` is not visited:
            - Print `v`.
            - Mark `v` as visited.
            - Insert `v` into the queue.
    - End if.
4. End while

> The BFS algorithm continues until the queue is empty, ensuring that all reachable vertices from the starting node have been visited.

## Example

``` mathematica
   1
  / \
 2   3
 |   |
 4   5

```

For BFS starting at `1`, the traversal is: `1 -> 2 -> 3 -> 4 -> 5`

``` mathematica
Initial queue: [1]
Visit 1, enqueue adjacent 2, 3 -> queue: [2, 3]
Visit 2, enqueue adjacent 4 -> queue: [3, 4]
Visit 3, enqueue adjacent 5 -> queue: [4, 5]
Visit 4 -> queue: [5]
Visit 5 -> done
```