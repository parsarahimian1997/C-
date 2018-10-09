#include <iostream>
using namespace std;

int main()
{
	long t, n, m, counter;
	scanf("%ld", &t);
	while (t--)
	{
		counter = 0;
		scanf("%ld %ld", &n, &m);
		while (n / 2 != 0 || m / 2 != 0)
		{
			if (n % 2 != m % 2)
				counter++;
			n /= 2;
			m /= 2;
		}
		if (n % 2 != m % 2)
			counter++;
		printf("%ld\n", counter);
	}
	return 0;
}