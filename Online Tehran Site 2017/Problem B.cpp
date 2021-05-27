#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	map<string, long>a, b;
	map<string, long>::iterator it;
	long t, n, m, i, k;
	scanf("%ld", &t);
	while (t--)
	{
		a.clear();
		b.clear();
		k = 0;
		scanf("%ld %ld", &n, &m);
		for (i = 0; i < n; i++)
		{
			cin >> s;
			a[s]++;
		}
		for (i = 0; i < m; i++)
		{
			cin >> s;
			b[s]++;
		}
		for (it = a.begin(); it != a.end(); it++)
		{
			s = it->first;
			k += min(a[s], b[s]);
		}
		printf("%ld\n", k);
	}
	return 0;
}