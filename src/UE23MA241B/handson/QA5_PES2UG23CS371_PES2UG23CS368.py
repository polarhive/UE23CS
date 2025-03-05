"""
1. Economic Forecasting Using LU Decomposition and Rank-Nullity
Problem Statement
An economic model predicts market trends using a system of equations represented by matrix A. The model uses LU decomposition to solve the system Ax=b and determine the rank and nullity of A.
In this problem, the input matrix is guaranteed to be non-singular, ensuring that a unique solution exists.
You need to:
Solve for x using LU decomposition.
Compute the rank and nullity of A.
Ensure that the system has a unique solution (i.e., the nullity is always 0).
Concepts Used:
LU Decomposition
Rank-Nullity Theorem
Solving Linear Systems

Input Format
The first line contains two integers m and n, representing the number of rows and columns in matrix A.
The next m lines each contain n space-separated numbers, representing the elements of matrix A.
The last line contains m space-separated numbers, representing the elements of vector b.
Note: The input matrix is guaranteed to be non-singular, meaning m=n and rank(A)=n


Output Format
First, print "x =" followed by the solution vector x, formatted to four decimal places.
Then, print "Rank =" followed by the rank of A.
Finally, print "Nullity =" followed by the nullity of A.

Constraints
2≤n≤100(A is a square matrix)
−1000≤A[i][j],b[i]≤1000
A is always non-singular (rank(A)=n) ensuring a unique solution exists.

Sample Test Case 1
Input
2 2
3 1
4 2
9 10
Expected Output
x =
4.0000 -3.0000
Rank = 2
Nullity = 0

Explanation
The system of equations is: 3x+1y=9, 4x+2y=10
The matrix is not singular, so we solve for x using LU decomposition.
The rank of A is 2, and the nullity is 0 (indicating a unique solution).

Sample Test Case 2
Input
3 3
2 -1 3
1 3 2
4 5 -2
5 6 7

Expected Output

x =
1.2540 0.8413 1.1111
Rank = 3
Nullity = 0

Explanation
The system of equations is a full-rank 3×3 system.
The matrix is not singular, so a unique solution exists.

"""

import numpy as np
from scipy.linalg import lu_factor, lu_solve

def economic_forecast(A, b):
    """
    Solve an economic forecasting system using LU decomposition.

    Args:
        A (numpy.ndarray): Coefficient matrix of size n x n.
        b (numpy.ndarray): Column vector of size n.

    Returns:
        tuple: (x, rank, nullity) where:
               x is the solution vector.
               rank is the rank of A.
               nullity is the nullity of A.
    """
    lu, piv = lu_factor(A)
    x = lu_solve((lu, piv), b)
    rank = np.linalg.matrix_rank(A)
    nullity = A.shape[1] - rank
    return x, rank, nullity

# Boilerplate code to handle input and output
def main():
    
    A, b = [], []
    rows, cols = map(int, input().split())  # Read dimensions of A

    for _ in range(rows):
        A.append(list(map(float, input().split())))

    b = list(map(float, input().split()))  # Read b values

    A = np.array(A)
    b = np.array(b)

    # Perform Economic Forecast Analysis
    result = economic_forecast(A, b)

    # Print results
    x, rank, nullity = result

    print("x =")
    print(" ".join(f"{xi:.4f}" for xi in x))

    print("\nRank =", rank)
    print("Nullity =", nullity)

if __name__ == "__main__":
    main()
