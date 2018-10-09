#include <iostream>
#include <algorithm>
using namespace std;

void jabejaii(int*a, int*b)
{
	if (*a > *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main()
{
	int a, b, x, y, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d %d", &a, &b, &x, &y);
		jabejaii(&a, &b);
		jabejaii(&x, &y);
		if (b < x || y < a)
			printf("Line\n");
		else if (a == y || b == x)
			printf("Point\n");
		else if (x >= a && x < b || a >= x && a < y)
		{
			if (a == b || x == y)
				printf("Point\n");
			else
				printf("Nothing\n");
		}
	}
	return 0;
}