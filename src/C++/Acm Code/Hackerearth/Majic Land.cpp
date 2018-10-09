#include <iostream>
#include <algorithm>
using namespace std;

int a[1000 + 170 + 7][1000 + 170 + 7];

int main()
{
	int m, n, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		int r = 1, c = 1, count, flag = 0;
		for (int i = 0; i < n; i++)
		{
			flag = a[i][0];
			count = 0;
			for (int j = 0; j < m; j++)
			{
				if (flag == a[i][j])
				{
					count++;
					r = max(count, r);
				}
				else
				{
					r = max(count, r);
					count = 1;
					flag = a[i][j];
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			flag = a[0][i];
			count = 0;
			for (int j = 0; j < n; j++)
			{
				if (flag == a[j][i])
				{
					count++;
					c = max(count, c);
				}
				else
				{
					{
						c = max(count, c);
						count = 1;
						flag = a[j][i];
					}
				}
			}
		}
		printf("%lld\n", r*c);
	}
	return 0;
}