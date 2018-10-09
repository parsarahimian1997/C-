#include <iostream>
#define n 67
#define m 207
using namespace std;
long long a[n][n * m];
long long b[n][m];

int main()
{
	int c, d;
	long long f, mod = 1000000000 + 7;
	for (int k = 1; k < m; k++) 
	{
		a[0][0] = 1;
		for (int i = 1; i < n; i++)
		{
			long long sum = 0;
			for (int j = 0; j <= k * i; j++)
			{
				sum = (sum + a[i - 1][j]) % mod;
				a[i][j] = sum;
				if (j >= k)
					sum = (sum + mod - a[i - 1][j - k]) % mod;
			}
			b[i][k] = 0;
			for (int j = 0; j <= k; j++)
				b[i][k] = (b[i][k] + a[i][j * i]) % mod;
		}
	}
	scanf_s("%d %d", &c, &d);
	while (c && d) 
	{
		f = (b[c - 1][d] * c) % mod;
		if (f < 0)
			f += mod;
		printf("%lld\n", f);
		scanf_s("%d %d", &c, &d);
	}
	return 0;
}