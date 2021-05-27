#include <iostream>
using namespace std;
int main()
{
	double a,b=0,i,j,n;
	cin>>a;
	while(a!=0)
	{
		b=0;
		n=1;
		while(b<a){
			b+= ( 1/ (n+1) );
			n++;
		}
		cout<<n-1<<" "<<"card(s)"<<endl;
		cin>>a;
	}
	return 0;

}