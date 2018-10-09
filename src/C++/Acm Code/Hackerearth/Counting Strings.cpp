#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ll s, sum, i;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		s = 0;
		char a[1000000 + 7];
		scanf("%s", a);
		for (i = 0; a[i] != NULL; i++)
		{
			if (a[i] == 'a' || a[i] == 'z')
			{
				sum += s*(s + 1) / 2;
				s = 0;
				continue;
			}
			s++;
		}
		sum += s*(s + 1) / 2;
		printf("%lld\n", (i*(i + 1) / 2) - sum);
	}
	return 0;
}