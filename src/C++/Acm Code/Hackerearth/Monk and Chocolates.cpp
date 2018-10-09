#include <iostream>
#include <algorithm>
using namespace std;

int solve(char c, char *s, int n, int k)
{
	int m, l, r, count;
	for (l = count = r = 0; r < n; r++)
	{
		if (s[r] != c)
		{
			count++;
			if (count > k)
			{
				count--;
				while (s[l] == c)
					l++;
				l++;
			}
		}
		m = max(m, r - l);
	}
	return m;
}

int main()
{
	char s[100000 + 7];
	int t, n, k, i, sm, b, ma;
	scanf("%d", &t);
	while (t--)
	{
		ma = 0;
		scanf("%d %d %s", &n, &k, s);
		for (i = 0; i < 26; i++)
		{
			sm = solve('a' + i, s, n, k);
			b = solve('A' + i, s, n, k);
			ma = max(ma, max(sm, b) + 1);
		}
		printf("%d\n", ma);
	}
	return 0;
}