#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int q, n, x, a, b, t, p[10000 + 77], time[10000 + 77], i, count;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &n);
		memset(time, 0, n + 77);
		for (i = 0; i < n; i++)
			scanf("%d", p + i);
		scanf("%d %d %d %d", &x, &a, &b, &t);
		count = 0;
		i = 1;
		while (i <= t)
		{
			time[x]++;
			if (time[x] >= p[x])
			{
				count++;
				time[x] = 0;
			}
			x = (x*a + b) % n;
			i++;
		}
		printf("%d\n", count);
	}
	return 0;
}