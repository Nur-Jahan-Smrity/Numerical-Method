#include<bits/stdc++.h>
using namespace std;
int n;
double ar[100000],arp[100000];
double f(double x)
{
    double ans=0;
    for(int i=0; i<=n; i++)
    {
        double ans1=1;
        for(int j=0; j<i; j++) ans1*=x;
        ans+=(ar[i]*ans1);
    }
    return ans;
}
double f_prime(double x)
{
    double ans=0;
    for(int i=0; i<=n; i++)
    {
        double ans1=1;
        for(int j=0; j<i; j++) ans1*=x;
        ans+=(arp[i]*ans1);
    }
    return ans;
}
/*
Algorithm: Newton-Raphson Method
1.Assign an initial value for x, say x0 and stopping criterion E.
2.Compute f (x0) and f ‘(x0).
3.Find the improved estimate of x0
x1 = x0 – f (x0) / f ’(x0)
4.Check for accuracy of the latest estimate.
If | x1-x0 | < E then stop; otherwise continue.
5.Replace x0 by x1 and repeat steps 3 and 4.
*/
int main()
{
    cout<<"What is Degree of polynomial Equation? "<<endl;
    cin>>n;
    double a,b,x0;
    for(int i=n; i>=0; i--)
    {
        cout<<"Enter Co-efficient of X^"<<i<<" : ";
        cin>>ar[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        arp[i]=ar[i+1]*(i+1);
    }
    double x=1,nx=0,i=1;
    cout<<"X0 = 0\n";
    while(fabs(nx-x)>=0.0005)
    {
        x=nx;
        nx=x-(f(x)/f_prime(x));
        cout<<"X"<<i<<" = "<<nx<<endl;
        i++;
    }
    cout<<nx<<endl;
}
/*

2
x^2-3x+2
1
-3
2

*/
