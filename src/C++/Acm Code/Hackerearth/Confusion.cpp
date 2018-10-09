#include <iostream>
#include <algorithm>
using namespace std;
int a[10000 + 1997];

int main()
{
	int count;
	long n, q, x;
	scanf("%ld %ld", &n, &q);
	for (long i = 0; i < n; i++)
		scanf("%d", a + i);
	for (long i = 0; i < q; i++)
	{
		count = 1;
		scanf("%ld", &x);
		for (long j = x; j < n; j++)
		{
			if (a[j - 1] != a[j] && a[j - 1] != a[j + 1])
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}