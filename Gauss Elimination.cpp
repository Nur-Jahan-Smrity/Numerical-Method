#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#define   SIZE   10

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE], store;
	 int i,j,k,n;
	 char aa='x';


     cout<< setprecision(3)<< fixed;


	 cout<<"Enter number of unknowns: ";
	 cin>>n;


	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"a["<< i<<"]"<<"["<< j<<"]= ";
			   cin>>a[i][j];
		  }
	 }

	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   store = a[j][i]/a[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - store*a[i][k];
			   }
		  }
	 }

	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }


	 cout<< endl<<"Solution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	//cout<<"x["<< i<<"] = "<< x[i]<< endl;
	  	cout<<aa<<" = "<<x[i]<<endl;
	  	aa++;
	 }

	 return(0);
}
/*
3
a[1]1]= 2
a[1]2]= 1
a[1]3]= 1
a[1]4]= 10
a[2]1]= 3
a[2]2]= 2
a[2]3]= 3
a[2]4]= 18
a[3]1]= 1
a[3]2]= 4
a[3]3]= 9
a[3]4]= 16

3
2
1
1
10
3
2
3
18
1
4
9
16
*/
