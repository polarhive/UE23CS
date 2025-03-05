"""
2. Solving a Linear System Using Optimized Gaussian Elimination
Problem Statement
Given a system of linear equations represented as Ax=b, solve for x using Gaussian Elimination.
Tasks:
Convert the augmented matrix [A | b] into row echelon form using Gaussian elimination.
Use back-substitution to solve for x.
Print the row echelon form of [A | b] and the solution vector x.
 Note: The system always has a unique solution (i.e., A is full-rank and non-singular).

Concepts Used
Gaussian Elimination
Row Echelon Form (REF)
Back-Substitution

Input Format
The first line contains one integer n, representing the size of the square matrix A (i.e., n×n).
The next n lines contain n+1 space-separated numbers, representing the augmented matrix [A | b] where:
The first n values in each row correspond to matrix A.
The last value in each row corresponds to vector b.
 Note: The system always has a unique solution (rank(A)=n).

Output Format
First, print "U =" followed by the row echelon form of [A | b].
Then, print "x =" followed by the solution vector x.

Constraints
2≤n≤1002(A is always square)
−1000≤A[i][j],b[i]≤1000
A is always full-rank, so a unique solution exists.

Sample Test Case 1 (Basic 2×2 System)
Input
2
2 -1 1
1 3 2

Expected Output
U =
1.0 -0.5 
0.0 1.0 

x =
0.7 0.4
Explanation
Gaussian Elimination transforms [A | b] into row echelon form.
Back-substitution yields the solution x=[1,2].

Sample Test Case 2 (3×3 System with Unique Solution)
Input
3
1 2 3 6
4 5 6 15
7 8 10 25

Expected Output
U =
1.0 2.0 3.0
-0.0 1.0 2.0
0.0 0.0 1.0

x =
1.0 1.0 1.0

Explanation
The row echelon form maintains an upper triangular structure.
Back-substitution solves = 3x3​=3, 2x2​=2, 1x1​=1.


Python Code
"""
import numpy as np

def gaussian_elimination(A, b):
    """
    Perform Gaussian elimination to solve Ax = b.

    Args:
        A (numpy.ndarray): Coefficient matrix of size n x n.
        b (numpy.ndarray): Column vector of size n.

    Returns:
        tuple: (U, x) where:
               U is the row echelon form of [A|b].
               x is the solution vector.
    """
    n = len(A)
    Ab = np.hstack((A, b.reshape(-1, 1)))

    for i in range(n):
        pivot = Ab[i, i]
        Ab[i] = Ab[i] / pivot

        for j in range(i + 1, n):
            factor = Ab[j, i]
            Ab[j] -= factor * Ab[i]

    U = Ab[:, :-1]
    b_new = Ab[:, -1]

    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b_new[i] - np.dot(U[i, i + 1 :], x[i + 1 :])) / U[i, i]

    return U, x

# Boilerplate code to handle input and output
def main():
    # Read input
    n = int(input().strip())  # Read matrix size
    A, b = [], []

    for _ in range(n):
        row = list(map(float, input().split()))
        A.append(row[:-1])  # First n values go to A
        b.append(row[-1])  # Last value goes to b

    A = np.array(A)
    b = np.array(b)

    # Perform Gaussian elimination
    U, x = gaussian_elimination(A, b)

    # Print results
    print("U =")
    for row in U:
        print(" ".join(f"{x:.1f}" for x in row))

    print("\nx =")
    print(" ".join(f"{xi:.1f}" for xi in x))

if __name__ == "__main__":
    main()


