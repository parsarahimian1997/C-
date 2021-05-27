#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	long i, j, k, n, a[1000], t;
	scanf("%ld", &t);
	while (t--)
	{
		scanf("%ld", &n);
		for (i = 0; i < n; i++)
			scanf("%ld", a + i);
		while (true)
		{
			sort(a, a + n);
			if (a[0] == a[n - 1])
			{
				printf("%ld\n", a[0]);
				break;
			}
			k = a[n - 1] - a[0];
			a[0] = a[n - 1] = k;
		}
	}
	return 0;
}