#include <iostream>
using namespace std;

int main()
{
	long long t, n, x;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		if (n % 2 == 0)
			printf("%lld\n", ++n);
		else
		{
			x = (((n + 1) ^ n)&(n + 1));
			printf("%lld\n", n + x);
		}
	}
	return 0;
}