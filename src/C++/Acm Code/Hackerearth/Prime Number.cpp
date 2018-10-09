#include <iostream>
using namespace std;

void prime(bool b[], int n)
{
	b[2] = true;
	b[3] = true;
	for (int i = 4; i < n+1;)
	{
		if (i % 2 != 0)
		{
			for (int j = 3; j*j <= i; j += 2)
				if (i % j == 0)
					goto l;
			b[i] = true;
		}
	l:i++;
	}
}

int main()
{
	bool b[1000 + 7] = { false };
	int n;
	scanf("%d", &n);
	prime(b, n);
	for (int i = 0; i < n; i++)
		if (b[i]==true)
			printf("%d ", i);
	printf("\n");
}