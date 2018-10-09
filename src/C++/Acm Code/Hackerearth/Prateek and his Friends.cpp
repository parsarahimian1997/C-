#include <AP97.h>

int main()
{
	int t;
	long n, j;
	long long spend, sum;
	scanf("%d", &t);
	while (t--)
	{
		bool flag = false;
		scanf("%ld %lld", &n, &spend);
		long *cost = new long[n];
		for (long i = 0; i < n; i++)
			scanf("%ld", cost + i);
		for (long i = 0; i < n; i++)
		{
			j = i;
			sum = 0;
			while (sum < spend && j < n )
			{
				sum += cost[j];
				j++;
			}
			if (sum == spend)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
}