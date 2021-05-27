#include "stdafx.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a1, a2, i, si;
	a1 = a2 = 0;
	char s[15000 + 7], s1[7700 + 7], s2[7700 + 7], st[7700 + 7];
	scanf("%s", s);
	si = strlen(s);
	for (i = 0; i < si / 2; i++)
		a1 += s[i];
	for (; i < strlen(s); i++)
		a2 += s[i];
	for (i = 0; i < si; i++)
	{
		if (i >= si / 2)
			s2[i - si / 2] = (s[i] + a2) % 26;
		else
			s1[i] = (s[i] + a1) % 26;
	}
	for (i = 0; i < si / 2; i++)
	{
		st[i] = (s1[i] + s2[i]) % 26;
		st[i] += 'A';
	}
	st[i] = '\n';
	printf("%s", st);
	return 0;
}