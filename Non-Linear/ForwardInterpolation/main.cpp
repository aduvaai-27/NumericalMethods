#include<bits/stdc++.h>
using namespace std;
int n,h;
double diff[100][100];
double x[100];
double findValue(double val,int terms)
{
    double u=(val-x[0])/h;
    double y=diff[0][0];
    double coefficient=1;
    for(int k=1; k<terms; k++)
    {
        coefficient=coefficient*(u-(k-1))/k;
        y=y+coefficient*diff[0][k];
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
        for(int i=0; i<n-j; i++)
        {
            diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
        }

    }


    for(int i=0; i<n; i++)
    {
        printf("%10.3f",x[i]);
        for(int j=0; j<n-i; j++)
        {
            printf("%10.3f",diff[i][j]);
        }
        cout<<endl;
    }
    double target1,target2;
    cin>>target1>>target2;
    double s1=findValue(target1,n);
    double s2=findValue(target2,n);
    double extra;
    cin>>extra;
    diff[n][0]=extra;
    x[n]=x[n-1]+h;
    n++;
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<n-j; i++)
        {
            diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
        }

    }
    double new_s1=findValue(target1,n);
    double new_s2=findValue(target2,n);

    cout<<"S("<<target1<<") :"<<s1<<endl;
    cout<<"S("<<target2<<") :"<<s2<<endl;
    cout<<"Error in solution 1"<<fabs(new_s1-s1)<<endl;
    cout<<"Error in solution 2"<<fabs(new_s2-s2)<<endl;

    cout<<"Polynomial : "<<endl;
    cout<<"y = "<<diff[0][0];
    for(int i=0; i<n; i++)
    {
        cout<<" + "<<diff[0][i]<<"/"<<i<<"!";
        cout<<" *u";
        for(int j=0; j<i; j++)
        {
            cout<<"(u-"<<j<<")";

        }
    }
    cout<<endl;
    cout<<"u = ( x - "<<x[0]<< " ) /"<<h<<endl;



}

/*input:
5
5
0
0
5
38
10
148
15
332
20
590
18
7
950

output:
5
5
0
0
5
38
10
148
15
332
20
590
     0.000     0.000    38.000    72.000     2.000    -2.000
     5.000    38.000   110.000    74.000     0.000
    10.000   148.000   184.000    74.000
    15.000   332.000   258.000
    20.000   590.000
18
7
950
S(18) :478.003
S(7) :73.2032
Error in solution 10.89856
Error in solution 20.34944*/

