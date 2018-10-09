#include <iostream>
using namespace std;

int main()
{
	int n, m, k, x, a[100 + 7][100 + 7], c[100 + 7][100 + 7] = { 0 };
	scanf("%d %d %d %d", &n, &m, &k, &x);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == x)
				c[i][j] = 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c[i][j] = c[i][j] + c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
	int s, d, f, g, counter = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int z = i + 1; z <= n; z++)
				for (int v = j + 1; v <= m; v++)
				{
					int b = c[z][v] + c[i - 1][j - 1] - c[i - 1][v] - c[z][j - 1];
					if (b < k)continue;
					s = a[i][j];
					d = a[z][v];
					f = a[i][v];
					g = a[z][j];
					if (s == d || s == f || s == g || d == f || d == g || f == g)
						counter++;
				}
	printf("%d\n", counter);
	return 0;
}