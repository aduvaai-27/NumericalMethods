#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double A[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        double pivot = A[i][i];
        if (pivot < 0.0001)
        {
            continue;
        }
        for (int j = 0; j <= n; j++)
        {
            A[i][j] = A[i][j] / pivot;
        }
        for (int k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            ;
            double cofactor = A[k][i];
            for (int j = 0; j < n + 1; j++)
            {
                A[k][j] = A[k][j] - cofactor * A[i][j];
            }
        }
    }
    cout << "Reduced Echelon Form :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%10.3f", A[i][j]);
        }

        cout << endl;
    }
    int type = 1;
    int rank = 0;

    for (int i = 0; i < n; i++)
    {
        bool rowZero = true;
        for (int j = 0; j < n; j++)
        {
            if (fabs(A[i][j]) > 0.0001)
            {
                rowZero = false;
            }
        }
        if (rowZero && fabs(A[i][n]) > 0.0001)
        {
            type = 0;
            break;
        }
        else if (!rowZero)
        {
            rank++;
        }
    }
    if (type == 0)
    {
        cout << "No solution" << endl;
    }
    else if (rank < n)
    {
        cout << "Infinity Solution" << endl;
    }
    else
    {
        cout << "Unique Solution" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "X" << i + 1 << " = " << A[i][n] << endl;
        }
    }
}
