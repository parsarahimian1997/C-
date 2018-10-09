#include <iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	int x, y, a, b;
	unsigned char r, s;
	while (t--)
	{
		cin >> r >> s;
		x = r - 96;
		y = s - 96;
		cin >> r >> s;
		a = r - 96;
		b = s - 96;
		if (((x + y) % 2 == 0 && (a + b) % 2 == 0) || ((x + y) % 2 != 0 && (a + b) % 2 != 0))
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}