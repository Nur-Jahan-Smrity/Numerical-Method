#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#include <vector>
std::vector<float>m;
using namespace std;

int main()
{


    int A[3][3],k=0,B[3][3],C[3][3],i, j;
    float det = 0;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            cin>>A[i][j];
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            cin>>B[i][j];

    for(i = 0; i < 3; i++)
        det += (A[0][i] * (A[1][(i+1)%3] * A[2][(i+2)%3] - A[1][(i+2)%3] * A[2][(i+1)%3]));

    cout<<"determinant: "<<det<<endl;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            C[i][j]=((A[(j+1)%3][(i+1)%3] * A[(j+2)%3][(i+2)%3]) - (A[(j+1)%3][(i+2)%3] * A[(j+2)%3][(i+1)%3]));
    }

    for(i = 0; i < 3; i++)
    {

        for(j = 0; j < 1; j++)
        {
            float sum=0;
            for(int p=0; p<3; p++)
            {
                sum+=C[i][p]*B[p][j];
                // cout<<C[i][p]<<' '<<B[p][j]<<endl;
            }
            m.pb(sum/det);
        }
    }
    cout<<"x y z\n";
    for(i=0; i<3; i++)
        cout<<m[i]<<' ';
}

/*3 1 2
2 -3 -1
1 2 1
3 -3 4
*/
