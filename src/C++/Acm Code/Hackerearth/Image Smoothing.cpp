#include <iostream>
using namespace std;

int main()
{
	int g[128 + 28][128 + 28] = { 0 }, f[30 + 7][30 + 7] = { 0 }, i, j, n, m, x, y;
	long s;
	scanf("%d %d", &n, &m);
	for (i = 0; i < (2 * m + 1); i++)
		for (j = 0; j < (2 * m + 1); j++)
			scanf("%d", &f[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			s = 0;
			for (x = -1 * m; x <= m; x++)
				for (y = -1 * m; y <= m; y++)
				{
					if (i + x < 0 || j + y < 0)
						continue;
					s += g[i + x][j + y] * f[x + m][y + m];
				}
			printf("%ld ", s);
		}
		printf("\n");
	}
	return 0;
}