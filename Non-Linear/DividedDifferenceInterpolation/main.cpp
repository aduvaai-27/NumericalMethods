#include<bits/stdc++.h>
using namespace std;
int n;
double diff[20][20];
double x[20];
double findValue(double val,int term){
double coefficient=1;
double y=diff[0][0];
for(int k=1;k<term;k++){
    coefficient=coefficient*(val-x[k-1]);
    y+=coefficient*diff[0][k];
    }
    return y;

}
int main(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>x[i];
    cin>>diff[i][0];
}

for(int j=1;j<n;j++){
    for(int i=0;i<n-j;i++){
        diff[i][j]=(diff[i+1][j-1]-diff[i][j-1])/(x[i+j]-x[i]);
    }
}

for(int i=0;i<n;i++){
        printf("%10.3f",x[i]);
    for(int j=0;j<n-i;j++){
        printf("%10.3f",diff[i][j]);
    }
    cout<<endl;
}
double target1,target2;
cin>>target1>>target2;
double s1=findValue(target1,n);
double s2=findValue(target2,n);

cout<<"Solution 1 : "<<s1<<endl;
cout<<"Solution 2 : "<<s2<<endl;

cin>>x[n]>>diff[n][0];
n++;
for(int j=1;j<n;j++){
    for(int i=0;i<n-j;i++){
        diff[i][j]=(diff[i+1][j-1]-diff[i][j-1])/(x[i+j]-x[i]);
    }
}
double new_s1=findValue(target1,n);
double new_s2=findValue(target2,n);

cout<<"Error 1 : "<<fabs(new_s1-s1)<<endl;
cout<<"Error 2 : "<<fabs(new_s2-s2)<<endl;



cout<<"Polynomial : "<<endl;
cout<<"y = "<<diff[0][0];
for(int i=1;i<n;i++){
    cout<<" + "<<diff[0][i];
    for(int j=0;j<i;j++){
        cout<<"(x-"<<x[j]<<")";
    }
}
cout<<endl;

}

/*
input:
5
0 5 10 15 20
0 38 148 332 590
18 7
25 950

output:
5
0 5 10 15 20
0 38 148 332 590
     0.000     5.000     1.000    -0.125     0.012    -0.000
    10.000    15.000    -1.500     0.347    -0.001
    20.000     0.000     8.222    -0.022
    38.000   148.000     1.503
   332.000   590.000
18 7
Solution 1 : 1.18558
Solution 2 : 18.3635
25 950
Error 1 : 227.817
Error 2 : 346.451
Polynomial :
y = 5 + 1(x-0) + -0.125(x-0)(x-10) + 0.0124269(x-0)(x-10)(x-20) + -4.08798e-05(x-0)(x-10)(x-20)(x-38) + 0.00012596(x-0)(x-10)(x-20)(x-38)(x-332)

