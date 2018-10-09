#include <iostream>
#include <string>
using namespace std;

int main()
{
	char *a;
	string s;
	long long *c, *d;
	long long b;
	int t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		cin >> s;
		b = s.length();
		a = new char[b + 35];
		d = new long long[b + 35];
		c = new long long[b + 35];
		for (int i = 0; i < b; i++)
			a[i] = s[i];
		a[b] = '\0';
		for (int i = 0; i < b; i++)
			d[i] = a[i];
		for (int i = 0; i < b; i++)
		{
			c[i] = d[i] + d[b - i - 1] - 96;
			if (c[i] > 122)			
				c[i] -= 26;
		}
		for (int i = 0; i < b; i++)
		{
			a[i] = c[i];
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}