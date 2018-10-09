#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long f[100000 + 7], a;
long x[100000 + 7], y[100000 + 7];

int main()
{
	double d;
	long k, n, i;
	scanf("%ld %ld", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%ld", x + i);
	for (i = 0; i < n; i++)
		scanf("%ld", y + i);
	for (i = 0; i < n; i++)
		f[i] = pow(x[i], 2) + pow(y[i], 2);
	sort(f, f + n);
	d = sqrt(f[k - 1]);
	a = sqrt(f[k - 1]);
	if (d > a)
		a += 1;
	printf("%ld\n", a);
	return 0;
}