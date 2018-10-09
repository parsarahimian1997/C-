#include <iostream>
using namespace std;

int main()
{
	int t;
	long n, sum, m, a[100000 + 777];
	scanf("%d", &t);
	while (t--)
	{
		m = 10000;
		scanf("%ld", &n);
		for (int i = 0; i<n; i++)
			scanf("%ld", a + i);
		for (int i = 0; i<n; i++)
		{
			sum = 0;
			while (a[i])
			{
				if (a[i] & 1)
					sum++;
				a[i] >>= 1;
			}
			if (sum<m)
				m = sum;
		}
		printf("%ld\n", m);
	}
	return 0;
}