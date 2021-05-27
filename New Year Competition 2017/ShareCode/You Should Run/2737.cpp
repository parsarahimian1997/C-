#include<iostream>
using namespace std;
int main()
{
	int i,j,m,n,t,k,e;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		int sum=0,f=0;
		cin>>m>>n;
		for(i=m-1;i>=0;i--)
		{
			e=f;
			for(j=n-1;j>=0;j--)
			{
				sum+=e;
				e++;
			}
			f++;
		}
		cout<<sum<<endl;
	}
return 0;
}