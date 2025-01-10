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

# Time Complexities with Sample Values

| Symbol     | Name          | n = 1 | n = 10 | n = 100  | n = 1000   | n = 10000     |
| ---------- | ------------- | ----- | ------ | -------- | ---------- | ------------- |
| O(1)       | Constant Time | 1     | 1      | 1        | 1          | 1             |
| O(log n)   | Logarithmic   | 0     | 2      | 6        | 9          | 13            |
| O(sqrt(n)) | Sublinear     | 1     | 3      | 10       | 31         | 100           |
| O(n)       | Linear        | 1     | 10     | 100      | 1000       | 10000         |
| O(n logn)  | Linearithmic  | 0     | 33     | 664      | 9965       | 132877        |
| O(n^2)     | Quadratic     | 1     | 100    | 10000    | 1000000    | 100000000     |
| O(n^3)     | Cubic         | 1     | 1000   | 1000000  | 1000000000 | 1000000000000 |
| O(2^n)     | Exponential   | 2     | 1024   | ~1.27e30 | ~1.07e301  | Overflow      |
| O(n!)      | Factorial     | 1     | 3.63e6 | Overflow | Overflow   | Overflow      |

![[Pasted image 20250110154114.png]]

---

# Algorithmic Analysis Framework

## 1. Space Complexity

> S(p) = C + SP(I)

- P is the problem
- C is the constants
- I talks about instance characteristics

## 2. Time Complexity

Big O, Step Count Method

## 3. Measuring Input Size

Efficiency of the algorithm -> func

- t(n) = n
- S(n) parameters a function takes

## 4. Measuring Run Time

- Identify the basic operation
- Understand the concept of basic operation
- Compute total time taken for the operation

> T(n) is Cop x C(n)

## 5. Compute the Order of Growth

Measure the performance of the algorithm in relation with input size, we must analyze for all cases of `n`

---

# Asymptotic Notation

> Asymptotic notations describe the growth of functions, often used in analyzing the time and space complexity of algorithms.

## Upper Bound

Big O provides the upper bound of an algorithm's running time, guaranteeing it won't exceed a certain rate of growth.

> [!Info]
> The function $( t(n) = O(g(n)) )$ if and only if there exist constants $( C > 0 )$ and $( n_0 \geq 0 )$ such that: $[ t(n) \leq C \cdot g(n), \quad \forall n \geq n_0 ]$

> Example: $( t(n) = 3n + 2 )$ is $( O(n) )$, as $( t(n) \leq 4n )$ for $( n \geq 1 )$ (with $( C = 4, n_0 = 1 )$).

---

## Lower Bound

Omega provides the lower bound of an algorithm's running time, guaranteeing it takes at least a certain amount of time.

> [!Info]
>
> The function $( t(n) = \Omega(g(n)) )$ if and only if there exist constants $( C > 0 )$ and $( n_0 \geq 0 )$ such that: $[ t(n) \geq C \cdot g(n), \quad \forall n \geq n_0 ]$

> Example: $( t(n) = 3n + 2 )$ is $( \Omega(n) )$, as $( t(n) \geq 3n )$ for $( n \geq 1 )$ (with $( C = 3, n_0 = 1 )$)

---

## Tight Bound

Theta provides both the upper and lower bounds, tightly bounding the growth of an algorithm's running time.

> [!Info]
> The function $( t(n) = \Theta(g(n)) )$ if and only if there exist constants $( C_1, C_2 > 0 )$ and $( n_0 \geq 0 )$ such that: $[ C_1 \cdot g(n) \leq t(n) \leq C_2 \cdot g(n), \quad \forall n \geq n_0 ]$

> Example: $( t(n) = 3n + 2 )$ is $( \Theta(n) )$, as $( 3n \leq t(n) \leq 4n )$ for $( n \geq 1 )$.

---

## Small o and Small ω

> These notations describe stricter bounds compared to Big O and Omega.

| Notation     | Description        | Usage                           |
| ------------ | ------------------ | ------------------------------- |
| $(O)$        | Upper bound        | Guarantees worst-case runtime   |
| $( \Omega )$ | Lower bound        | Guarantees minimum runtime      |
| $( \Theta )$ | Tight bound        | Represents average-case runtime |
| $( o )$      | Strict upper bound | Stricter than Big O             |
| $( \omega )$ | Strict lower bound | Stricter than Omega             |

---