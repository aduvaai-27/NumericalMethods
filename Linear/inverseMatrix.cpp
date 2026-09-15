#include<bits/stdc++.h>
#define MAX 20
using namespace std;
void cofactor(double A[][MAX],double temp[][MAX],int p,int q,int n)
{
    int row=0,col=0;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=p && j!=q)
            {
                temp[row][col]=A[i][j];
                col++;
                if(col==n-1)
                {
                    col=0;
                    row++;
                }
            }

        }
    }

}

double determinant(double A[][MAX],int n)
{
    if(n==1)
    {
        return A[0][0];
    }
    else
    {
        double det=0;
        int sign =1;
        double temp[MAX][MAX];
        for(int j=0; j<n; j++)
        {
            cofactor(A,temp,0,j,n);
            det+=sign*A[0][j]*determinant(temp,n-1);
            sign*=(-1);
        }
        return det;
    }

}

void adjoint(double A[][MAX],double adj[][MAX],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double temp[MAX][MAX];
            cofactor(A,temp,i,j,n);
            int sign;
            if((i+j)%2==0)
            {
                sign = 1;
            }
            else
            {
                sign = -1;
            }
            adj[j][i]=sign * determinant(temp,n-1);

        }
    }
}

int main()
{
    char ch;
    do
    {
        int n;
        cin>>n;
        double A[MAX][MAX],ADJ[MAX][MAX],INV[MAX][MAX];
        double B[MAX],X[MAX];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>A[i][j];

            }
            cin>>B[i];
        }
        double det=determinant(A,n);
        cout<<"Determinant : "<<det<<endl;

        if(det==0)
        {
            cout<<"Inverse doesn't exists."<<endl;
            return 0;
        }

        adjoint(A,ADJ,n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                INV[i][j]=ADJ[i][j]/det;
            }
        }

        for(int i=0; i<n; i++)
        {
            X[i]=0;
            for(int j=0; j<n; j++)
            {
                X[i]+=INV[i][j]*B[j];
            }
        }
        cout<<"Inverse Matrix : "<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%10.3f",INV[i][j]);
            }
            cout<<endl;
        }

        for(int i=0; i<n; i++)
        {
            cout<<"X"<<i+1<<"="<<X[i]<<endl;
        }
        cout<<"Continue?";
        cin>>ch;
    }
    while(ch=='y' || ch=='Y');


}

/*INPUT:
5
2 1 -1 3 2 9
1 3 2 -1 1 8
3 2 4 1 -2 20
2 1 3 2 1 17
1 -1 2 3 4 15

OUTPUT:

Determinant : 65
Inverse Matrix :
     0.385     0.385     1.923    -3.769     1.615
    -0.000     0.000    -1.000     2.000    -1.000
    -0.246    -0.046    -0.231     0.692    -0.154
    -0.046    -0.446    -1.231     2.692    -1.154
     0.062     0.262     0.308    -0.923     0.538
X1=5.15385
X2=-1
X3=2.26154
X4=-0.138462
X5=1.18462
Continue?n
*/
