import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from sklearn.svm import SVC

# Original data points
X = np.array([
    [1, 1], [-1, -1],  # Class +1
    [1, -1], [-1, 1]   # Class -1
])
y = np.array([1, 1, -1, -1])  # Class labels

# Feature transformation function
def phi(x1, x2):
    return np.array([
        np.sqrt(2) * x1,       # Phi_1
        np.sqrt(2) * x1 * x2,  # Phi_2
        1,                     # Phi_3
        np.sqrt(2) * x2,       # Phi_4
        x1**2,                 # Phi_5
        x2**2                  # Phi_6
    ])

# Transform data
X_transformed = np.array([phi(x1, x2) for x1, x2 in X])

# Train SVM in transformed space
svm = SVC(kernel='linear')
svm.fit(X_transformed, y)

# Extract hyperplane parameters
w = svm.coef_[0]
b = svm.intercept_[0]

### PLOT 1: ORIGINAL 2D DATA ###
def plot_original_space():
    plt.figure(figsize=(6, 6))
    
    plt.scatter(X[y == 1, 0], X[y == 1, 1], color='red', s=100, label='Class +1')
    plt.scatter(X[y == -1, 0], X[y == -1, 1], color='blue', s=100, label='Class -1')
    
    plt.axhline(0, color='black', linestyle='--', linewidth=1)
    plt.axvline(0, color='black', linestyle='--', linewidth=1)
    plt.xlabel(r'$x_1$')
    plt.ylabel(r'$x_2$')
    plt.title('Original 2D Data (Not Linearly Separable)')
    plt.legend()
    plt.grid()
    plt.show()

### PLOT 2: TRANSFORMED 3D SPACE WITH HYPERPLANE ###
def plot_transformed_space():
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection='3d')

    # Scatter plot
    for i, label in enumerate(y):
        color = 'red' if label == 1 else 'blue'
        ax.scatter(X_transformed[i, 0], X_transformed[i, 1], X_transformed[i, 2], c=color, s=100)

    # Create meshgrid for hyperplane
    x1_range = np.linspace(-2, 2, 20)
    x2_range = np.linspace(-2, 2, 20)
    X1, X2 = np.meshgrid(x1_range, x2_range)
    Z = (-w[0] * X1 - w[1] * X2 - b) / w[2]  # Compute Z from w·x + b = 0

    # Plot the linear hyperplane
    ax.plot_surface(X1, X2, Z, color='gray', alpha=0.5, edgecolor='black')

    # Marking support vectors
    sv_indices = svm.support_
    for i in sv_indices:
        ax.scatter(X_transformed[i, 0], X_transformed[i, 1], X_transformed[i, 2], c='green', edgecolors='black', s=200, label="Support Vector" if i == sv_indices[0] else "")

    ax.set_xlabel(r'$\Phi_1 = \sqrt{2}x_1$')
    ax.set_ylabel(r'$\Phi_2 = \sqrt{2}x_1x_2$')
    ax.set_zlabel(r'$\Phi_3 = 1$')
    ax.set_title('Transformed 3D Space with SVM Hyperplane')

    plt.show()

### PLOT 3: PHI_1 vs PHI_2 WITH DECISION BOUNDARY ###
def plot_phi1_phi2_boundary():
    plt.figure(figsize=(6, 6))
    
    for i, label in enumerate(y):
        color = 'red' if label == 1 else 'blue'
        plt.scatter(X_transformed[i, 0], X_transformed[i, 1], c=color, s=100)

    # Create meshgrid for decision boundary
    x1_range = np.linspace(-2, 2, 100)
    x2_range = np.linspace(-2, 2, 100)
    X1, X2 = np.meshgrid(x1_range, x2_range)
    decision_boundary = (-w[0] * X1 - w[1] * X2 - b)  # Decision function

    # Plot decision boundary
    plt.contour(X1, X2, decision_boundary, levels=[0], colors='black')

    plt.xlabel(r'$\Phi_1 = \sqrt{2}x_1$')
    plt.ylabel(r'$\Phi_2 = \sqrt{2}x_1x_2$')
    plt.title('Decision Boundary in (Phi_1, Phi_2) Space')
    plt.grid()
    plt.show()

# Run the plots
plot_original_space()
plot_transformed_space()
plot_phi1_phi2_boundary()
