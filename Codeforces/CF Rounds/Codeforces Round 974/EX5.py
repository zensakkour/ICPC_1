class KDTreeNode:
    def __init__(self, point, left=None, right=None):
        """
        Represents a node in the kd-tree.
        :param point: The point stored in this node (e.g., a 4D tuple).
        :param left: Pointer to the left child.
        :param right: Pointer to the right child.
        """
        self.point = point
        self.left = left
        self.right = right

def build_kd_tree(points, depth=0):
    """
    Builds a kd-tree from a list of k-dimensional points.
    :param points: A list of tuples (each has k coordinates).
    :param depth: Current depth in the tree (used to determine splitting axis).
    :return: The root node of the kd-tree (KDTreeNode).
    """
    if not points:
        return None

    k = len(points[0])  # Number of dimensions
    axis = depth % k    # Choose splitting axis based on depth

    # Sort points according to the axis
    points.sort(key=lambda x: x[axis])
    median = len(points) // 2

    return KDTreeNode(
        point=points[median],
        left=build_kd_tree(points[:median], depth + 1),
        right=build_kd_tree(points[median+1:], depth + 1)
    )


def depth_first_search(node, result=None):
    """
    Performs a depth-first (preorder) traversal of the kd-tree.
    :param node: KDTreeNode (current node).
    :param result: list to store the traversal order (defaults to new list).
    :return: list of points visited in DFS order (root-left-right).
    """
    if result is None:
        result = []

    if node is None:
        return result

    # 1. Visit the current node
    result.append(node.point)
    # 2. Traverse the left subtree
    depth_first_search(node.left, result)
    # 3. Traverse the right subtree
    depth_first_search(node.right, result)

    return result



# All 200 numbers (should be 50 points * 4 dimensions = 200 floats)
data_1d = [
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
]

# Convert every 4 consecutive floats into one 4D tuple
points_4d = []
for i in range(0, len(data_1d), 4):
    p = (data_1d[i], data_1d[i+1], data_1d[i+2], data_1d[i+3])
    points_4d.append(p)

print("Number of 4D points:", len(points_4d))  # Should be 50
assert(len(points_4d)==50)

print("Example point #0:", points_4d[0])      # Should be (0.28, 0.13, 0.65, 0.31)


# 2) Build the kd-tree
kd_tree_root = build_kd_tree(points_4d)

# 3) DFS Traversal
dfs_result = depth_first_search(kd_tree_root)

# 4) Print the results
print("Depth-First Traversal Order (4D):")
for i, p in enumerate(dfs_result):
    print(f"Node {i + 1}: {p}")
