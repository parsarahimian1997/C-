#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t, n, m, count;
	long long d;
	long long a[1000 + 70 + 7] = { 0 };
	char str[1000 + 10 + 7];
	string s[500 + 10 + 7];
	scanf("%d", &t);
	while (t--)
	{
		count = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			a[i] = a[i - 1] * 2 + s[i].size();
		}
		while (m--)
		{
			scanf("%lld", &d);
			for (int i = n; i >= 0; i--)
			{
				if (d >= 2 * a[i - 1])
				{
					str[count++] = s[i][d - 2 * a[i - 1]];
					break;
				}
				else if (d >= a[i - 1])
					d = 2 * a[i - 1] - d - 1;
			}
		}
		str[count] = '\0';
		printf("%s\n", str);
	}
	return 0;
}