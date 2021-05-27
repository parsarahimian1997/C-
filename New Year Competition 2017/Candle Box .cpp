#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	long long r, t;
	scanf("%d %d %d", &a, &b, &c);
	for (int j = a; j <= 4000; j++)
	{
		r = 0, t = 0;
		for (int i = 4; i <= j; i++)
			r += i;
		for (int i = 3; i <= j - a; i++)
			t += i;
		if (b - r == t - c)
		{
			printf("%d\n", b - r);
			return 0;
		}
	}
	return 0;
}