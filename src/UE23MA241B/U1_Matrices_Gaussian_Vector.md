# Linear Algebra: Matrices

> *Linear algebra is a branch of mathematics that studies vectors, vector spaces, and linear transformations*

> [!Example] System of Equations
>
> $$
> 2x + 3y + 4z = 19
> $$
>
> $$
> 4x + 11y + 14z = 55
> $$
>
> $$
> 2x + 8y + 17z = 50
> $$

## Augmented Matrix

The augmented matrix for the above system of equations is:

$$
\begin{bmatrix}
2 & 3 & 4 & \vert & 19 \\
4 & 11 & 14 & \vert & 55 \\
2 & 8 & 17 & \vert & 50
\end{bmatrix}
$$

## Gauss Elimination

Using Gauss Elimination, we perform row operations to simplify the augmented matrix. Our goal is to transform it into an upper triangular form.

### Step 1: Fix $( R1 )$ and modify $( R2)$ and $( R3)$

$$
R_2 \to R_2 - 2R_1 
$$

$$
R_3 \to R_3 - R_1
$$

Performing these operations, the updated matrix becomes:

$$
\begin{bmatrix}
2 & 3 & 4 & \vert & 19 \\
0 & 5 & 6 & \vert & 17 \\
0 & 5 & 13 & \vert & 31
\end{bmatrix}
$$

### Step 2: Simplify further

Divide $( R2)$ by 5 to normalize the pivot:

$$
R_2 \to \frac{R_2}{5}
$$

$$
\begin{bmatrix}
2 & 3 & 4 & \vert & 19 \\
0 & 1 & \frac{6}{5} & \vert & \frac{17}{5} \\
0 & 5 & 13 & \vert & 31
\end{bmatrix}
$$

Next, eliminate the second element in $( R_3)$:

$$
R_3 \to R_3 - 5R_2
$$

$$
\begin{bmatrix}
2 & 3 & 4 & \vert & 19 \\
0 & 1 & \frac{6}{5} & \vert & \frac{17}{5} \\
0 & 0 & 7 & \vert & 14
\end{bmatrix}
$$

### Step 3: Normalize $( R_3 )$

$$
R_3 \to \frac{R_3}{7}
$$

$$
\begin{bmatrix}
2 & 3 & 4 & \vert & 19 \\
0 & 1 & \frac{6}{5} & \vert & \frac{17}{5} \\
0 & 0 & 1 & \vert & 2
\end{bmatrix}
$$

The system is now ready for back substitution to find the solution.

---

# Types of Solutions

1. **Consistent Systems**: at least one solution.
	   - **Unique Solution**: exactly one solution.
		   - $x + y = 2$
		   - $2x - y = 1$
	  - **Infinitely Many Solutions**: infinite number of solutions.
		  - $x + y + z = 3$
		  - $2x + 2y + 2z = 6$
2. **Inconsistent Systems**: no solution.
	- $x + y = 1$
	- $x + y = 3$

---

## Row Echelon Form (REF)

   - All rows consisting entirely of zeros are at the bottom.
   - The first nonzero element (pivot) in each row is to the right of the pivot in the row above it.
   - Below each pivot, all entries are zero.

$$
   \begin{bmatrix}

   1 & 1 & -2 & 3 & \vert & 4 \\

   0 & 1 & 7 & -7 & \vert & -5 \\

   0 & 0 & 0 & -2 & \vert & -5

   \end{bmatrix}

   
$$

## Reduced Row Echelon Form (RREF)

   - The matrix is in REF.
   - Each pivot is 1.
   - Each pivot is the only nonzero entry in its column.

$$
   \begin{bmatrix}

   1 & 0 & -9 & 0 & \vert & -3 \\

   0 & 1 & 7 & 0 & \vert & \frac{5}{2} \\

   0 & 0 & 0 & 1 & \vert & \frac{5}{2}

   \end{bmatrix}

   
$$

---

> [!Example]
> The given matrix $( A )$ represents an augmented matrix for a system of linear equations. It is written as:
>
> $$
> \begin{bmatrix}
> 
> 1 & 1 & -2 & 3 & \vert & 4 \\
> 
> 2 & 3 & 3 & -1 & \vert & 3 \\
> 
> 5 & 7 & 4 & -1 & \vert & 5
> 
> \end{bmatrix}
> $$

We aim to solve this system using Gaussian Elimination and also find its **Row Echelon Form (REF)** and **Reduced Row Echelon Form (RREF)**.

### Step 1: Fix $( R1 )$ (First row)

Keep  R1 as it is. Eliminate the first element in $( R2 )$ and $( R3 )$ by performing the following row operations:

$$
R_2 \to R_2 - 2R_1
$$

$$
R_3 \to R_3 - 5R_1
$$

Performing these operations gives:

$$
\begin{bmatrix}

1 & 1 & -2 & 3 & \vert & 4 \\

0 & 1 & 7 & -7 & \vert & -5 \\

0 & 2 & 14 & -16 & \vert & -15

\end{bmatrix}
$$

### Step 2: Normalize $( R2 )$ and Eliminate Below It

Next, eliminate the second element in $( R3 )$ using $( R2 )$:

$$
R_3 \to R_3 - 2R_2
$$

This gives:

$$
\begin{bmatrix}

1 & 1 & -2 & 3 & \vert & 4 \\

0 & 1 & 7 & -7 & \vert & -5 \\

0 & 0 & 0 & -2 & \vert & -5

\end{bmatrix}
$$

At this stage, the matrix is in **Row Echelon Form (REF)**:

$$
\begin{bmatrix}

1 & 1 & -2 & 3 & \vert & 4 \\

0 & 1 & 7 & -7 & \vert & -5 \\

0 & 0 & 0 & -2 & \vert & -5

\end{bmatrix}
$$

## Reduced Row Echelon Form (RREF)

Each pivot is $( 1 )$, and all elements above and below pivots are $(0)$ Proceed as follows:

### Step 1: Normalize $( R3 )$

Divide $( R3 )$ by $( -2 )$:

$$
R_3 \to \frac{R_3}{-2}
$$

$$
\begin{bmatrix}
1 & 1 & -2 & 3 & \vert & 4 \\
0 & 1 & 7 & -7 & \vert & -5 \\
0 & 0 & 0 & 1 & \vert & \frac{5}{2}
\end{bmatrix}
$$

## Step 2: Eliminate Above $( R3 )$'s Pivot

Using $(R3)$, eliminate the fourth element in $(R1)$ and $(R2)$:

$$
R_1 \to R_1 - 3R_3
$$

$$
R_2 \to R_2 + 7R_3
$$

Performing these gives:

$$
\begin{bmatrix}

1 & 1 & -2 & 0 & \vert & \frac{-1}{2} \\

0 & 1 & 7 & 0 & \vert & \frac{5}{2} \\

0 & 0 & 0 & 1 & \vert & \frac{5}{2}

\end{bmatrix}
$$

## Step 3: Eliminate Above $( R2 )$'s Pivot

Using $( R2 )$, eliminate the second element in $( R1 )$: $R_1 \to R_1 - R_2$

This gives the final **Reduced Row Echelon Form (RREF)**:

$$
\begin{bmatrix}

1 & 0 & -9 & 0 & \vert & -3 \\

0 & 1 & 7 & 0 & \vert & \frac{5}{2} \\

0 & 0 & 0 & 1 & \vert & \frac{5}{2}

\end{bmatrix}
$$

---

# Geometry of Linear Equations

> [!Example]
>
> - $x - y = -1$
> - $2x + y = 4$

- In the **Row Picture**, the solution is found by intersecting lines (or planes in higher dimensions).
- In the **Column Picture**, the solution is a combination of vectors that equals the result vector.

## Row Picture

The **Row Picture** represents each equation as a line in the plane. The solution to the system of equations is the point where these lines intersect. For the system:

1. $x - y = -1$
2. $2x + y = 4$

The intersection point is $(1, 2)$, which satisfies both equations.

## Column Picture

The **Column Picture** focuses on expressing the equations as combinations of column vectors. For a system like:

$$
\left[
\begin{pmatrix} 1 & -1 \\ 2 & 1 \end{pmatrix} 
\begin{pmatrix} x \\ y \end{pmatrix} 
=
\begin{pmatrix} -1 \\ 4 \end{pmatrix}
\right]
$$

- The first column vector is $v_1 = \begin{pmatrix} 1 \\ 2 \end{pmatrix}$, multiplied by $x$.
- The second column vector is $v_2 = \begin{pmatrix} -1 \\ 1 \end{pmatrix}$, multiplied by $y$.
- The right-hand side is the result vector $v_3 = \begin{pmatrix} -1 \\ 4 \end{pmatrix}$.

The equation can be rewritten as:

$$
x \begin{pmatrix} 1 \\ 2 \end{pmatrix} + y \begin{pmatrix} -1 \\ 1 \end{pmatrix} = \begin{pmatrix} -1 \\ 4 \end{pmatrix}
$$

Geometrically, this means the vector $\begin{pmatrix} -1 \\ 4 \end{pmatrix}$ can be expressed as a linear combination of $\begin{pmatrix} 1 \\ 2 \end{pmatrix}$ and $\begin{pmatrix} -1 \\ 1 \end{pmatrix}$. The coefficients of this combination are $x$ and $y$.

---

# Upper Triangular Form

Given the system of equations $( Ax = b )$, it can be transformed into the form $( Ux = c )$, where $U$ is an upper triangular matrix.

## Breakdown of Gaussian Elimination

Gaussian Elimination is a method used to solve a system of linear equations by transforming the matrix $A$ into an upper triangular matrix $U$. This is achieved through a series of **row operations**:

- **Curable (Row Operations)**: These are row operations that can transform the matrix into upper triangular form.
	- Swapping rows.
	- Multiplying a row by a non-zero scalar.
	- Adding a multiple of one row to another row.
- **Incurable (Singular)**: If at any point, the matrix becomes singular (a row becomes all zeros or the determinant becomes zero), the system is classified as **incurable**. This indicates that the system does not have a unique solution (it may have no solution or infinitely many solutions).

When the matrix is in upper triangular form, solving the system is straightforward using **back substitution**.

### Example

Consider the following system of equations represented by the matrix equation $( Ax = b )$

$$
A = \begin{pmatrix}
2 & 3 & 1 \\
4 & 9 & 2 \\
6 & 8 & 3
\end{pmatrix}, \quad
x = \begin{pmatrix} x_1 \\ x_2 \\ x_3 \end{pmatrix}, \quad
b = \begin{pmatrix} 5 \\ 8 \\ 7 \end{pmatrix}
$$

We can apply Gaussian elimination to transform $A$ into an upper triangular matrix $U$. Let's perform the row operations:

1. Eliminate the first column below the pivot (2 in the first row, first column):
   - Subtract $2$ times row 1 from row 2.
   - Subtract $3$ times row 1 from row 3.

After applying these row operations, we obtain the upper triangular matrix $U$:

$$
U = \begin{pmatrix}
2 & 3 & 1 \\
0 & 3 & 0 \\
0 & 0 & 2
\end{pmatrix}
$$

Now, the system is in the form $( Ux = c )$, where:

$$
c = \begin{pmatrix} 5 \\ 0 \\ 1 \end{pmatrix}
$$

The system is now easy to solve using **back substitution**:

1. From the third row: $2x_3 = 1 \Rightarrow x_3 = \frac{1}{2}$
2. From the second row: $3x_2 = 0 \Rightarrow x_2 = 0$
3. From the first row: $2x_1 + 3x_2 + x_3 = 5 \Rightarrow 2x_1 + 0 + \frac{1}{2} = 5 \Rightarrow x_1 = \frac{9}{4}$

> Thus, the solution is:

$$
x = \begin{pmatrix} \frac{9}{4} \\ 0 \\ \frac{1}{2} \end{pmatrix}
$$

### Singular Example (Incurable)

Consider the system:

$$
A = \begin{pmatrix}
1 & 2 & 3 \\
2 & 4 & 6 \\
1 & 2 & 3
\end{pmatrix}, \quad
b = \begin{pmatrix} 9 \\ 18 \\ 9 \end{pmatrix}
$$

Using Gaussian elimination, we would eventually encounter a row of zeros (i.e., a singular matrix), which indicates the system is either inconsistent or has infinitely many solutions. Specifically, after performing row operations:

$$
U = \begin{pmatrix}
1 & 2 & 3 \\
0 & 0 & 0 \\
0 & 0 & 0
\end{pmatrix}
$$

The system has no unique solution, and we can conclude that it is **incurable** (the matrix is singular).

---

# Matrix Notation and Multiplication

## Elementary Matrices and Elimination

> An **elementary matrix** represents a single row operation applied to the identity matrix $I$. Performing a row operation on a matrix $A$ is equivalent to multiplying $A$ by an elementary matrix $E_{i,j}$ from the left.

For example:

- $I_{i,j} \to E_{i,j}$: This represents an elementary matrix that performs a specific row operation (e.g., row addition, scaling, or swapping).

> The elimination process transforms a matrix $A$ into an upper triangular matrix $U$. This can be expressed as:

$$
E_{32} E_{31} E_{21} A = U
$$

where $E_{ij}$ are the elementary matrices that perform the necessary row operations to reduce $A$ to upper triangular form $U$.

---

# Cost of Elimination

1. **Right-Hand Side (RHS):** The time required to perform operations for the elimination process. For an $n \times n$ matrix, the cost is dominated by the forward elimination step, which involves approximately: $n^2$
2.    **Left-Hand Side (LHS):** Refers to the result of applying the sequence of elementary matrices to the matrix $A$. Each multiplication $E_{ij} A$ contributes to the overall cost.

$$
\frac{n^3-n}{3}
$$

---

# Triangular Factors and Row Exchanges

The matrix $A$ can be factored into a **lower triangular matrix** $L$ and an **upper triangular matrix** $U$ through Gaussian elimination:

$$
A = LU
$$

> - $L$ is a lower triangular matrix with ones on the diagonal, representing the multipliers used during the elimination process.
> - $U$ is an upper triangular matrix resulting from the elimination.

---

# Permutation Matrix

A permutation matrix is a square matrix obtained by permuting the rows of the identity matrix. Here's an example of a permutation matrix $( P )$ for $( 3 \times 3 )$:

$P$ is a permutation matrix if the rows are in a different order. Product can be permutated, Inverse can be permutated.

$$
I = 
\begin{pmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{pmatrix}
$$

The matrix $P$ has been formed by swapping the first and second rows of the identity matrix. This is an example of a permutation matrix, where the rows of the identity matrix are rearranged in a specific order.

## Properties of a Permutation Matrix

1. **Orthogonality**: A permutation matrix is always orthogonal, meaning that its inverse is equal to its transpose:

   $$
   P^{-1} = P^T

$$

2. **Product of Permutation Matrices**: When multiplying permutation matrices, the result is another permutation matrix. The product of two permutation matrices corresponds to applying one permutation after another.

3. **Determinant**: The determinant of a permutation matrix is either $+1$ or $-1$, depending on whether the number of row swaps is even or odd. Specifically, the determinant is $+1$ if the number of swaps is even, and $-1$ if the number of swaps is odd.

4. **Inverse**: The inverse of a permutation matrix is another permutation matrix, which is simply the matrix that "reverses" the row swaps performed by the original matrix. $P^{-1}$ is the same as $P$, as swapping the rows of $P$ back to their original order results in the same matrix.

