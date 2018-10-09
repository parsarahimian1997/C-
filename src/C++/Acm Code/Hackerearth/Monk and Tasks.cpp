#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
	int t;
	long n;
	long long x;
	bitset<64> bit;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld", &n);
		vector< pair<int, pair<long, long long>>> a;
		for (long i = 0; i < n; i++)
		{
			scanf("%lld", &x);
			bit = x;
			a.push_back(make_pair(bit.count(), make_pair(i, x)));
		}
		sort(a.begin(), a.end());
		for (long i = 0; i < n; i++)
			printf("%lld ", a[i].second.second);
		printf("\n");
	}
	return 0;
}