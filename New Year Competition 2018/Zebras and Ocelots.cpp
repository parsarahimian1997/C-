#include "stdafx.h"
#include <cstdio>
using namespace std;

int main()
{
	long n, t = 0;
	char c;
	scanf("%ld", &n);
	while (n--) 
	{
		getchar();
		c = getchar();
		t *= 2;
		if (c == 'O')
			t++;
	}
	printf("%ld\n", t);
	return 0;
}