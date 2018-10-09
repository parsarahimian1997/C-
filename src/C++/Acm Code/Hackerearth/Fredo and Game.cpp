#include <iostream>
using namespace std;

int main()
{
	bool flag;
	bool a[100000 + 7];
	int t;
	long m, n, i;
	scanf("%d", &t);
	while (t--)
	{
		flag = false;
		scanf("%ld %ld", &m, &n);
		for (i = 0; i < n; i++)
			scanf("%d", a + i);
		for (i = 0; i < n; i++)
		{
			if (m == 0)
			{
				flag = true;
				break;
			}
			if (a[i] == 1)
				m += 2;
			else
				m--;
		}
		if (flag)
			printf("No %ld\n", i);
		else
			printf("Yes %ld\n", m);
	}
	return 0;
}