#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.001
double func(double x)
{
    return x * x * x - 2 * x * x + 3 * x + 4;
}

double bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "Guesses are not perfect.";
        return -1;
    }

    else
    {
        double c = a;
        while (abs(a - b)/ abs(b) >= EPSILON)
        {
            c = (a + b) / 2;

            if (abs(func(c)) < EPSILON)
            {
                return c;
            }
            else if (func(c) * func(a) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        return c;
    }
}

int main()
{
    double a = -2, b = 0.5;
    cout << bisection(a, b) << endl;
    return 0;
}