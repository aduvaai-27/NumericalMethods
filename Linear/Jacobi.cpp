#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.0001

int main()
{
    int n;
    cin >> n;
    double a[n][n];
    double b[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    double x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    double oldX[n];

    while (true)
    {
        for (int i = 0; i < n; i++)
            oldX[i] = x[i];

        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += a[i][j] * oldX[j];
                }
            }
            x[i] = (b[i] - sum) / a[i][i];
        }
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (abs(oldX[i] - x[i]) >= EPSILON)
            {
                done = false;
                break;
            }
        }
        if (done)
        {
            break;
        }
    }
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}