#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[100000 + 7];
	int t, sum;
	long n;
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		scanf("%ld", &n);
		scanf("%s", s);
		for (int i = 0; i<strlen(s); i++)
			if (s[i] == '1')
				sum++;
		printf("%d\n", sum);
	}
	return 0;
}