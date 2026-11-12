#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100;
int degree;
double coeff[MAX];
double upper_limit;
double lower_limit;
int intervals;
double f(double x) 
{
    double result = 0;
    for (int i = 0; i <= degree; i++) 
    {
        result += coeff[i] * pow(x, degree - i);
    }
    return result;
}
void print_function() 
{
    bool first = true;
    for (int i = 0; i <= degree; i++) 
    {
        if (coeff[i] != 0) 
        {
            if (!first && coeff[i] > 0) 
            {
                cout << "+";
            }
            cout << coeff[i];
            if (degree - i > 0) 
            {
                cout << "x^" << (degree - i);
            }
            first = false;
        }
    }
    if (first) 
    {
        cout << "0";
    }
    cout << endl;
}
void simpson38() 
{
    double h = (upper_limit - lower_limit) / intervals;
    double sum = f(lower_limit) + f(upper_limit);
    for (int i = 1; i < intervals; i++) 
    {
        double x = lower_limit + i * h;
        if (i % 3 == 0) 
        {
            sum += 2 * f(x);
        } 
        else 
        {
            sum += 3 * f(x);
        }
    }
    double integral = (3.0 * h / 8.0) * sum;
    cout << "The value of the integral is: " << integral << endl;
}
int main() 
{
    cout << "No. of degree of the function: ";
    cin >> degree;
    cout << "Coefficients of the function (from a_n to a_0): ";
    for (int i = 0; i <= degree; i++) 
    {
        cin >> coeff[i];
    }
    cout << "Upper limit: ";
    cin >> upper_limit;
    cout << "Lower limit: ";
    cin >> lower_limit;
    cout << "Number of intervals (multiple of 3): ";
    cin >> intervals;
    if (intervals <= 0 || intervals % 3 != 0)
    {
        cout << "Error: number of intervals must be a positive multiple of 3." << endl;
        return 1;
    }
    cout << endl;
    cout << "Function: ";
    print_function();
    simpson38();
    return 0;
}
