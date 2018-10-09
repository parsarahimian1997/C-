#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char a[100 + 20 + 7];
	int t, r, u, b, y, ruby;
	scanf("%d", &t);
	while (t--)
	{
		r = u = b = y = 0;
		scanf("%s", &a);
		for (int i = 0; a[i] != '\0'; i++)
			switch (a[i])
			{
			case 'r': r++; break;
			case 'u': u++; break;
			case 'b': b++; break;
			case 'y': y++; break;
			}
		ruby = min(min(min(b, y), u), r);
		printf("%d\n", ruby);
	}
	return 0;
}
