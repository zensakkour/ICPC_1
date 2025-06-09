# **Exercise I: True/False Questions**

1. **MDS is a linear dimensionality reduction method preserving distances in the original and lower-dimensional spaces.**  
   **Answer**: False  
   **Justification**: MDS (Multidimensional Scaling) can be used for non-linear relationships, and the preservation of distances depends on the method (e.g., classical MDS assumes linear relationships).

2. **Clustering can usually be evaluated by computing errors with respect to ground truth labels.**  
   **Answer**: False  
   **Justification**: Clustering is unsupervised, and evaluation typically uses internal metrics (e.g., silhouette score) or external metrics when ground truth labels are available.

3. **In kernel SVMs, the non-linear mapping \( \Phi(x): \mathbb{R}^q \to \mathbb{R}^p \) can be of an infinite dimension and does not have to be computed explicitly.**  
   **Answer**: True  
   **Justification**: Kernel trick computes inner products in feature space directly, avoiding explicit computation of \( \Phi(x) \).

4. **Spectral clustering does not work for non-convex clusters.**  
   **Answer**: False  
   **Justification**: Spectral clustering is effective for non-convex clusters, relying on the eigenstructure of similarity graphs.

5. **The Empirical Risk on the training set converges to the True Risk and is sufficient to estimate the generalization error.**  
   **Answer**: False  
   **Justification**: Empirical risk minimizes training error but may not account for generalization error due to overfitting.

6. **The closed-form solution of least squares regression is always better than gradient descent methods.**  
   **Answer**: False  
   **Justification**: Gradient descent can handle large datasets and non-invertible matrices, unlike the closed-form solution.

7. **A 4-NN classifier has a lower variance than a 7-NN classifier.**  
   **Answer**: False  
   **Justification**: Increasing \( k \) reduces variance, as predictions are based on larger neighborhoods.

8. **The eigenvectors of \( A A^T \) and \( A^T A \) are not the same.**  
   **Answer**: True  
   **Justification**: The eigenvectors of \( A A^T \) correspond to the left singular vectors of \( A \), while the eigenvectors of \( A^T A \) correspond to the right singular vectors. These are related but not identical unless \( A \) is square.

9. **In Adaboost: the error associated with each hypothesis is computed as the ratio of misclassified examples to the total number of examples.**  
   **Answer**: True  
   **Justification**: Adaboost updates weights based on the proportion of misclassified instances.

10. **The maximum likelihood estimator considers model parameters as random variables following a specific distribution.**  
   **Answer**: False  
   **Justification**: MLE treats parameters as fixed values that maximize the likelihood function, unlike Bayesian approaches.

---

# **Exercise II: MSE as a Function of Noise, Bias, and Variance**

The Mean Squared Error (MSE) is defined as:  
\[
MSE(f̂(x)) = \mathbb{E}[(y - f̂(x))^2].
\]

1. Expand \( y = f(x) + \epsilon \):  
   \[
   MSE(f̂(x)) = \mathbb{E}[(f(x) + \epsilon - f̂(x))^2].
   \]

2. Separate terms:  
   \[
   MSE(f̂(x)) = \mathbb{E}[(f(x) - f̂(x))^2] + \mathbb{E}[\epsilon^2] + 2\mathbb{E}[(f(x) - f̂(x))\epsilon].
   \]

3. Noise \( \epsilon \) has zero mean and is independent of \( f(x) \) and \( f̂(x) \), so \( \mathbb{E}[(f(x) - f̂(x))\epsilon] = 0 \):  
   \[
   MSE(f̂(x)) = \mathbb{E}[(f(x) - f̂(x))^2] + \sigma^2.
   \]

4. Decompose \( \mathbb{E}[(f(x) - f̂(x))^2] \):  
   \[
   \mathbb{E}[(f(x) - f̂(x))^2] = \text{Bias}^2(f̂(x)) + \text{Variance}(f̂(x)).
   \]

5. Final equation:  
   \[
   MSE(f̂(x)) = \text{Bias}^2(f̂(x)) + \text{Variance}(f̂(x)) + \sigma^2.
   \]


# **Exercise III: Linear and Logistic Regression**

### (a) Derive the normal equations for the minimization of \( J(w) \)
The cost function is defined as:  
\[
J(w) = \|Xw - y\|_2^2 + \|\Gamma w\|_2^2.
\]

Expanding each term:  
\[
J(w) = (Xw - y)^T(Xw - y) + w^T\Gamma^T\Gamma w.
\]

Take the gradient of \( J(w) \) with respect to \( w \):  
\[
\nabla_w J(w) = 2X^T(Xw - y) + 2\Gamma^T\Gamma w.
\]

Set the gradient to zero to find the optimal \( w^* \):  
\[
X^TXw - X^Ty + \Gamma^T\Gamma w = 0.
\]

Reorganizing:  
\[
(X^TX + \Gamma^T\Gamma)w = X^Ty.
\]

Thus, the normal equation is:  
\[
w^* = (X^TX + \Gamma^T\Gamma)^{-1}X^Ty.
\]

---

# **Exercise III (b): Necessary and Sufficient Condition**

To ensure the cost function 
\[
J(w) = \|Xw - y\|_2^2 + \|\Gamma w\|_2^2
\]
has a unique minimum, the matrix \( (X^T X + \Gamma^T \Gamma) \) must be invertible. This requires that \( (X^T X + \Gamma^T \Gamma) \) is **positive definite**.

---

#### Properties of \( X^T X \)

The matrix \( X^T X \) is always **positive semi-definite** because for any vector \( z \), we have:
\[
z^T (X^T X) z = (Xz)^T (Xz) = \|Xz\|_2^2 \geq 0.
\]
This is the squared \( L^2 \)-norm of \( Xz \), which is always non-negative.

However, \( X^T X \) is not always **positive definite**. If \( X \) has linearly dependent columns (i.e., \( X \) is not full rank), there exist non-zero vectors \( z \) such that \( Xz = 0 \). For these \( z \), \( z^T (X^T X) z = 0 \), meaning \( X^T X \) is not invertible. Therefore, \( X^T X \) being only semi-definite can cause issues in ensuring a unique minimum for \( J(w) \).

---

####  \( \Gamma^T \Gamma \)

The term \( \Gamma^T \Gamma \) acts as a **regularization term** that compensates for potential deficiencies in \( X^T X \). If \( \Gamma^T \Gamma \) is **positive definite**, then \( (X^T X + \Gamma^T \Gamma) \) becomes positive definite, regardless of whether \( X^T X \) is full rank. This ensures that:
\[
(X^T X + \Gamma^T \Gamma) z \neq 0, \quad \forall z \neq 0.
\]

Thus, \( \Gamma^T \Gamma \) must be positive definite to guarantee the invertibility of \( (X^T X + \Gamma^T \Gamma) \), ensuring a unique solution for \( w \).

---

#### Sufficient and Necessary Condition

The condition for \( J(w) \) to have a unique minimum is that \( \Gamma^T \Gamma \) is **positive definite**. This condition is both **sufficient** and **necessary**:
- **Necessary**: Without \( \Gamma^T \Gamma \) being positive definite, \( (X^T X + \Gamma^T \Gamma) \) might not be invertible, leading to multiple solutions for \( w \).
- **Sufficient**: If \( \Gamma^T \Gamma \) is positive definite, then \( (X^T X + \Gamma^T \Gamma) \) is guaranteed to be positive definite, ensuring a unique minimum.

---

#### Summary of \( X^T X \)

- \( X^T X \) is always **positive semi-definite** because:
  \[
  z^T (X^T X) z = \|Xz\|_2^2 \geq 0, \quad \forall z.
  \]
- \( X^T X \) is not necessarily positive definite if \( X \) is not full rank (i.e., if \( X \) has linearly dependent columns).


The condition \( \Gamma^T \Gamma \) must be **positive definite** is required for the matrix \( (X^T X + \Gamma^T \Gamma) \) to be invertible. This guarantees that the cost function \( J(w) \) has a unique minimum.

---

### **(c) Relation of \( \Gamma \) to Anisotropic Normal Distribution**

If \( w \sim N(0, \Sigma) \), where \( \Sigma \) is the positive-definite covariance matrix of the prior distribution, the relationship between \( \Gamma \) and \( \Sigma \) can be derived as follows:

1. **Prior Log-Likelihood**:  
   The probability density function (PDF) of the anisotropic normal distribution is:
   \[
   p(w) = \frac{1}{\sqrt{(2\pi)^d |\Sigma|}} \exp\left(-\frac{1}{2} w^T \Sigma^{-1} w\right).
   \]

2. **Regularization Term in the Cost Function**:  
   The prior contributes a penalty term to the cost function:
   \[
   -\log p(w) \propto \frac{1}{2} w^T \Sigma^{-1} w.
   \]

3. **Relation to \( \Gamma \)**:  
   The regularization term in the cost function is:
   \[
   \|\Gamma w\|_2^2 = w^T (\Gamma^T \Gamma) w.
   \]
   Comparing the two expressions, we identify:
   \[
   \Gamma^T \Gamma = \Sigma^{-1}.
   \]

Thus, \( \Gamma \) corresponds to the inverse square root of the covariance matrix \( \Sigma \). If needed, \( \Gamma \) can be computed using Cholesky decomposition or spectral methods:
\[
\Gamma = \Sigma^{-1/2}.
\]


---

### **(d) Isocontours in 2D Space**

The isocontours of the two terms \( \|Xw - y\|_2^2 \) and \( \|\Gamma w\|_2^2 \) in the cost function are ellipses. Here's how they behave in a 2D feature space (\( d = 2 \)):

#### **1. Isocontours of \( \|Xw - y\|_2^2 \)**
- These ellipses are centered at \( w^* \), the solution minimizing \( J(w) \).
- The shape and orientation depend on the eigenvalues and eigenvectors of \( X^T X \), which determine the scaling and rotation of the ellipse axes.

#### **2. Isocontours of \( \|\Gamma w\|_2^2 \)**
- These ellipses are centered at \( w = 0 \) (the origin).
- The shape and orientation depend on \( \Gamma^T \Gamma \), which reflects the anisotropy of the regularization term (linked to the covariance matrix \( \Sigma \)).

#### **3. Interaction Between the Two Terms**
- The solution \( w^* \) is the point where the two sets of ellipses intersect and balance.
- \( \|Xw - y\|_2^2 \) encourages \( w \) to fit the data, while \( \|\Gamma w\|_2^2 \) penalizes large weights.

#### **4. Sketch Description**
- **Ellipse for \( \|Xw - y\|_2^2 \)**: Centered at \( w^* \), aligned with the covariance structure of \( X^T X \).
- **Ellipse for \( \|\Gamma w\|_2^2 \)**: Centered at the origin, reflecting the regularization imposed by \( \Gamma^T \Gamma \).
- **Intersection**: \( w^* \) lies at the intersection of these two ellipses, representing the balance between data fitting and regularization.

---

### **Summary of (c) and (d)**
1. **Relation**: \( \Gamma^T \Gamma = \Sigma^{-1} \), where \( \Sigma \) is the covariance matrix of the prior distribution.
2. **Isocontours**: Ellipses for \( \|Xw - y\|_2^2 \) and \( \|\Gamma w\|_2^2 \) intersect at \( w^* \), balancing data fitting and regularization.

---

# **Exercise V: Nearest Neighbours and kd-Trees**

## **Python Implementation**

### **kd-Tree Construction**
```C++
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KDTreeNode {
    vector<double> point;       // The k-dimensional point
    KDTreeNode* left;          // Pointer to the left child
    KDTreeNode* right;        // Pointer to the right child

    KDTreeNode(const vector<double>& p) : point(p), left(nullptr), right(nullptr) {}
};

// Function to build the KD-Tree
KDTreeNode* buildKDTree(vector<vector<double>>& points, int depth = 0) {
    if (points.empty()) return nullptr;

    int k = points[0].size();  // Number of dimensions
    int axis = depth % k;     // Splitting axis

    // Sort points based on the current axis
    sort(points.begin(), points.end(), [axis](const vector<double>& a, const vector<double>& b) {
        return a[axis] < b[axis];
    });

    int median = points.size() / 2;

    // Create a new node for the median point
    KDTreeNode* node = new KDTreeNode(points[median]);

    // recursively bulding SubTree
    vector<vector<double>> leftPoints(points.begin(), points.begin() + median);
    vector<vector<double>> rightPoints(points.begin() + median + 1, points.end());
    node->left = buildKDTree(leftPoints, depth + 1);
    node->right = buildKDTree(rightPoints, depth + 1);

    return node;
}

// DFS of the KD-Tree
void depthFirstSearch(KDTreeNode* node, vector<vector<double>>& result) {
    if (!node) return;

    result.push_back(node->point);

    depthFirstSearch(node->left, result);
    depthFirstSearch(node->right, result);
}

int main() {
    vector<double> data = {
    0.28, 0.13, 0.65, 0.31, 
    0.61, 0.56, 0.75, 0.15, 
    0.71, 0.12, 0.97, 0.28, 
    0.38, 0.97, 0.97, 0.15, 
    0.03, 0.13, 0.96, 0.44, 
    1.00, 0.97, 0.43, 0.79, 
    0.47, 0.00, 0.04, 0.81, 
    0.10, 0.44, 0.42, 0.26, 
    0.93, 0.31, 0.33, 0.57, 
    0.44, 0.18, 0.07, 0.44, 
    0.26, 0.50, 0.64, 0.49, 0.42, 0.29, 0.06, 0.78, 0.55, 0.65, 0.40, 0.75, 0.55, 0.33, 0.77, 0.93, 0.90, 0.65, 0.40, 0.94, 0.29, 0.35, 0.88,
    0.12, 0.48, 0.34, 0.95, 0.47, 0.85, 0.05, 0.56, 0.15, 0.86, 0.83, 0.36, 0.74, 0.09, 0.69, 0.47, 0.34, 0.50, 0.98, 0.98, 0.69,
    0.67, 0.05, 0.23, 0.54, 0.37, 0.78, 0.67, 0.35, 0.52, 0.36, 0.03, 0.54, 0.72, 0.38, 0.72, 0.22, 0.11, 0.62, 0.65, 0.22, 0.41,
    0.09, 0.23, 0.35, 0.38, 0.65, 0.33, 0.73, 0.95, 0.76, 0.83, 0.52, 0.44, 0.32, 0.15, 0.01, 0.31, 0.65, 0.78, 0.33, 0.85, 0.23,
    0.83, 0.21, 0.60, 0.82, 0.33, 0.75, 0.05, 0.28, 0.70, 0.32, 0.65, 0.17, 0.56, 0.65, 0.96, 0.47, 0.55, 0.14, 0.28, 0.68, 1.00,
    0.11, 0.53, 0.84, 0.50, 0.75, 0.88, 0.36, 0.88, 0.97, 0.72, 0.90, 0.62, 0.31, 0.64, 0.53, 0.64, 0.33, 0.79, 0.37, 0.85, 0.14,
    0.63, 0.80, 0.95, 0.14, 0.50, 0.25, 0.06, 0.64, 0.82, 0.75, 0.42, 0.21, 0.42, 0.98, 0.65, 0.78, 0.87, 0.16, 0.97, 0.80, 0.63,
    0.46, 0.45, 0.04, 0.01, 0.98, 0.99, 0.14, 0.53, 0.54, 0.57, 0.47
    };

    // Converting the 1D data into a vector of 4D points
    vector<vector<double>> points_4d;
    for (size_t i = 0; i < data.size(); i += 4) {
        points_4d.push_back({data[i], data[i + 1], data[i + 2], data[i + 3]});
    }

    // Build the KD-Tree
    KDTreeNode* kdTreeRoot = buildKDTree(points_4d);

    // Perform DFS traversal
    vector<vector<double>> dfsResult;
    depthFirstSearch(kdTreeRoot, dfsResult);

    // Print the DFS traversal order
    cout << "Depth-First Traversal Order (4D):\n";
    for (size_t i = 0; i < dfsResult.size(); ++i) {
        cout << "Node " << i + 1 << ": (";
        for (size_t j = 0; j < dfsResult[i].size(); ++j) {
            cout << dfsResult[i][j];
            if (j < dfsResult[i].size() - 1) cout << ", ";
        }
        cout << ")\n";
    }

    return 0;
}

```
``` Python
Depth-First Traversal Order (4D):
Node 1: (0.53, 0.54, 0.57, 0.47)
Node 2: (0.1, 0.44, 0.42, 0.26)
Node 3: (0.41, 0.09, 0.23, 0.35)
Node 4: (0.5, 0.25, 0.06, 0.64)
Node 5: (0.44, 0.18, 0.07, 0.44)
Node 6: (0.44, 0.32, 0.15, 0.01)
Node 7: (0.52, 0.36, 0.03, 0.54)
Node 8: (0.47, 0.0, 0.04, 0.81)
Node 9: (0.42, 0.29, 0.06, 0.78)
Node 10: (0.05, 0.28, 0.7, 0.32)
Node 11: (0.29, 0.35, 0.88, 0.12)
Node 12: (0.28, 0.13, 0.65, 0.31)
Node 13: (0.48, 0.34, 0.95, 0.47)
Node 14: (0.03, 0.13, 0.96, 0.44)
Node 15: (0.37, 0.78, 0.67, 0.35)
Node 16: (0.38, 0.65, 0.33, 0.73)
Node 17: (0.11, 0.62, 0.65, 0.22)
Node 18: (0.09, 0.69, 0.47, 0.34)
Node 19: (0.26, 0.5, 0.64, 0.49)
Node 20: (0.53, 0.84, 0.5, 0.75)
Node 21: (0.42, 0.98, 0.65, 0.78)
Node 22: (0.38, 0.97, 0.97, 0.15)
Node 23: (0.28, 0.68, 1.0, 0.11)
Node 24: (0.01, 0.98, 0.99, 0.14)
Node 25: (0.5, 0.98, 0.98, 0.69)
Node 26: (0.31, 0.65, 0.78, 0.33)
Node 27: (0.96, 0.47, 0.55, 0.14)
Node 28: (0.55, 0.33, 0.77, 0.93)
Node 29: (0.67, 0.05, 0.23, 0.54)
Node 30: (0.72, 0.38, 0.72, 0.22)
Node 31: (0.63, 0.46, 0.45, 0.04)
Node 32: (0.85, 0.05, 0.56, 0.15)
Node 33: (0.93, 0.31, 0.33, 0.57)
Node 34: (0.65, 0.17, 0.56, 0.65)
Node 35: (0.71, 0.12, 0.97, 0.28)
Node 36: (0.85, 0.23, 0.83, 0.21)
Node 37: (0.79, 0.37, 0.85, 0.14)
Node 38: (0.88, 0.36, 0.88, 0.97)
Node 39: (0.87, 0.16, 0.97, 0.8)
Node 40: (1.0, 0.97, 0.43, 0.79)
Node 41: (0.6, 0.82, 0.33, 0.75)
Node 42: (0.86, 0.83, 0.36, 0.74)
Node 43: (0.82, 0.75, 0.42, 0.21)
Node 44: (0.9, 0.65, 0.4, 0.94)
Node 45: (0.55, 0.65, 0.4, 0.75)
Node 46: (0.72, 0.9, 0.62, 0.31)
Node 47: (0.63, 0.8, 0.95, 0.14)
Node 48: (0.61, 0.56, 0.75, 0.15)
Node 49: (0.95, 0.76, 0.83, 0.52)
Node 50: (0.64, 0.53, 0.64, 0.33)
```

**(b) Why Building the Decision Tree is \(O(n\,d\,h)\)**

#### **Problem Setup**
- **Dataset**: `n` data points, each with `d` real-valued features.
- **Task**: Build a binary classification tree by:
  1. Evaluating all possible univariate splits at each node.
  2. Retaining the split that maximizes the **information gain**.
- **Goal**: Justify that the time complexity to build the tree is **O(ndh)**, where:
  - `n` = Number of data points.
  - `d` = Number of features.
  - `h` = Depth of the tree.

---

#### Time Complexity to Choose a Split for One Node**
- To determine the best split for a single node:
  1. **Radix Sort** each feature's values:
     - Sorting `n` values for `d` features takes **O(nd)** time (linear-time radix sort for each feature).
  2. **Evaluate Splits for Each Feature**:
     - After sorting, compute potential split values in **O(n)** time per feature.
     - For all `d` features, this takes **O(nd)** time.

Thus, for one node, the **time to find the best split** is **O(nd)**.

---

#### Depth of the Tree
- The tree grows to a maximum depth `h`.
- At each level of the tree:
  - The total number of points considered decreases as splits divide the dataset.
  - For simplicity, assume that the total work at each level is proportional to the original `n`.

---

#### Total Time Complexity
- At each level of depth, the work done to determine splits is **O(nd)**.
- For a tree of depth `h`, this process is repeated `h` times.
- Therefore, the total time complexity for building the entire tree is:
  \[
  O(ndh)
  \]

---

#### Key Assumptions
1. Radix sort for real numbers can be done in **O(n)** time **(Explenation of complexity at the end of question b)**.
2. At each node, splits divide the dataset roughly evenly (balanced tree assumption).
3. The depth of the tree (`h`) scales logarithmically with the number of points ($h ≈ \log_2 n$), though `h` is treated as a parameter here.

---

#### Conclusion
The total time complexity for building the decision tree is **O(ndh)**, where:
- `O(nd)` accounts for the split evaluation at each node.
- `O(h)` accounts for the depth of the tree.


### Complexity of Radix Sort for Floating-Point Numbers

#### **Overview**
Radix Sort is a non-comparison-based sorting algorithm that processes numbers digit by digit (or bit by bit). It works efficiently on integers but requires special handling for floating-point numbers. Here's how it can be adapted:

---

#### **Steps**
1. **Convert Floating-Point Numbers to Sortable Integers**:
   - Use the **bit-level representation** of floating-point numbers (IEEE 754 standard).
   - For **negative numbers**, flip the sign bit to ensure they are correctly ordered (as radix sort expects non-negative values).

2. **Radix Sort on Integer Representation**:
   - Perform the radix sort on the integer array.
   - Process each digit (or byte) from the least significant to the most significant.
   - Use **counting sort** internally for each digit to maintain a stable sort.

3. **Convert Sorted Integers Back to Floats**:
   - Reverse the integer-to-float transformation by interpreting the binary data back into floating-point numbers.
   - For flipped negative numbers, reverse the sign bit flipping.

---

#### Time Complexity
- **Sorting Integers**: \( O(n) \), where \( n \) is the number of elements.
- **Conversion**: \( O(n) \) for converting between floating-point numbers and integers.

Total Complexity: **\( O(n) \)**

---

