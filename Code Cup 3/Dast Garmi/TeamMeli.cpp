#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d[7][7], s[100 + 7] = { 0 }, x = 0, y = 0, z = 0;
	long long price = 0;
	scanf("%d %d %d", &a, &b, &c);
	b *= 2;
	c *= 3;
	int i;
	for (i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &d[i][j]);
	for (i = d[0][0]; i < d[0][1]; i++)
		s[i]++;
	for (i = d[1][0]; i < d[1][1]; i++)
		s[i]++;
	for (i = d[2][0]; i < d[2][1]; i++)
		s[i]++;
	for (i = 0; i < 100; i++)
	{
		if (s[i] == 1)
			x++;
		if (s[i] == 2)
			y++;
		if (s[i] == 3)
			z++;
	}
	price += (x*a) + (y*b) + (z*c);
	printf("%lld\n", price);
	return 0;
}