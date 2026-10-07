#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double x1[10],y1[10];
    for(int i=0; i<n; i++)
    {
        cin>>x1[i]>>y1[i];
    }

    int choice;

    cout << "\nChoose model:\n";
    cout << "1. y = a*x^b\n";
    cout << "2. P = p0*e^(k*t)\n";
    cout << "3. T = a + b*f(x)\n";
    cout << "Enter choice: ";
    cin >> choice;

    double a, b;
//y=e*x^b;
    if(choice ==1)
    {
        double sx=0,sx2=0,sy=0,sxy=0;
        for(int i=0; i<n; i++)
        {
            double x=log(x1[i]);
            double y=log(y1[i]);
            sx+=x;
            sx2+=x*x;
            sxy+=x*y;
            sy+=y;
        }

        b=(n*sxy- sx*sy)/(n*sx2 - sx*sx);
        double r=(sy-b*sx)/n;
        a=exp(r);
        cout << "y = " << a << " * x^" << b << endl;

    }

//P=p0e^kt
    else if(choice==2)
    {
        double sx=0,sxy=0,sy=0,sx2=0;
        for(int i=0; i<n; i++)
        {

            double x=x1[i];
            double y=log(y1[i]);
            sx+=x;
            sxy+=x*y;
            sx2+=sx*sx;
            sy+=y;

        }
        b=(sxy*n-sx*sy)/(sx2*n-sx*sx);
        double r=(sy-b*sx)/n;

        a=exp(r);
        cout<<"Equation P = "<<a<<"e^("<<b<<"t)"<<endl;

    }

    else if(choice == 3)
    {
        double sx=0,sx2=0,sxy=0,sy=0;
        for(int i=0; i<n; i++)
        {
            double x=exp(x1[i]/4);
            double y=y1[i];
            sx+=x;
            sy+=y;
            sxy+=x*y;
            sx2+=x*x;

        }
        b=(n*sxy - sx*sy)/ (n*sx2 - sx*sx);
        a=(sy-b*sx)/n;
        cout << "Equation: T = " << a << " + " << b << "*e^(x/4)" << endl;

    }
    return 0;


}
