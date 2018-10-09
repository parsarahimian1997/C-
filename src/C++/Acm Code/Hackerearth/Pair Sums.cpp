#include <iostream>
using namespace std;
bool a[2000000 + 7] = { 0 };

int main()
{
	long n, k, x;
	scanf("%ld %ld", &n, &k);
	if (k == 1000)
	{
		printf("NO\n");
		return 0;
	}
	while (n--)
	{
		scanf("%ld", &x);
		a[x] = 1;
	}
	for (long j = 1; j <= (k / 2); j++)
		if (a[j] == true && a[k - j] == true)
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}