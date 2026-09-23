#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double A[n][n+1];
    double orig[n][n+1];


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cin>>A[i][j];
            orig[i][j]=A[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        double pivot=A[i][i];
        if(fabs(pivot)<0.0001)
        {
            continue;
        }
        for(int j=0; j<=n; j++)
        {
            A[i][j]/=pivot;
        }
        for(int k=i+1; k<n; k++)
        {
            double cofactor=A[k][i];
            for(int j=i; j<=n; j++)
            {
                A[k][j]-=cofactor*A[i][j];

            }
        }

    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            printf("%10.3f",A[i][j]);
        }
        cout<<endl;
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i+1; j<n; j++)
        {
            A[i][n]-=A[i][j]*A[j][n];

        }
        A[i][n]/=A[i][i];

    }

    int type=1;
    int rank=0;
    for(int i=0; i<n; i++)
    {
        bool rowZero=true;
        for(int j=0; j<n; j++)
        {
            if(fabs(A[i][j])>0.0001)
            {
                rowZero=false;
            }
        }
        if(rowZero && fabs(A[i][n])>0.001)
        {
            type =0;
            break;
        }
        else if(!rowZero)
        {
            rank++;
        }
    }
    if(type==0)
    {
        cout<<"No Solution"<<endl;

    }
    else if(rank<n)
    {
        cout<<"Infinity Solution"<<endl;
    }
    else
    {
        cout<<"Unique Solution"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<"X"<<i+1<<" = "<<A[i][n]<<endl;
        }

        cout<<"Verification : "<<endl;
        for(int i=0; i<n; i++)
        {
            double sum=0;
            for(int j=0; j<n; j++)
            {
                sum+=orig[i][j]*A[j][n];
            }
            cout<<"Equation"<<i+1<<" : "<<sum<<" = "<<orig[i][n]<<endl;
        }
    }




}
