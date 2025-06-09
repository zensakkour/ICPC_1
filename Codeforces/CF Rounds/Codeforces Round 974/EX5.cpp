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
