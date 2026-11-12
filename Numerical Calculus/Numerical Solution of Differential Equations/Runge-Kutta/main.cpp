#include <iostream>
using namespace std;
double f(double x, double y) 
{
    return x + (y * y);
}
int main() 
{
    double x = 0.0;
    double y = 1.0;
    double h = 0.1;
    double x_target = 0.3;
    int steps = (x_target - x + 0.0001) / h; 
    cout << "Initial values: x = " << x << ", y = " << y << endl;
    for (int i = 0; i < steps; i++) 
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;
        cout << "At x = " << x << ", y = " << y << endl;
    }
    cout << endl;
    cout << "The approximate value of y at x = " << x_target << " is " << y << endl;
    return 0;
}
