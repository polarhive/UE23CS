# Decrease and Conquer

- **Permutation**: Arrangement of elements in a specific order (order matters).
- **Combination**: Selection of elements in a given set (order doesn't matter).
- **Subset**: `{}, {v,c,s}, {v,s}, {s,c}, {v,c}, {v}, {s}, {c}`

## Generate Permutation

Start permuting by a smaller subset, and then gradually expanding it. It should also satisfy the minimal change requirement.

## Johnson Trotter

1. Each number has a direction (could be left/right)
2. Find the largest mobile integer
3. Swap the largest mobile integer with its adjacent element in its direction
4. Reverse the direction of all the numbers larger than the largest swapped number
5. Continue until all permutations are generated

> Mobile component: a number pointing to a smaller digit

``` 
3<-4
1<-2
``` 

## Lexicographic Order

1. Look for pairs which appear in increasing order
2. Choose the pair which is farthest away from the LHS
3. Find the next larger element to swap
4. Swap the number with the RHS, which is larger than 5 and close to 5
5. Sort the elements in ascending order

```
325|74
32754
32745
```

```
1243
12|43
1342
1324
```

```
632541
25
63|2541
```