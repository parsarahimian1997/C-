#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long t, n, i, a[1000 + 7], b[1000 + 7], s1, s2;
	scanf_s("%ld", &t);
	while (t--)
	{
		s1 = s2 = 0;
		scanf_s("%ld", &n);
		for (i = 0; i<n; i++)
		{
			scanf_s("%ld", a + i);
			s1 += a[i];
		}
		for (i = 0; i<n; i++)
		{
			scanf_s("%ld", b + i);
			s2 += b[i];
		}
		if (s1 == s2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}