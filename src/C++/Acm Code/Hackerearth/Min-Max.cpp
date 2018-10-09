#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long a[100000 + 7], ma = 0, mi = 0;
	long n, i;
	scanf("%ld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", a + i);
	sort(a, a + n);
	for (i = 0; i < n - 1; i++)
		mi += a[i];
	ma = mi - a[0] + a[n - 1];
	printf("%lld %lld\n", mi, ma);
	return 0;
}