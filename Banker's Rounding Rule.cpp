//bankers rounding rule ..

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
#define setafter fixed << setprecision
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

    ll n,k=0,i;
    string s;
    cout<<"enter string and number of sinificant bit"<<endl;
    cin>>s>>n;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]>'0' && s[i]<='9')
        {
            //first significant paisi ...
            k=i;
            break;
        }
    }
    //first significant number pawa porjonto print korsi
    if(k!=0)
    {
        for(i=0; i<k; i++)
            cout<<s[i];
        k=i;
        n=k+n-1;
    }
    if(s[n+1]<'5' && n<s.size())
    {
        for(i=k; i<n+1; i++)
            cout<<s[i];
    }
    else if(s[n+1]>'5' && n<s.size())
    {
        for(i=k; i<n+1; i++)
        {
            if(i==n)
            {
                cout<<(s[i]-'0')+1;
                break;
            }
            cout<<s[i];
        }
    }
    else if(s[n+1]=='5' && n<s.size())
    {
        int store=(s[n]-'0');
        if(store%2==0)
        {
            for(i=k; i<n+1; i++)
                cout<<s[i];
        }
        else
        {
            for(i=k; i<n+1; i++)
            {
                if(i==n)
                {
                    cout<<(s[i]-'0')+1;
                    break;
                }
                cout<<s[i];
            }
        }

    }
    cout<<endl;
}
void test()
{
    long long t;
    cout<<"enter test case :  "<<endl;
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

*/
