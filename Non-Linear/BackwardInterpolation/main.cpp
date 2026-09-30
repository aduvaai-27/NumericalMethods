#include<bits/stdc++.h>
using namespace std;
int n,h;
double diff[100][100];
double x[100];
double findValue(double val,int term)
{
    double u=(val-x[term-1])/h;
    double y=diff[term-1][0];
    double coefficient=1;
    for(int k=1; k<term; k++)
    {
        coefficient*=(u+(k-1))/k;
        y+=coefficient*diff[term-1][k];
    }
    return y;

}
int main()
{
    cin>>n;
    cin>>h;
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
        cin>>diff[i][0];
    }


    for(int j=1; j<n; j++)
    {
        for(int i=n-1; i>=j; i--)
        {
            diff[i][j]=diff[i][j-1]-diff[i-1][j-1];
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%10.3f",x[i]);
        for(int j=0; j<=i; j++)
        {
            printf("%10.3f",diff[i][j]);

        }
        cout<<endl;
    }

    double target1,target2;
    cin>>target1>>target2;
    double s1=findValue(target1,n);
    double s2=findValue(target2,n);
    cout<<"f("<<target1<<") : "<<s1<<endl;
    cout<<"f("<<target2<<") : "<<s2<<endl;

    double extra;
    cin>>extra;
    diff[n][0]=extra;
    x[n]=x[n-1]+h;
    n++;
    for(int j=1; j<n; j++)
    {
        for(int i=n-1; i>=j; i--)
        {
            diff[i][j]=diff[i][j-1]-diff[i-1][j-1];
        }
    }

    double new_s1=findValue(target1,n);
    double new_s2=findValue(target2,n);


    cout<<"Error 1 :"<<fabs(new_s1-s1)<<endl;
    cout<<"Error 2 :"<<fabs(new_s2-s2)<<endl;


    cout<<"Polynomial : "<<endl;

    cout<<"y = "<<diff[n-1][0];

    for(int i=1; i<n; i++)
    {
        cout<<" + "<<diff[n-1][i]<<"/"<<i<<"!";
        cout<<" *u";

        for(int j=1; j<i; j++)
        {
            cout<<"(u+"<<j<<")";
        }
    }

    cout<<endl;

    cout<<"u = ( x - "<<x[n-1]<<" ) /"<<h<<endl;
}

/*
input
4
1
1 1
2 4
3 9
4 16
3.5 4.5
25

output:
4
1
1 1
2 4
3 9
4 16
     1.000     1.000
     2.000     4.000     3.000
     3.000     9.000     5.000     2.000
     4.000    16.000     7.000     2.000     0.000
3.5 4.5
f(3.5) : 12.25
f(4.5) : 20.25
25
Error 1 :0
Error 2 :0
Polynomial :
y = 25 + 9/1! *u + 2/2! *u(u+1) + 0/3! *u(u+1)(u+2) + 0/4! *u(u+1)(u+2)(u+3)
u = ( x - 5 ) /1

*/
