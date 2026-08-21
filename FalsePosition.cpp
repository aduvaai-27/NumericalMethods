#include <bits/stdc++.h>
#define EPSILON 0.001
using namespace std;

double func(double x)
{
    return 3 * x - cos(x) - 1;
}
double falsePosition(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "Your Initial Guesses Are Wrong" << endl;
        return -1;
    }
    else
    {
        double c = 0;

        while (abs(a - b) / abs(b) >= EPSILON)
        {
            c = a - ((b - a) / (func(b) - func(a))) * func(a);
            if (abs(func(c)) <= EPSILON)
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
    double a = 0, b = 1;
    cout << falsePosition(a, b) << endl;
    return 0;
}
