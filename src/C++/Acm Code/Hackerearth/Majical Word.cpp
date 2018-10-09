#include <iostream>
#include <algorithm>
using namespace std;
bool prime[127 + 7];

void Prime_Number()
{
	for (int p = 2; p*p <= 130; p++)
		if (prime[p] == false)
			for (int i = p * 2; i <= 130; i += p)
				prime[i] = true;
}

int main()
{
	Prime_Number();
	fill(prime, prime + 64, true);
	char s[500 + 7];
	int n, t, d, d1, ma, j, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		scanf("%s", s);
		for (int i = 0; i < n; i++)
			if (prime[s[i]])
			{
				if (s[i] < 'A')
					s[i] = 'A';
				if (s[i] > 'z')
					s[i] = 'z';
				if (s[i] > 'Z' && s[i] < 'a')
				{
					if (s[i] - 'Z' < 'a' - s[i])
						s[i] = 'Z';
					else
						s[i] = 'a';
				}
				d = d1 = 0;
				if (s[i] >= 'a' && s[i] <= 'z')
				{
					k = j = s[i];
					while (prime[j])
					{
						if (j >= 'z')
						{
							d = 200;
							goto l1;
						}
						else
							j++;
						d++;
					}
				l1:
					while (prime[k])
					{
						if (k <= 'a')
						{
							d1 = 200;
							break;
						}
						else
							k--;
						d1++;
					}
				}
				else
				{
					k = j = s[i];
					while (prime[j])
					{
						if (j >= 'Z')
						{
							d = 200;
							goto l;
						}
						else
							j++;
						d++;
					}
				l:
					while (prime[k])
					{
						if (k <= 'A')
						{
							d1 = 200;
							break;
						}
						else
							k--;
						d1++;
					}
				}
				if (d == d1)
					s[i] = min(k, j);
				else if (d > d1)
					s[i] = k;
				else
					s[i] = j;
			}
		s[n] = '\0';
		printf("%s\n", s);
	}
	return 0;
}