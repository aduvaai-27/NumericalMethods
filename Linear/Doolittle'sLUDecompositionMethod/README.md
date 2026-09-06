# Doolittle LU Decomposition Method

A simple C++ implementation of the **Doolittle LU Decomposition method** for solving a system of linear equations.

## 📌 Overview

The **Doolittle method** is an LU decomposition technique used to solve a system of linear equations:

$$
AX = B
$$

The coefficient matrix $A$ is decomposed into two triangular matrices:

$$
\boxed{A = LU}
$$

where:

- **L** = Lower Triangular Matrix
- **U** = Upper Triangular Matrix
- The diagonal elements of **L** are 1

After decomposing $A$, the system is solved in two steps:

$$
LZ = B
$$

using **Forward Substitution**, followed by:

$$
UX = Z
$$

using **Backward Substitution**.

---

## 🔄 Method Flow

```text
              AX = B
                │
                ▼
             A = LU
                │
                ▼
             LUX = B
                │
                ▼
             LZ = B
                │
                ▼
        Forward Substitution
                │
                ▼
                Z
                │
                ▼
             UX = Z
                │
                ▼
        Backward Substitution
                │
                ▼
                X
```

---

## 🧮 Mathematical Formulas

### 1. Finding U

For Doolittle decomposition:

$$
U_{ij} = A_{ij} - \sum_{k=0}^{i-1} L_{ik} U_{kj}
$$

In the program:

```cpp
U[i][j] = A[i][j] - sum;
```

---

### 2. Finding L

The elements below the diagonal of $L$ are calculated using:

$$
L_{ji} = \frac{A_{ji} - \sum_{k=0}^{i-1} L_{jk} U_{ki}}{U_{ii}}
$$

In the program:

```cpp
L[j][i] = (A[j][i] - sum) / U[i][i];
```

The diagonal elements of $L$ are:

$$
L_{ii} = 1
$$

---

## ➡️ Forward Substitution

After finding $L$ and $U$, solve:

$$
LZ = B
$$

For each $Z_i$:

$$
Z_i = B_i - \sum_{k=0}^{i-1} L_{ik} Z_k
$$

Since the diagonal of $L$ is 1, no division is required.

Program:

```cpp
for (int i = 0; i < n; i++)
{
    double sum = 0;

    for (int k = 0; k < i; k++)
    {
        sum += L[i][k] * Z[k];
    }

    Z[i] = B[i] - sum;
}
```

---

## ⬅️ Backward Substitution

Next solve:

$$
UX = Z
$$

Starting from the last row:

$$
X_i = \frac{Z_i - \sum_{k=i+1}^{n-1} U_{ik} X_k}{U_{ii}}
$$

Program:

```cpp
for (int i = n - 1; i >= 0; i--)
{
    double sum = 0;

    for (int k = i + 1; k < n; k++)
    {
        sum += U[i][k] * X[k];
    }

    X[i] = (Z[i] - sum) / U[i][i];
}
```

---

## 💡 Simple Logic to Remember

The complete algorithm can be remembered as:

```text
A → LU → Z → X
```

More specifically:

```text
A = LU
 ↓
LZ = B
 ↓
UX = Z
 ↓
X = solution
```

### Loop Pattern

| Operation              | Main Loop       | Inner Loop      |
| ----------------------- | --------------- | --------------- |
| Find U                  | `j = i → n-1`   | `k = 0 → i-1`   |
| Find L                  | `j = i+1 → n-1` | `k = 0 → i-1`   |
| Forward Substitution    | `i = 0 → n-1`   | `k = 0 → i-1`   |
| Backward Substitution   | `i = n-1 → 0`   | `k = i+1 → n-1` |

A useful memory trick:

```text
U        → Move RIGHT
L        → Move DOWN

Forward  → TOP to BOTTOM
Backward → BOTTOM to TOP
```

---

## 🧪 Example

Consider the system:

$$
2x_1 + x_2 = 5
$$

$$
x_1 + 3x_2 = 6
$$

The coefficient matrix is:

$$
A =
\begin{bmatrix}
2 & 1 \\
1 & 3
\end{bmatrix}
$$

and:

$$
B =
\begin{bmatrix}
5 \\
6
\end{bmatrix}
$$

### Input

```text
Number of Equation : 2

Enter the augmented matrix :
2 1 5
1 3 6
```

### L Matrix

$$
L =
\begin{bmatrix}
1 & 0 \\
0.5 & 1
\end{bmatrix}
$$

### U Matrix

$$
U =
\begin{bmatrix}
2 & 1 \\
0 & 2.5
\end{bmatrix}
$$

### Forward Substitution

$$
LZ = B
$$

gives:

$$
Z =
\begin{bmatrix}
5 \\
3.5
\end{bmatrix}
$$

### Backward Substitution

$$
UX = Z
$$

gives:

$$
X =
\begin{bmatrix}
1.8 \\
1.4
\end{bmatrix}
$$

### Output

```text
L :
1       0
0.5     1

U :
2       1
0       2.5

Solution :
x1 : 1.8
x2 : 1.4
```

---

## 📚 Algorithm Summary

```text
1. Read A and B
2. Initialize L and U
3. Set diagonal of L to 1
4. Calculate U
5. Calculate L
6. Solve LZ = B using Forward Substitution
7. Solve UX = Z using Backward Substitution
8. Print X
```

## ⭐ Final Formula

The entire method can be summarized as:

$$
\boxed{
AX = B
\;\Rightarrow\;
A = LU
\;\Rightarrow\;
LUX = B
\;\Rightarrow\;
LZ = B
\;\Rightarrow\;
UX = Z
\;\Rightarrow\;
X
}
$$
