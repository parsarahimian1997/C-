#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector <long>a, b;
	int t;
	long n, i;
	long long x, y, ma, f, ff;
	scanf_s("%d", &t);
	while (t--)
	{
		a.clear();
		b.clear();
		scanf_s("%ld", &n);
		for (i = 0; i<n; i++)
		{
			scanf_s("%lld %lld", &x, &y);
			a.push_back(x);
			b.push_back(y);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		f = a[n - 1] - a[0];
		ff = b[n - 1] - b[0];
		ma = max(f, ff);
		printf("%lld\n", ma*ma);
	}
	return 0;
}