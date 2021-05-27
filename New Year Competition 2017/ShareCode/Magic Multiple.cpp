#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	bool flag, a[10];
	int d, k, i, j;
	char s[11];
	string s1;
	long long x, r;
	while (cin >> r)
	{
		k = 10;
		flag = false;
		memset(a, NULL, 10);
		for (j = 1; ; j++)
		{
			x = r*j;
			memset(s, NULL, 11);
			sprintf(s, "%lld", x);
			s1 = string(s);
			d = s1.size();
			for (i = 0; i < d; i++)
				if (!(a[s[i] - '0']))
				{
					a[s[i] - '0'] = true;
					k--;
					if (k == 0)
					{
						flag = true;
						break;
					}
				}
			if (flag)
				break;
		}
		cout << j << endl;
	}
	return 0;
}