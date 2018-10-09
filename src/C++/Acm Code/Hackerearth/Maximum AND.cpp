#include <iostream>
using namespace std;

int main()
{
	long long a, b, max, temp;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		max = 0;
		scanf("%lld %lld", &a, &b);
		if (b % 2 == 0)
			max = b - 2;
		else
			max = b - 1;
		if (max<a)
			max = (a&b);
		printf("%lld\n", max);
	}
	return 0;
}