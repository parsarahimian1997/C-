#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int as, ae, asp, bs, bsp;
	scanf("%d %d %d %d %d", &as, &ae, &asp, &bs, &bsp);
	printf("%d\n", (int)((ae - as) * asp / (double)bsp + bs) + 1);
	return 0;
}