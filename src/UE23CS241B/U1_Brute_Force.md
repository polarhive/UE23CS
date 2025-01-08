# Algorithms. Brute. Force

> Set of sequence of unambiguous instructions for solving a problem.

## Characteristics

1. Zero or more inputs: "hello world" program zero inputs
2. Definiteness: Each step should be precise and unambiguous
3. Output: At least one output
4. Effectiveness: Each step should be precise and feasible
5. Finiteness: Terminates after finite number of steps

> We write algorithms in pseudo-code: A mix of natural and programming language

```c
# Example: swap two numbers (a, b)
Algorithm swap(a,b)
Begin:
	temp = a;
	a = b;
	b = temp;
End:
```

> We can use `{}` in the place of `Begin:` and `End:`
> The = token may also be written as := and <-

---

# Fundamentals of Problem Solving

> This is the framework for analyzing algorithms to solve new problems.

1. Understand the Problem
	1.  Clearly define:
		1.  input
		2. expected output
	2. Consider the constraints and assumptions
	3. Ensure the problem is well defined and unambiguous
2. Decide on the Computational Means
	1. Choose the appropriate model: PRAM, RAM, < TM >
	2. Evaluate the hardware and software constraints
3. Exact v/s Approximate problem solving
	1. Decide if the exact solution is feasible, or necessary
	2. Computational cost
4. Algorithmic Design Techniques
	1. Brute Force
	2. Divide and Conquer
	3. Decrease and Conquer
	4. Transform and Conquer
	5. Dynamic Programming
	6. Greedy Technique
	7. Branch and Bound
	8. Backtracking
5.  Designing an Algorithm
	1. Step by step: pseudocode
	2. Algorithm follows all the characteristics
	3. Break into subroutines
6. Proving Algorithm Correctness: Works for all valid inputs
7. Analyze the algorithm
	1. Timer Complexity
	2. Space Complexity
8. Test and Debug: Test for all the cases
9. Documenting the algorithm
10. Improving and Refinement

---

# Ways to Analyse

1. Time Efficiency/Complexity: how long to run as `input` size grows
2. Space Efficiency/Complexity: how much memory consumed as `input` size grows
3. Network Efficiency/Complexity
4. Hardware (Power) Efficiency/Complexity

## Analyse Time and Space for

> [!Example]
>
> Time: measure every statement as 1 unit of time
> Space: Frequency count of variables when algorithms are small
>
> ```c
> Algorithm swap(a,b)
> Begin:
> 	temp <- a; (1t)
> 	a <- b;    (1t)
> 	b <- temp; (1t)
> End:
> ```

- T(n) = 1+1+1 = 3 = *constant*
- S(n) = 1+1+1 = 3 = constant

> We can represent this in the order of $O(1)$

---

> [!Example]
> Notice the difference when we have a loop:
> ```c
> Algorithm sum(A,n)
> Begin:
> 	s=0;
> 	for (i=0, i<n, i++)  // checks upto 'n+1' times, i++ 'n' times
> 		s = s + A[i]   // repeats upto n times
> 	return s;
> End:
> ```

1. The dominant term is checking the condition (n+1). Consider only this
2. (2n+2) -> n+1; the +2 becomes insignificant as n increases

> So: T(n+1) -> O(n)

---
