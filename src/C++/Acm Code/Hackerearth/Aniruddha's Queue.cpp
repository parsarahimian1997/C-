#include <AP97.h>
#define l long

int main()
{
	int t;
	l n, *x, count;
	ll sum, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld", &n);
		x = new l[n];
		sum = 0;
		for (l i = 0; i < n; i++)
		{
			scanf("%ld", x + i);
			sum += x[i];
		}
		scanf("%lld", &m);
		m %= sum;
		if (m == 0)
		{
			for (l i = n - 1; i >= 0; i--)
				if (x[i] != 0)
				{
					count = i + 1;
					break;
				}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				m -= x[i];
				if (m <= 0)
				{
					count = i + 1;
					break;
				}
			}
		}
		printf("%ld\n", count);
	}
	return 0;
}