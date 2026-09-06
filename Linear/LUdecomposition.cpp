#include <bits/stdc++.h>
using namespace std;
int MAX = 20;
int main()
{
    double A[MAX][MAX], U[MAX][MAX], L[MAX][MAX];
    double B[MAX], X[MAX], Z[MAX];

    int n;
    cout << "Number of Equation : ";
    cin >> n;

    // INPUT
    cout << "Enter the augmented matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        cin >> B[i];
    }

    // Initialize L and U
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            L[i][j] = 0;
            U[i][j] = 0;
        }
        L[i][i] = 1;
    }

    // decompose
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            double sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        for (int j = i + 1; j < n; j++)
        {
            double sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L[j][k] * U[k][i];
            }
            L[j][i] = (A[j][i] - sum) / U[i][i];
        }
    }

    // Print L:
    cout << "L : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << L[i][j] << "\t";
        }
        cout << endl;
    }
    // print U :
    cout << "U : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << U[i][j] << "\t";
        }
        cout << endl;
    }

    // forward substitution:
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int k = 0; k < i; k++)
        {
            sum += L[i][k] * Z[k];
        }
        Z[i] = B[i] - sum;
    }

    // backword substitution:
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int k = i + 1; k < n; k++)
        {
            sum += U[i][k] * X[k];
        }
        X[i] = (Z[i] - sum) / U[i][i];
    }

    // output
    cout << "Solution : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " : " << X[i] << endl;
    }
}