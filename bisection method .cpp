//bisection method ..
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<iomanip>
#define nl "\n"
#define all(qz) qz.begin(),qz.end()
#define rall(qz) qz.rbegin(),qz.rend()
#define debug(x) cout<<#x<<" = "<<x<<nl;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pi (3.141592653589)
#define setafter fixed << setprecision
#define NO             cout << "NO" << endl;
#define Yes            cout << "Yes" << endl;
#define No             cout << "No" << endl;
#define yes            cout << "yes" << endl;
#define no             cout << "no" << endl;
#define YES            cout << "YES" << endl;
// reverse(s.begin(), s.end());
using namespace std;
typedef long long ll;
//int j=0;
ll p[1000],i,n,n1, j,k,m;
float x1,x2,x,e;

void bisect(string &s,int len)
{
    for(i=0; i<len; i++)
    {
        //x er highest degree koto check kortesi then oitake amra n er moddhe store kortesi ..
        //   //x^3-4x^2+x+6 .....
        //ei example e highest degree 3 ...so n=3 ..n=n1=3 ..
        if(s[i]=='x')
        {
            n=s[i+2]-'0';
            break;
        }
    }
    n1=n;
    //prothom digit ta ki coefficient kina check korsi....
    if(s[0]>='0' && s[0]<='9')
    {
        p[n]=s[0]-'0',n--;
    }
    //prothom number ta jodi minus hoy porer ta ki coefficient kina check korsi ..
    //plus wala condition di nai karon kono kichur agae kichu nai mane oita positive dhora hoy auto ..like 7x .. 7 er agae plus ase oita mone mone dhora hoy ..
    else if((s[0]=='-' && (s[1]>='0' && s[1]<='9')))
    {
        p[n]=(s[1]-'0')*(-1);
        n--;
    }
    //loop ta chalano hoise coefficient gulo k alada kore array te store korar jonno ...
    for(i=0; i<len; i++)
    {
        //ei condition ta cholbe jodi kono coefficient pai and ter ager value jodi - or + hoy .....
        if(s[i]>='0' && s[i]<='9'&& (s[i-1]=='-' || s[i-1]=='+'))
        {
            p[n]=s[i]-'0';
            if(i>0 && s[i-1]=='-') p[n]*=(-1);
            n--;
        }
        //ei condition ta cholbe jodi x er kono coefficient na thakae ...
        //tokhon amra dhore nibo x er coefficient hocche 1....
        else if(s[i]=='x' && !(s[i-1]>='0'&&s[i-1]<='9'))
        {
            p[n]=1;
            if(s[i-1]=='-') p[n]*=(-1);
            n--;
        }
    }
}

float value(string &s, float x)
{
    float sum=0;
    float mul;
    int n2=n1;
    //value put kore solution ber kora hoise ...
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='x')
        {
            mul=x;
            if(s[i+1]=='^')
            {
                mul=pow(x,s[i+2]-'0');
            }
            sum+=p[n2]*mul,n2--;
        }
    }
    sum+=p[n2];
    return sum;
}



void solve()
{

    string s;
    cout<<"Enter the equation : "<<endl;
    cin>>s;
    cout<<"Guess the value of x1 and x2 : "<<endl;
    cin>>x1>>x2;
    cout<<"enter the value of stopping criteria e : "<<endl;
    cin>>e;

    int len=s.size();
    bisect(s,len);
    ///step 2
    float f1=value(s,x1);
    float f2=value(s,x2);
    // cout<<f1<<' '<<f2<<endl;

    /*
    Algorithm: Bisection method
    1.Decide initial values for x1 and x2 and stopping criterion E.
    2.Compute f1 = f (x1) and f2 = f (x2).
    3.If f1 * f2 > 0, x1 and x2 do not bracket any root and go to step 1.
    4.Compute x0 = (x1 + x2) / 2 and compute f0 = f (x0).
    5.If f1 * f0 < 0 then set x2 = x0 else set x1 = x0.
    6.If absolute value of (x2-x1) is less then E, then root = (x1 + x2) / 2 and go to step 7
    Else go to step 4
    7.Stop.
    */
    ///step 3
    if(f1*f2>0)
        cout<<"x1 ans x2 do not bracket any root\n";
    ///step 4
    else
    {
        cout<<endl;
        for(int pp=0; ; pp++)
        {
            float x0=(x1+x2)/2;
            float f0=value(s,x0);

            float f=f1*f0;
            ///step 5
            if(f<0)
                x2=x0;
            else
                x1=x0;

            ///jodi setprecision koto nibo oita user bole dey tokhon nicher ei process e hobe .....
            /*
            double x1 = ...;
            double x2 = ...;

            int n = ...;  // The number of decimal places specified by the user

            double factor = pow(10, n);
            x1 = round(x1 * factor) / factor;
            x2 = round(x2 * factor) / factor;
            */
///ekhane amra decimal er por 3 ghor rakhtesi...tai 1000 nisi ......
          //  x1 = round(x1 * 1000) / 1000;
          //  x2 = round(x2 * 1000) / 1000;
           // cout<<fixed<<setprecision(3);
            cout<<"new x1 and x2 are : "<<endl;
            cout<<fixed<<setprecision(3)<<x1<<endl;
            cout<<x2<<endl;


            //cout<<endl;
            float root=(x1*1.0+x2*1.0)/2.0;
            cout<<"new root is : ";
            cout<<root<<endl;
            ///step 6
            if(abs(x2-x1)<e)
            {
                cout<<"The abs(x2-x1) : "<<abs(x2-x1) <<" which is less than "<<e<<endl;
                cout<<" So,we meet the requirement .. so we need to stop here "<<endl;
                break;
            }
        }
    }
    cout<<endl;
    cout<<endl;
}

void test()
{
    long long t;
    cout<<"enter test case : "<<endl;
    cin>>t;

    while(t--)
    {
        //j++;
        solve();
    }

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int n = sizeof(arr) / sizeof(arr[0]);
    test();
    // solve();
}
/*

x^3-x-1



Algorithm: Bisection method
1.Decide initial values for x1 and x2 and stopping criterion E.
2.Compute f1 = f (x1) and f2 = f (x2).
3.If f1 * f2 > 0, x1 and x2 do not bracket any root and go to step 1.
4.Compute x0 = (x1 + x2) / 2 and compute f0 = f (x0).
5.If f1 * f0 < 0 then set x2 = x0 else set x1 = x0.
6.If absolute value of (x2-x1) is less then E, then root = (x1 + x2) / 2 and go to step 7
Else go to step 4
7.Stop.
*/


