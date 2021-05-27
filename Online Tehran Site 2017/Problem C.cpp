#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	long long b, c;
	vector<long>a;
	long t, n, i, j, k;
	scanf("%ld", &t);
	while (t--)
	{
		a.clear();
		b = c = 0;
		scanf("%ld", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%ld %ld", &j, &k);
			b += j;
			c += k;
			a.push_back(j - k);
		}
		if (b < c)
			printf("it's a trap\n");
		else
			for (i = 0; i < n; i++)
			{
				k = n;
				b = c = false;
				for (j = i; j < k; j++)
				{
					b += a[j];
					if (b < 0)
						break;
					else if (j == k - 1 && !c)
					{
						c = true;
						j = -1;
						k = i;
					}
				}
				if (b >= 0)
				{
					printf("%ld\n", i);
					break;
				}
			}
	}
	return 0;
}