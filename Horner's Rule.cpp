//horner's Rule
//time complexity O(n) ..
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<math.h>
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
ll Pow(ll c, ll d)
{
    return d == 0 ? 1 : c * pow(c, d - 1);
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return ((a * b) / gcd(a, b));
}
void fillPrefixSum(ll arr[], ll n, ll prefixSum[])
{
    prefixSum[0] = arr[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}
void solve()
{

    string s;
    cout<<"enter the polynomial equation: "<<endl;
    cin>>s;
    int i,j,k,m,n,x;
    cout<<"Enter the value of X : "<<endl;
    cin>>x;
    cout<<endl;
    //we used array p  to store the coefficient of x.. .. ...
    ll p[1000];
    //
    for(i=0; i<s.size(); i++)
    {
        //x er highest degree koto check kortesi then oitake amra n er moddhe store kortesi ..
        //   //x^3-4x^2+x+6 .....
        //ei example e highest degree 3 ...so n=3 ..n=n1=3 ..
        if(s[i]=='x')
        {
            n=s[i+2]-'0';
            //cout<<s[i+2]<<endl;
            //cout<<s[i+2]-'0'<<endl;
            //cout<<n<<endl;
            break;
        }
    }

    int n1=n;
    //prothom digit ta ki coefficient kina check korsi....
    if(s[0]>='0' && s[0]<='9')
    {
        p[n]=s[0]-'0';
        n--;
    }
    //prothom number ta jodi minus hoy porer ta ki coefficient kina check korsi ..
    //plus wala condition di nai karon kono kichur agae kichu nai mane oita positive dhora hoy auto ..like 7x .. 7 er agae plus ase oita mone mone dhora hoy ..
    else if(  (   s[0]=='-' &&  (s[1]>='0' && s[1]<='9')  )  )
    {
        //coefficient ta k negetive korar jonno -1 diye into kora hoise ....
        p[n]=(s[1]-'0')*(-1);
        n--;
    }
//loop ta chalano hoise coefficient gulo k alada kore array te store korar jonno ...
    for(i=0; i<s.size(); i++)
    {
        //ei condition ta cholbe jodi kono coefficient pai and ter ager value jodi - or + hoy .....
        if(s[i]>='0' && s[i]<='9'&& (s[i-1]=='-' || s[i-1]=='+'))
        {
            p[n]=s[i]-'0';
            if(i>0 && s[i-1]=='-')
                p[n]*=(-1);
            n--;
        }
        //ei condition ta cholbe jodi x er kono coefficient na thakae ...
        //tokhon amra dhore nibo x er coefficient hocche 1....
        else if(s[i]=='x' && !(s[i-1]>='0'&&s[i-1]<='9'))
        {
            p[n]=1;
            if(s[i-1]=='-')
                p[n]*=(-1);
            n--;
        }
    }

    cout<<"The coefficient part of all the terms are : ";
    for(i=n1; i>=0; i--)
        cout<<p[i]<<' ';

    cout<<endl;
    cout<<endl;
    //here sum holds the coefficient of x which contains the highest degree ..
    //x^3-4x^2+x+6 .....
    // for this example it is p3=a3=1 ...means sum=1 ......
    int sum=p[n1];

    cout<<"The value of P are  : "<<endl;
    cout<<"p["<<n1<<"] = "<<sum<<'\n';
    for(i=n1-1; i>=0; i--)
    {
        sum=sum*x+p[i];
        cout<<"p["<<i<<"] = "<<sum<<'\n';
    }

    int sum1=0;
    int mul;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='x')
        {
            mul=x;
            if(s[i+1]=='^')
            {
                mul=pow(x,s[i+2]-'0');
            }
            sum1+=p[n1]*mul,n1--;
        }
    }
    //shober last a constant number ta add kora hocche ...
    sum1+=p[n1];

    cout<<endl;
    cout<<"So,"<<endl;
    cout<<"f("<<x<<") = "<<sum1<<endl;

    if(sum==0)
        cout<<"So we can say that , for value of x = "<<x<<" the polynomial is satisfied ."<<endl;
    else
        cout<<"So we can say that , for value of x = "<<x<<" the polynomial is not satisfied ."<<endl;
    cout<<endl;
}
void test()
{
    long long t;
    cout<<"Enter number of test case :"<<endl;
    cin>>t;

    while(t--)
    {
        //j++;
        solve();
    }

}
/*
Bitwise Operators in C/C++
  & (bitwise AND)
  | (bitwise OR)
  ^ (bitwise XOR)
  << (left shift)
  >> (right shift)
  ~ (bitwise NOT)
*/
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int n = sizeof(arr) / sizeof(arr[0]);
    test();
    //solve();
}
/*
x^3-4x^2+x+6
2
*/
