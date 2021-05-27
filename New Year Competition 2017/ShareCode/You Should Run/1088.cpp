#include<iostream>
using namespace std;
#include<string>
int main()
{
 int i,n,j,a;
 string A;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  cin>>A;
  for(j=0;A[j]!='\0';j++){
  a=A[j];
  a++;
  if(a==91){a=65;}
  A[j]=a;}
  cout<<"String #"<<i<<endl<<A<<endl<<endl;
 }
 return 0;
}