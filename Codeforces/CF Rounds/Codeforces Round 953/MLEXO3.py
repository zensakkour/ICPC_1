import numpy as np
import matplotlib.pyplot as plt

# Generate a synthetic dataset for visualization
np.random.seed(42)
X = np.random.randn(100, 2)  # 100 samples, 2 features
y = X @ np.array([2, -1]) + np.random.randn(100) * 0.5  # Linear relationship with noise

# Compute X^T X and Gamma^T Gamma
XTX = X.T @ X  # (X^T X)
Gamma = np.array([[1, 0.5], [0.5, 1.5]])  # Example regularization matrix
GammaT_Gamma = Gamma.T @ Gamma  # (Gamma^T Gamma)

# Grid for visualization
w1_range = np.linspace(-3, 3, 100)
w2_range = np.linspace(-3, 3, 100)
W1, W2 = np.meshgrid(w1_range, w2_range)

# Compute the quadratic forms
def quadratic_form(A, W1, W2):
    """Computes the quadratic form for contour visualization."""
    Q = np.array([[W1[i, j], W2[i, j]] for i in range(W1.shape[0]) for j in range(W1.shape[1])])
    return np.reshape(np.einsum('ij,ij->i', Q @ A, Q), W1.shape)

# Compute the isocontours
J_data = quadratic_form(XTX, W1, W2)  # ||Xw - y||_2^2
J_reg = quadratic_form(GammaT_Gamma, W1, W2)  # ||Γw||_2^2
J_total = J_data + J_reg  # Correctly combined cost function (unique, not a repeat)

# Plot all three separately and one combined plot
fig, axes = plt.subplots(2, 2, figsize=(12, 10))

# Plot 1: Isocontour of ||Xw - y||_2^2
ax = axes[0, 0]
contour1 = ax.contour(W1, W2, J_data, levels=20, cmap='coolwarm')
ax.set_title(r'Isocontours of $\|Xw - y\|_2^2$')
ax.set_xlabel(r'$w_1$')
ax.set_ylabel(r'$w_2$')
fig.colorbar(contour1, ax=ax)

# Plot 2: Isocontour of ||Γw||_2^2
ax = axes[0, 1]
contour2 = ax.contour(W1, W2, J_reg, levels=20, cmap='summer')
ax.set_title(r'Isocontours of $\|\Gamma w\|_2^2$')
ax.set_xlabel(r'$w_1$')
ax.set_ylabel(r'$w_2$')
fig.colorbar(contour2, ax=ax)

# Plot 3: Combined isocontour (J_total)
ax = axes[1, 0]
contour3 = ax.contour(W1, W2, J_total, levels=20, cmap='viridis')
ax.set_title(r'Isocontours of $J(w) = \|Xw - y\|_2^2 + \|\Gamma w\|_2^2$')
ax.set_xlabel(r'$w_1$')
ax.set_ylabel(r'$w_2$')
fig.colorbar(contour3, ax=ax)

# Plot 4: All contours in one plot (but ensuring the sum is unique)
ax = axes[1, 1]
contour1 = ax.contour(W1, W2, J_data, levels=20, cmap='coolwarm', alpha=0.6)
contour2 = ax.contour(W1, W2, J_reg, levels=20, cmap='summer', alpha=0.6)
contour3 = ax.contour(W1, W2, J_total, levels=20, cmap='viridis', linewidths=1.5)
ax.set_title(r'Combined Isocontours')
ax.set_xlabel(r'$w_1$')
ax.set_ylabel(r'$w_2$')

# Legend for the combined plot
handles = [
    plt.Line2D([0], [0], color='red', lw=2, label=r'$\|Xw - y\|_2^2$'),
    plt.Line2D([0], [0], color='green', lw=2, label=r'$\|\Gamma w\|_2^2$'),
    plt.Line2D([0], [0], color='purple', lw=2, label=r'$J(w)$')
]
ax.legend(handles=handles, loc='upper right')

plt.tight_layout()
plt.show()
