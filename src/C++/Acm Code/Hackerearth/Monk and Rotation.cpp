#include <iostream>
using namespace std;

int main()
{
	int t;
	long n, k, i, a[100000 + 7];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld %ld", &n, &k);
		k %= n;
		for (i = 0; i < n; i++)
			scanf("%ld", a + i);
		for (i = n - k; i < n; i++)
			cout << a[i] << " ";
		for (i = 0; i < n - k; i++)
			cout << a[i] << " ";
		printf("\n");
	}
	return 0;
}