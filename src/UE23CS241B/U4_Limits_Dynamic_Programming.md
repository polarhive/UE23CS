# Dynamic Programming

- Re-use the solution. `F(0)`, `F(1)`, store the values in a table
- Binomial Co-efficient: Recurrence relation

## How to Fill the table?

```c
C(n,k) = {
	1 if k==0 || n==k;
	C(n-1, k)+C(n-1, k-1); for n>k>0
}
```

---
