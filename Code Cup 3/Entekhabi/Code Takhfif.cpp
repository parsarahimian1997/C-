#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector <char>a, b;
	int n, Lt, si, d, count = 0, si1;
	bool flag;
	string s, s1;
	cin >> n >> s;
	si = s.size();
	sort(s.begin(), s.end());
	a.push_back(s[0]);
	for (int i = 1; i < si; i++)
		if (a[count] != s[i])
		{
			a.push_back(s[i]);
			count++;
		}
	d = a.size();
	while(n--)
	{
		count = 0;
		flag = true;
		cin >> s1;
		si1 = s1.size();
		sort(s1.begin(), s1.end());
		b.push_back(s1[0]);
		for (int i = 1; i < si1; i++)
			if (b[count] != s1[i])
			{
				b.push_back(s1[i]);
				count++;
			}
		if (a.size() != b.size())
			cout << "No" << endl;
		else
		{
			for (int i = 0; i < d; i++)
				if (a[i] != b[i])
				{
					flag = false;
					cout << "No" << endl;
					break;
				}
			if(flag)
				cout << "Yes" << endl;
		}
		b.clear();
	}
	return 0;
}