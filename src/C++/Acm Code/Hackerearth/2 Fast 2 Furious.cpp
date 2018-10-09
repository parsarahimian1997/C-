#include <iostream>
using namespace std;

int main()
{
	long n, preDom = 0, maxDom = 0, preBrian = 0, maxBrian = 0, i, current, diff;
	scanf("%ld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &current);
		diff = current - preDom;
		if (diff < 0)
			diff = -diff;
		if (diff > maxDom)
			maxDom = diff;
		preDom = current;
		current = 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &current);
		diff = current - preBrian;
		if (diff < 0)
			diff = -diff;
		if (diff > maxBrian)
			maxBrian = diff;
		preBrian = current;
		current = 0;
	}
	if (maxDom == maxBrian)
		printf("Tie\n%ld\n", maxBrian);
	else if (maxBrian > maxDom)
		printf("Brian\n%ld\n", maxBrian);
	else
		printf("Dom\n%ld\n", maxDom);
	return 0;
}