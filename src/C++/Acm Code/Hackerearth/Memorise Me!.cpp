#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long n, q, i;
	int a[100000 + 7], b[100000 + 7] = { 0 }, x;
	scanf("%ld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		b[a[i]]++;
	}
	scanf("%ld", &q);
	while (q--)
	{
		scanf("%d", &x);
		if (b[x] == 0)
			printf("NOT PRESENT\n");
		else
			printf("%d\n", b[x]);
	}
	return 0;
}