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

---

# Generating Subsets

1. `1 to n-1`
2. Adding element `n` to each of them
3. `2^n-1`

---

# Russian Peasant Problem

No addition / Multi

---

# Josephus Problem

> [!Warning]
> Instead of surrendering, they decided to kill them-selves.

Every alternate person dies.

> [!Example]
> When `n=13`
> $J(n)=2L+1$
> $2^m$: largest power of $2 <= n$
> $L=n-2^m$

> [!Example] $n=8$
> Pos of survivor = $1$

---

# Divide and Conquer

Take a large problem and solve the sub-problems.

>  Sub problems

## Merge Sort

---

# Large Matrix Multiplication

> Strassen Multiplcation

- Let the two numbers being multiplied be a and b
- a and b are n–digit integers, where n is a positive even number
- Let the first half of a’s digits be $a1$ and second half be $a0$
- Similarly, let the first half of b’s digits be $b1$ and second half be $b0$
- In these notations, $a = a1*a0$ implies $a = a1*10n/2 + a0$ and $b = b1*b0$ implies $b = b1*10n/2 + b0$

