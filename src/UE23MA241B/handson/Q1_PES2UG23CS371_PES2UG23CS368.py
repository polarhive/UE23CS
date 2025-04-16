"""
Customer Behavior Analysis for Retail Optimization

Background:
A retail company has collected data from 10,000 customers, tracking 15 behavioral 
metrics (e.g., monthly spending, product returns, session duration, coupon usage). The team wants to 
identify patterns to group customers into segments for targeted marketing. However, visualizing and 
analyzing 15 dimensions is impractical. They need a method to reduce the data to its most "meaningful" 
components while minimizing information loss.

Problem Statement:
Your task is to design a linear algebra pipeline to:

1. Preprocess the data to ensure numerical stability.
2. Identify the key orthogonal directions in which the data varies the most.
3. Project the data onto a low-dimensional subspace (2-3 dimensions) for visualization.
4. Quantify the error introduced by this approximation.
5. Explain why the chosen subspace preserves the geometric structure of the original data.

Deliverables:

1. A mathematical justification for the number of dimensions retained.
2. An analysis of how the original feature space relates to the reduced subspace.
3. A reconstruction of the original data from the reduced subspace and its error.

Constraints:

1. Use only fundamental linear algebra operations (no prebuilt ML libraries like sklearn).
2. Address edge cases (e.g., linearly dependent features).


------------------------------------------------
TEST CASE 1

INPUT:
    5 0
    5 0
    5 0

OUTPUT:
    Centered data:
    [[0. 0.]
    [0. 0.]
    [0. 0.]]

    Top directions:
    No directions (all features are constant)

    Reduced data:
    No reduced data (all features are constant)

    Reconstructed data:
    [0. 0.]

    Reconstruction error: 8.66

------------------------------------------------
TEST CASE 2

INPUT:
    2 4 6
    1 2 3 
    3 6 9

OUTPUT:
    Centered data:
    [[ 0.  0.  0.]
    [-1. -2. -3.]
    [ 1.  2.  3.]]

    Top directions:
    -0.27 -0.53 -0.80

    Reduced data:
    0.00
    3.74
    -3.74

    Reconstructed data:
    [[2. 4. 6.]
    [1. 2. 3.]
    [3. 6. 9.]]

    Reconstruction error: 0.00
"""


import numpy as np
import sys

class DimensionalityReducer:
    def __init__(self):
        self.mean = None
        self.basis = None  # Principal components (rows)
        self.variance_explained = None

    def preprocess(self, X):
        self.mean = np.mean(X, axis=0)
        return X - self.mean

    def compute_key_directions(self, X_centered):
        if np.allclose(X_centered, 0):
            self.basis = None
            self.variance_explained = np.zeros(X_centered.shape[1])
            return
        
        n = X_centered.shape[0]
        cov_matrix = (X_centered.T @ X_centered) / (n - 1)
        eigenvalues, eigenvectors = np.linalg.eigh(cov_matrix)
        idx = eigenvalues.argsort()[::-1]
        eigenvalues = eigenvalues[idx]
        eigenvectors = eigenvectors[:, idx]
        if eigenvectors[0, 0] > 0:
            eigenvectors *= -1
        self.basis = eigenvectors.T
        total_variance = np.sum(eigenvalues)
        self.variance_explained = eigenvalues / total_variance if total_variance > 0 else np.zeros_like(eigenvalues)

    def reduce_dimensions(self, X_centered, k):
        if self.basis is None or k == 0:
            return np.zeros((X_centered.shape[0], 0))
        return X_centered @ self.basis[:k].T

    def reconstruct(self, X_reduced):
        if X_reduced.size == 0:
            return np.zeros_like(self.mean)
        return X_reduced @ self.basis[:X_reduced.shape[1]] + self.mean

    def evaluate_error(self, X_original, X_reconstructed):
        if X_reconstructed.ndim == 1:
            X_reconstructed = np.tile(X_reconstructed, (X_original.shape[0], 1))
        return np.linalg.norm(X_original - X_reconstructed)

def main():
    # Read input matrix from stdin
    A = []
    while True:
        try:
            row = input().strip()
            if row:
                A.append(list(map(float, row.split())))
            else:
                break 
        except EOFError:
            break
    A = np.array(A)
    
    reducer = DimensionalityReducer()
    
    # Step 1: Preprocess (center the data)
    try:
        X_centered = reducer.preprocess(A)
    except Exception as e:
        print("Error during preprocessing:", e)
        return
    
    print("Centered data:")
    print(X_centered)
    
    # Step 2: Compute key directions (SVD)
    try:
        reducer.compute_key_directions(X_centered)
    except Exception as e:
        print("Error during key directions computation:", e)
        return
    
    # Determine k for 95% variance
    cumulative_variance = np.cumsum(reducer.variance_explained)
    k = np.argmax(cumulative_variance >= 0.95) + 1
    if k == 0:  # Handle case where no component meets the threshold
        k = len(reducer.variance_explained)
    
    # Handle case when all variances are zero (e.g., constant features)
    if np.allclose(X_centered, 0):
        k = 0
    
    # Step 3: Reduce dimensions
    try:
        X_reduced = reducer.reduce_dimensions(X_centered, k)
    except Exception as e:
        print("Error during dimensionality reduction:", e)
        return
    
    print("\nTop directions:")
    if reducer.basis is None:
        print("No directions (all features are constant)")
    else:
        for direction in reducer.basis[:k]:
            print(" ".join(f"{x:.2f}" for x in direction))
    
    print("\nReduced data:")
    if X_reduced.size == 0:
        print("No reduced data (all features are constant)")
    else:
        for i in range(X_reduced.shape[0]):
            print(f"{X_reduced[i, 0]:.2f}")

    try:
        X_reconstructed = reducer.reconstruct(X_reduced)
    except Exception as e:
        print("Error during reconstruction:", e)
        return
    
    print("\nReconstructed data:")
    print(X_reconstructed)
    
    # Step 5: Evaluate reconstruction error
    try:
        error = reducer.evaluate_error(A, X_reconstructed)
    except Exception as e:
        print("Error during error evaluation:", e)
        return
    
    print(f"\nReconstruction error: {error:.2f}")

if __name__ == "__main__":
    main()

