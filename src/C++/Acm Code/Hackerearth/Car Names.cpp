#include <iostream>
using namespace std;

int main()
{
	int n, k;

	scanf("%d", &n);
	while (n--)
	{
		char s[4];
		int b[4] = { 0 };
		k = 0;
		char a[500];
		a[500] = '\0';
		scanf("%s", a);
		s[k] = a[k];
		b[k]++;
		for (int i = 1; a[i] != '\0'; i++)
		{
			if (a[i] == a[i - 1])
				b[k]++;
			else
			{
				bool flag = false;
				for (int j = 0; j<k; j++)
				{
					if (s[j] == a[i])
					{
						b[j]++;
						flag = true;
						break;
					}
				}
				if (flag == false)
				{
					s[++k] = a[i];
					b[k]++;
				}
				if (k == 3)
				{
					printf("Not OK\n");
					break;
				}
			}
		}
		if (k != 3)
		{
			if (b[0] == b[1] && b[1] == b[2])
				printf("OK\n");
			else
				printf("Not OK\n");
		}
	}
	return 0;
}