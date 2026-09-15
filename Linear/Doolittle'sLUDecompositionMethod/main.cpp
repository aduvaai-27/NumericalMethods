#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    do
    {
        int n;
        cin>>n;
        double A[n][n],L[n][n],U[n][n];
        double B[n],X[n],Z[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>A[i][j];
            }
            cin>>B[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                L[i][j]=0;
                U[i][j]=0;
            }
            L[i][i]=1;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                double sum=0;
                for(int k=0; k<i; k++)
                {
                    sum+=L[i][k]*U[k][j];
                }
                U[i][j]=A[i][j]-sum;
            }

            for(int j=i+1; j<n; j++)
            {
                double sum=0;
                for(int k=0; k<i; k++)
                {
                    sum+=L[j][k]*U[k][i];
                }
                L[j][i]=(A[j][i]-sum)/U[i][i];
            }

        }
        cout<<"L :"<<endl;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<L[i][j]<<"\t";
            }
            cout<<endl;
        }

        cout<<"U :"<<endl;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<U[i][j]<<"\t";
            }
            cout<<endl;
        }
        //forward
        for(int i=0; i<n; i++)
        {
            double sum=0;
            for(int j=0; j<i; j++)
            {
                sum+=L[i][j]*Z[j];

            }
            Z[i]=B[i]-sum;
        }


        int test=1;
        for(int i=0; i<n; i++)
        {
            bool rowZero=true;
            for(int j=0; j<n; j++)
            {
                if(fabs(U[i][j])>0.00001)
                {
                    rowZero=false;
                }
            }

            if(rowZero && fabs(Z[i])>0.00001)
            {
                test=0;
                break;
            }
            else if (rowZero)
            {
                test=2;

            }
        }

        if(test==0)
        {
            cout<<"There is no solution . "<<endl;

        }
        else if(test == 2)
        {
            cout<<"There is infinity solution."<<endl;
        }
        else
        {

            //backward
            for(int i=n-1; i>=0; i--)
            {
                double sum=0;
                for(int j=i+1; j<n; j++)
                {
                    sum+=U[i][j]*X[j];
                }
                X[i]=(Z[i]-sum)/U[i][i];
            }

            for(int i=0; i<n; i++)
            {
                cout<<"X"<<i+1<<" = "<<X[i]<<endl;
            }
        }

        cout<<"Do you want to continue?"<<endl;
        cin>>ch;


    }
    while(ch=='y' || ch=='Y');


}
