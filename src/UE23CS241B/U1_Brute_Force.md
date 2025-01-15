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

# Small o and Small ω

> These notations describe stricter bounds compared to Big O and Omega.

## Small $(o)$

> $(t_n = o(g_n))$ means that $(t_n)$ grows asymptotically slower than $(g_n)$:

$[ \lim_{n \to \infty} \frac{t_n}{g_n} = 0 ]$

## Small $(\omega)$

> $(t_n = \omega(g_n))$ means that $(t_n)$ grows asymptotically faster than $(g_n)$:

$[ \lim_{n \to \infty} \frac{t_n}{g_n} = \infty ]$

---

| Notation     | Description        | Usage                           |
| ------------ | ------------------ | ------------------------------- |
| $(O)$        | Upper bound        | Guarantees worst-case runtime   |
| $( \Omega )$ | Lower bound        | Guarantees minimum runtime      |
| $( \Theta )$ | Tight bound        | Represents average-case runtime |
| $( o )$      | Strict upper bound | Stricter than Big O             |
| $( \omega )$ | Strict lower bound | Stricter than Omega             |

---

# Analysis of Non-Recursive Algorithms

> **Q:** Find the maximum element of an array of size 'n'

```c
Algorithm find_max(A, n)
Begin:
    max_element <- A[0]; 
    for i <- 1 to n-1 do:   // (n-1 times)
        if A[i] > max_element then:
            max_element <- A[i];  // (1t) larger element is found
    return max_element;
End:
```

1. **Input size**: n (size of the array).
2. **Basic Operation**: Comparison (comparing the current element with the maximum element).
3. **C(n)**: The algorithm performs one comparison for each element
	1. $((u-l) +1)$
	2. $((n-1 - 1) + 1)$
	3. $(n-1)$
4. $C(n)$=$O(n)$

> [!Tip] Standard Formula
> $C(n) = \sum_{u}^{l} 1 = (u-l-1)$

> **Q:** Matrix multiplication A x B

```c
// Output Matric C = AxB
Algorithm multi(A(0..n-1, 0..n-1),B(0..n-1, 0..n-1))) {
	for (i=0; n-1) {
		for (j=0; n-1) {
			c[i, j]=(0,0)
			for (k=0; n-1) {
				c[i,j]=c[i,j] + A[i,k] * B[k,j]
			}
		}
	}
}
```

1. **Input size**: `n x n`
2. **Basic op**: Multiplication
3. $C(n) = \sum_{i=0}^{n-1} \sum_{j=0}^{n-1} \sum_{k=0}^{n-1} 1 = (n^3)$

---

# Analysis of Recursive Algorithms

> [!Question] What is the equation that relates to the algorithm??
> **Recurrence Relation**: An equation that recursively defines a sequence.
> Then, we solve the recurrence relation.

1. **Input size**: n (size of the params).
2. **Basic Operation**: Same as before.
3. **C(n)**:
	1. **Substitution**: Mathematical Induction, Backward Substitution
	2. **Recurrence Tree**
	3. **Master's**

> [!Example] Example 1
>
> ```c
> void test(int n) {
> 	if (n>0) { 
> 		printf("%d", n);
> 		test(n-1);
> 	}
> }
> ```
>
> Recurrence Tree
> ```mathematica
>            test(3)
>           /      \
>          3      test(2)
>                 /      \
>                2      test(1)
>                       /      \
>                      1      test(0)
>  ```
>  - $T(n)=(T(n-2)+1)$
> - $T(n-1)=(T(n-1-1)+1)+1 = T(n-2)+2$
> - $T(n-2)+2)=(T(n-2-1)+2)+T(n-3)+3$
> - $T(n-n)+n$
> 	- Assume $n-k=0$, $n=k$
> - $T(0)+n$
> - $O(n)$

> [!Example] Example 2
> - Given: $T(n)=T(n-1)+C$
> - Basecase: $T(1)=d$ <- stop the recursion
>
>   Substitution Method:
>   - $T(n)=T(n-1)+c$
>   - $T(n)=(T(n-2)+c) + c = T(n) = T(n-2)+2c$
>   - $T(n)=T(n-3)+3c$
> 	   so on..
>   - $T(n)=T(n-k) + kc$
> $n-k=1$: <- stops at base condition
>
> $T(n)=T(n-n+1)+(n-1)c$
> $T(n)=d+(n-1)c$ <- **stops**

> [!Example] Example 3
>
> ```c
> int fact(int n) {
> 	if (n=0) return 1 // base condition <- T(n) = 1
> 	else return (n * fact(n-1)) // basic op <-T(n) = 1
> 						// ^ for T(n-1) <- T(n-1)
> }
> ```
> - Given: $T(n)=1+1+T(n-1)+C$
> - Basecase: $T(1)=d$ <- stop the recursion
>
>   Substitution Method:
>   - $T(n)=T(n-1)+c$
>   - $T(n)=(T(n-2)+c) + c = T(n) = T(n-2)+2c$
>   - $T(n)=T(n-3)+3c$
> 	   so on..
>   - $T(n)=T(n-k) + kc$
> $n-k=1$: <- stops at base condition
> Linear: $O(n)$