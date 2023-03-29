#include<bits/stdc++.h>
using namespace std;
double fx(double x)
{
    //return sqrt((10)/(x*x*x+3));
    //return (x*x-1);
    return (1/(sqrt(x+1)));
}
int main()
{
    double x0=0,x1=1,k=0;
    int i=0;
    cout<<"X[0] = "<<1<<endl;
    cout<<"i\t\tx[i]\t\tx[i+1]\t\t|x[i]-x[i+1]|\n";
    while(fabs(x1-x0)>=0.0005)
    {
        x0=x1;
        x1=fx(x0);
        cout<<i++<<"\t\t"<<x0<<"\t\t"<<x1<<"\t\t"<<fabs(x0-x1)<<endl;
        if(k==20)
            break;
        k++;
    }
    cout<<"Ans : ";
    cout<<x1<<endl;
}
//sqrt((10)/(x*x*x+3))
