#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long a[10000777];

int main()
{
	unsigned long long n, m, sum = 0, x, y, z, s = 0, i, f = 0;
	cin >> m >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	sum -= m;
	x = sum%n;
	sum /= n;
	for (i = 0; a[i] <= sum; i++)
	{
		s += (sum - a[i]);
		f += a[i] * a[i];
	}
	n -= i;
	s += x;
	x = s%n;
	s /= n;
	z = sum + s;
	n -= x;
	y = z + 1;
	unsigned long long k = z*z*n;
	unsigned long long p = y*y*x;
	cout << f + p + k << endl;
	return 0;
}