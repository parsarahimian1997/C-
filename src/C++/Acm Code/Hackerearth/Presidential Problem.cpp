#include <cstdio>
#include <cstring>
#define p 21007
using namespace std;

int main()
{
	char c[p];
	int d[p];
	int t, n, q, r, l, f;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &q);
		scanf("%s", c);
		memset(d, 0, sizeof(d));
		while (q--)
		{
			scanf("%d %d", &l, &r);
			--d[l - 1];
			++d[r];
		}
		f = 0;
		for (int i = 0; i < n; ++i)
		{
			f += d[i];
			int convert = f + c[i] - 97;
			convert %= 26;
			if (convert < 0)
				convert += 26;
			c[i] = convert + 97;
		}
		printf("%.*s\n", n, c);
	}
	return 0;
}