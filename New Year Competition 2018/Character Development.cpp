#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	long n;
	scanf("%ld", &n);
	long long d = pow(2, n);
	d -= (n + 1);
	printf("%lld\n", d);
	return 0;
}