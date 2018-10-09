#include <iostream>
using namespace std;

int main()
{
	long t;
	long long n, count;
	scanf("%ld", &t);
	while (t--)
	{
		count = 0;
		scanf("%lld", &n);
		for (long i = 2; i < n; i *= 2)
		{
			for (long j = 1; j < i; j *= 2)
				if (i + j <= n)
					count = (count + i + j) % 1000000007;
		}
		printf("%lld\n", count % 1000000007);
	}
	return 0;
}