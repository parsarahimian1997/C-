#include "stdafx.h"

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	long x, y, c;
	scanf_s("%ld %ld", &x, &y);
	if (y>x + 1)
		printf("No\n");
	else
	{
		c = y - 1;
		while (c<x)
			c += 2;
		if (c == x)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}