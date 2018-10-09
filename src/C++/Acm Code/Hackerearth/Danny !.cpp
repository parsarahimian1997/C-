#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long count(long long D, vector <long long>&a)
{
	long long ans = 0, n = a.size(), y, c;
	for (long long i = 0; i < n; i++)
	{
		vector <long long>::iterator it = lower_bound(a.begin(), a.end(), a[i] - D);
		int pos = (it - a.begin());
		ans += (i - pos);
	}
	return ans;
}

int main()
{
	long long n, k, i, low = 0, high = 1000000000 + 7, mid, x;
	scanf("%lld %lld", &n, &k);
	vector <long long>a;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	while (low < high)
	{
		mid = (low + high) / 2;
		if (count(mid, a) >= k)
			high = mid;
		else
			low = mid + 1;
	}
	printf("%lld\n", low);
	return 0;
}