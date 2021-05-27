#include<iostream>
using namespace std;
#include<string>
int main(){
	int a,w,s,i;
	while(cin>>a>>w>>s)
	{
		int f=0;
		string p[3]={"0","0","0"};
		if(a==0 && w==0 && s==0)
			break;
		if(a<=30 && w>=70 && s>=500)
			p[0]="Mid-field";
		if(a<=26 && w>=60 && s>=200)
			p[1]="Forward";
		if(a<=36 && w>=80 && s>=300)
			p[2]="Defense";
		if(p[0]!="0")
			cout<<p[0];
		if(p[1]!="0" && p[0]!="0")
			cout<<" "<<p[1];
		else if(p[1]!="0" && p[0]=="0")
			cout<<p[1];
		if(p[2]!="0"){
			if(p[1]!="0")
				cout<<" "<<p[2];
			else if(p[1]=="0" && p[0]!="0")
				cout<<" "<<p[2];
			else if(p[1]=="0" && p[0]=="0")
				cout<<p[2];
		}
		if(p[0]=="0" && p[1]=="0" && p[2]=="0")
			cout<<"No positions";
		cout<<endl;
	}
	return 0;
}