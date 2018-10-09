#include <iostream>
#include <algorithm>
#define l long
using namespace std;
l a[1000000 + 127];

int main()
{
	l n, count = 0, d, j;
	scanf_s("%ld", &n);
	for (l i = 0; i < n; i++)
		scanf_s("%ld", a + i);
	sort(a, a + n);
	for (l i = 0; i < n; i++)
	{
		d = 1;
		while (a[i] == a[i + 1])
		{
			i++;
			d++;
		}
		if (d>count)
		{
			j = i;
			count = d;
		}
	}
	printf_s("%ld\n", a[j]);
	return 0;
}