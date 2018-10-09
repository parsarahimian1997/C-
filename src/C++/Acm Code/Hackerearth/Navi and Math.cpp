#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;

int main()
{
	int t, n, k = 1;
	long a[20 + 7];
	unsigned long long mul, sum, p, max;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%ld", a + i);
				sort(a, a + n);
		reverse(a, a + n);
		mul = sum = a[0];
		max = 0;
		for (int i = 1; i < n; i++)
		{
			sum += a[i];
			mul *= a[i];
			p = (mul / sum);
			p %= mod;
			if (p >= max)
				max = p;
		}
		printf("Case #%d: %u\n", k++, max);
	}
	return 0;
}