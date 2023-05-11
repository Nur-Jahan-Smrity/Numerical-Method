//trapezoidal
#include<iostream>
#include<iomanip>
using namespace std;

float y(float x)
{
    return x/(1+x);
}

int main()
{
    float a,b,h,s;
    int i,n;

    cout<<"Enter the lower limit,upper limit, no. of subintervals"<<endl;
    cin>>a>>b>>n;
    cout<<fixed;

    h=(b-a)/n;
    //y0+yn=s;
    s=y(a)+y(b);
    for(i=0; i<n; i++)
    {
        cout<<"x= "<<i<<"        y= "<<y(a+i*h)<<endl;
    }
    for(i=1; i<=n-1; i++)
    {
       s += 2*y(a+i*h);
    }


    cout<<"Value of integral is ";
    cout<<setw(3)<<setprecision(3);
    cout<<(h/2)*s<<endl;
    return 0;
}
/*
Enter the lower limit,upper limit, no. of subintervals
0 1 6
x= 0        y= 0.000000
x= 1        y= 0.142857
x= 2        y= 0.250000
x= 3        y= 0.333333
x= 4        y= 0.400000
x= 5        y= 0.454545
Value of integral is 0.305
*/
