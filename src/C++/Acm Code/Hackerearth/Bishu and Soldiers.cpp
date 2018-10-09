#include <iostream>
#include <algorithm>
using namespace std;
long long a[10000 + 7], c[10000 + 7];

long long binarySearch(long long low, long long high, long long key)
{
	if (key > high)
		return high;
	long long mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == key)
		{
			low = mid + 1;
			mid++;
		}
		else if (a[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return mid;
}

int main()
{
	long long n, q, x, i, k;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", a + i);
	sort(a, a + n);
	c[0] = a[0];
	for (i = 1; i < n; i++)
		c[i] = c[i - 1] + a[i];
	scanf("%lld", &q);
	while (q--)
	{
		scanf("%lld", &x);
		if (a[n - 1] < x)
		{
			printf("%lld %lld\n", n, c[n - 1]);
			continue;
		}
		k = binarySearch(0, n, x);
		printf("%lld %lld\n", k, c[k - 1]);
	}
	return 0;
}