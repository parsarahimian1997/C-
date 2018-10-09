#include <iostream>
#include <cmath>
using namespace std;
long long high, low, sub, mid, s;

long long g(long long A, long long B)
{
	if (A == 0)
		return B;
	return g(B%A, A);
}

long long solve(long long a, long long b, long long n)
{
	low = 0;
	high = pow(10, 17) + 7;
	long long gcd = (a*b) / (g(a, b));
	while (low <= high)
	{
		mid = (low + high) / 2;
		sub = (mid / a) + (mid / b) - (mid / gcd);
		if (sub < n)
			low = mid + 1;
		else
		{
			s = mid;
			high = mid - 1;
		}
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long a, b, n;
		scanf("%lld %lld %lld", &a, &b, &n);
		printf("%lld\n", solve(a, b, n));
	}
}