#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long n, i, k;
	long long a = 0, al = 0, b = 0, bl = 0;
	scanf_s("%ld", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%ld", &k);
		a += k;
		al |= k;
	}
	for (i = 0; i < n; i++)
	{
		scanf_s("%ld", &k);
		b += k;
		bl |= k;
	}
	a -= al;
	b -= bl;
	if (a > b)
		printf("1 %lld\n", a - b);
	else
		printf("2 %lld\n", b - a);
}