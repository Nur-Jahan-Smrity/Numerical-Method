#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s1,s2,s,s3;
string s1last,s1rem,s2last,s2rem,s3last,s3rem;
int i,j,l,k,p[100],arr[100],brr[100],crr[100],p1,k1,p2,p3,n,n1,k2,k3;
float s1int=0,s2int=0,s3int=0;
int in1=0;

int main()
{


    cin>>s1>>s2>>s3;
    /*
    5x+2y+z=12
    x+4y+2z=15
    x+2y+5z=20
    */
    //x k ek pashe rekhe baki gula k shoracchie right side e.. tai sign gula o change hobe left theke right side e niye jawer shomoy ...
    for(i=0; i<s1.size(); i++)
    {
        if(s1[i]=='x')
        {
            p1=i;
            for(j=i+1; j<s1.size(); j++)
            {
                if(s1[j]=='=')
                {
                    k1=j;
                    for(l=j+1; l<s1.size(); l++)
                        s1last+=s1[l];
                    break;
                }
                else
                {
                    if(s1[j]=='+')
                        s1[j]='-';
                    else if(s1[j]=='-')
                        s1[j]='+';
                    s1rem+=s1[j];
                }
            }
            break;
        }
        //x pawer ag porjonto ja ja pabo ogula k s1int e rakhtesi ..string character k int e convert kortesi ...
        else
            s1int=s1int*10+(s1[i]-'0');
            //cout<<s1int<<endl;
    }
    //dividing by a number less than 1 can result in a larger quotient, and dividing by 0 is undefined. By setting s2int to its reciprocal when it is greater than or equal to 1, the code ensures that the denominator will always be greater than or equal to 1, which avoids these issues.
   //last e jai amader k s1 er khetre 5 diye divide , s2 er khetre 4 diye and s3 te 5 diye divide korte hoto ..
   // tai agae vagae alada kore s1int er moddhe s1 er ta divide kore rekhe dise ,,..pore only multiply korsi ...
    s1int=1/s1int;
   // cout<<s1int<<endl;
    s1=s1last+s1rem;
    cout<<s1<<endl;
    //p1=1
    //s2=  x+4y+2z=15
    //s er moddhe x k rakhsi..
    for(i=0; i<p1; i++)
        s+=s2[i];

    for(i=p1+1; i<s2.size(); i++)
    {
        if(s2[i]=='y')
        {
            p2=i;
            for(j=i+1; j<s2.size(); j++)
            {
                if(s2[j]=='=')
                {
                    k2=j;
                    for(int l=j+1; l<s2.size(); l++)
                        s2last+=s2[l];
                    break;
                }
                else
                {
                    if(s2[j]=='+')
                        s2[j]='-';
                    else if(s2[j]=='-')
                        s2[j]='+';
                    s2rem+=s2[j];
                }
            }
            break;
        }
        else
            s2int=s2int*10+(s2[i]-'0');
       // cout<<s2int<<endl;
    }
    if(s2int>=1)
        s2int=1/s2int;
   // cout<<s2int<<endl;
    s2=s2last+'-'+s+s2rem;
    cout<<s2<<endl;
    string ss;
    for(i=0; i<=p2; i++)
    {
        if(s3[i]=='+')
            s3[i]='-';
        else if(s3[i]=='-')
            s3[i]='+';
        ss+=s3[i];
    }
    for(i=p2+2; i<s3.size(); i++)
    {
        if(s3[i]=='z')
        {
            p3=i;
            for(j=i+1; j<s3.size(); j++)
            {
                if(s3[j]=='=')
                {
                    k3=j;
                    for(l=j+1; l<s3.size(); l++)
                        s3last+=s3[l];
                    break;
                }
                else
                {
                    if(s3[j]=='+')
                        s3[j]='-';
                    else if(s3[j]=='-') s3[j]='+';
                    s3rem+=s3[j];
                }
            }
            break;
        }
        else s3int=s3int*10+(s3[i]-'0');
       // cout<<s3int<<endl;
    }
    if(s3int>=1)
        s3int=1/s3int;
   // cout<<s3int<<endl;
    s3=s3last+'-'+ss+s3rem;
    cout<<s3<<endl;
    float x0=0, z0=0,y0=0,y1,x1, z1, e1, e2, e3,step=0,e=0.01,sresult=0;
    cout<<endl;
    ll sign=1;
    j=0;
    ll arr[100],brr[100],crr[100];
    for(i=0; i<s1.size(); i++)
    {
        sresult=0;
        sign=1;
        if(s1[i]>='0' && s1[i]<='9')
        {
            if(s1[i-1]=='-')
                sign=-1;
            while(s1[i]>='0' && s1[i]<='9')
            {
                sresult= sresult*10+(s1[i]-'0');
                i++;
            }
        }
        //mane kono coefficient nai .. tokhon dhore nibo 1 ase ...
        if(sresult==0)
        {
            sresult=1;
            if(s1[i]=='-')
                arr[j++]=sresult*(-1);
        }
        else
            arr[j++]=sresult*sign;
    }
    j=0;
    sign=1;
    sresult=0;
    for(i=0; i<s2.size(); i++)
    {
        sresult=0;
        sign=1;
        if(s2[i]>='0' && s2[i]<='9')
        {
            if(s2[i-1]=='-') sign=-1;
            while(s2[i]>='0' && s2[i]<='9')
            {
                sresult= sresult*10+(s2[i]-'0');
                i++;
            }
        }
        if(sresult==0)
        {
            sresult=1;
            if(s2[i]=='-') brr[j++]=sresult*(-1);
        }
        else   brr[j++]=sresult*sign;
    }
    j=0;
    sign=1;
    sresult=0;
    for(i=0; i<s3.size(); i++)
    {
        sresult=0;
        sign=1;
        if(s3[i]>='0' && s3[i]<='9')
        {
            if(s3[i-1]=='-') sign=-1;
            while(s3[i]>='0' && s3[i]<='9')
            {
                sresult= sresult*10+(s3[i]-'0');
                i++;
            }
        }
        if(sresult==0)
        {
            sresult=1;
            if(s3[i]=='-') crr[j++]=sresult*(-1);
        }
        else   crr[j++]=sresult*sign;
    }
    cout<<"removing the variable we get : "<<endl;
    for(i=0; i<3; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    for(i=0; i<3; i++)
        cout<<brr[i]<<' ';
    cout<<endl;
    for(i=0; i<3; i++)
        cout<<crr[i]<<' ';
    cout<<endl<<endl;
    do
    {
        // to prevent overflow or underflow
        x1 = (arr[0]+arr[1]*y0+arr[2]*z0)*s1int;
        y1 = (brr[0]+brr[1]*x0+brr[2]*z0)*s2int;
        z1 = (crr[0]+crr[1]*x0+crr[2]*y0)*s3int;
        cout<< step<<"\t"<< x1<<" |\t"<< y1<<" |\t"<< z1<< endl;
        e1 = fabs(x0-x1);
        e2 = fabs(y0-y1);
        e3 = fabs(z0-z1);
        step++;
        x0 = x1;
        y0 = y1;
        z0 = z1;
    }
    while(e1>e && e2>e && e3>e);

}
/*
5x+2y+z=12
x+4y+2z=15
x+2y+5z=20
*/
/*
12-2y-z
15-x-2z
20-x-2y

12 -2 -1
15 -1 -2
20 -1 -2

0       2.4 |   3.75 |  4
1       0.1 |   1.15 |  2.02
2       1.536 | 2.715 | 3.52
3       0.61 |  1.606 | 2.6068
4       1.23624 |       2.2941 |        3.2356
5       0.83524 |       1.82314 |       2.83511
6       1.10372 |       2.12363 |       3.1037
7       0.929807 |      1.92222 |       2.9298
8       1.04515 |       2.05265 |       3.04515
9       0.969911 |      1.96614 |       2.96991
10      1.01956 |       2.02257 |       3.01956
11      0.987061 |      1.98533 |       2.98706
12      1.00846 |       2.0097 |        3.00846
13      0.994427 |      1.99366 |       2.99443
14      1.00365 |       2.00418 |       3.00365
*/
