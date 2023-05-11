//Simpson’s 1/3 Rule implementation
#include<bits/stdc++.h>
#define ll long long
using namespace std;
double f(double x)
{
   // return exp(x);
   return (1/(1+x*x));
}
double simpsons(double f(double x),double a,double b,int n)
{
    double h,l,x,sum=0;
    int i;
    h=fabs(b-a)/n;
    for(i=1; i<n; i++)
    {
        x=a+i*h;
        // cout<<"x= "<<i<<"        y= "<<f(x)<<endl;
        if(i%2==0)
        {
            sum=sum+2*f(x);
        }
        else
            sum=sum+4*f(x);
    }
    l=(h/3)*(f(a)+f(b)+sum);
    return l;
}
int main()
{
    int n,i=2;
    double a,b,h,x,sum=0,l,eps,nw;
    cout<<"enter lower limit and upper limit and its interval : "<<endl;
    scanf("%lf%lf%lf",&a,&b,&eps);
    nw=simpsons(f,a,b,i);
    //cout<<" nm "<<nw<<endl;
   /* do
    {
        l=nw;
        i=i+2;
        nw=simpsons(f,a,b,i);
    }
    while(fabs(nw-l)>=eps);*/
    printf("\nThe integral is: %lf .\n",nw);
}
/*
Input :
enter lower limit and upper limit and its interval :
0 1 6

The integral is: 0.783333 .
*/
