#include <iostream>
using namespace std;

int main()
{
	long n, x, i, count = 0, d = 0, a[100000 + 7];
	scanf("%ld %ld", &n, &x);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", a + i);
		if (a[i] <= x)
			count++;
		else if (d == 0)
			d++;
		else
			break;
	}
	for (i; i < n; i++)
		scanf("%ld", a + i);
	printf("%ld\n", count);
	return 0;
}