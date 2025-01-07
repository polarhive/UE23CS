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

## Step 1: Fix $( R1 )$ (First row)

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

---

## Step 2: Normalize $( R2 )$ and Eliminate Below It

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

---

# Reduced Row Echelon Form (RREF)

In RREF, each pivot is $( 1 )$, and all elements above and below pivots are $(0)$ Proceed as follows:

## Step 1: Normalize $( R3 )$

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

Using ( R3 ), eliminate the fourth element in ( R1 ) and ( R2 ):

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
