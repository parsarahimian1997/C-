#include <iostream>
using namespace std;

int b[1000000 + 7000 + 700 + 70 + 7], f, x;

int main()
{
	long n, q, l, r;
	scanf("%ld %ld", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	while (q--)
	{
		scanf("%ld", &x);
		if (x == 1)
		{
			scanf("%d", &f);
			if (b[f] == 0)
				b[f] = 1;
			else
				b[f] = 0;
		}
		else
		{
			scanf("%ld %ld", &l, &r);
			if (b[r] == 1)
				printf("ODD\n");
			else
				printf("EVEN\n");
		}
	}
	return 0;
}