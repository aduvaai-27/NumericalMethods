#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double A[n][n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cin>>A[i][j];
        }
    }
    double original[n][n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            original[i][j]=A[i][j];

        }
    }

    for(int i=0; i<n; i++)
    {
        double pivot=A[i][i];
        if(fabs(pivot)<0.001)
        {
            continue;
        }

        for(int j=0; j<=n; j++)
        {
            A[i][j]/=pivot;
        }

        for(int k=0; k<n; k++)
        {
            if(k==i)
            {
                continue;
            }
            double cofactor=A[k][i];
            for(int j=0; j<=n; j++)
            {
                A[k][j]-=cofactor*A[i][j];
            }

        }


    }
    cout << "Reduced Echelon Form :" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {

            printf("%10.3f",A[i][j]);
        }
        cout<<endl;
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

        if(rowZero && fabs(A[i][n])>0.0001)
        {
            type=0;
            break;
        }
        else if(!rowZero)
        {
            rank++;
        }
    }
    if(type==0)
    {
        cout<<"No solution"<<endl;
        return 0;
    }

    if(rank<n)
    {
        cout<<"Infinity Solution"<<endl;
        return 0;
    }

    else
    {
        cout<<"Unique Solution"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<"X"<<i+1<<"="<<A[i][n]<<endl;
        }

        cout<<"Verification:"<<endl;
        for(int i=0; i<n; i++)
        {
            double sum=0;
            for(int j=0; j<n; j++)
            {
                sum+=original[i][j]*A[j][n];

            }
            cout<<"Equation "<<i+1<<" : "<<sum<<" = "<<original[i][n];
            cout<<endl;
        }
    }




}


/*test case 1
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3


Reduced Echelon Form :
     1.000     0.000     0.000     2.000
     0.000     1.000     0.000     3.000
    -0.000    -0.000     1.000    -1.000
Unique Solution
X1=2
X2=3
X3=-1
Verification:
Equation 1 : 8 = 8
Equation 2 : -11 = -11
Equation 3 : -3 = -3

test case 2
2
1 1 3
1 1 5


Reduced Echelon Form :
     1.000     1.000     3.000
     0.000     0.000     2.000
No solution


test case 3
2
1 1 3
2 2 6

Reduced Echelon Form :
     1.000     1.000     3.000
     0.000     0.000     0.000
Infinity Solution
*/
