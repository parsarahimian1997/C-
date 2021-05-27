#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

int main()
{
	map<ll, ll>ma;
	vector<ll>a, b;
	ll n, m, i, j, max = -1, maxindex = 0;
	scanf("%lld %lld", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &j);
		a.push_back(j);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%lld", &j);
		b.push_back(j);
	}
	for (auto i : a)
		for (auto j : b)
			if (j - i > 0)
				ma[j - i]++;
	for (auto i : ma)
	{
		if (i.second > max)
		{
			maxindex = i.first;
			max = i.second;
		}
		if (i.second == max)
			maxindex = min(maxindex, i.first);
	}
	printf("%lld\n", maxindex);
	return 0;
}