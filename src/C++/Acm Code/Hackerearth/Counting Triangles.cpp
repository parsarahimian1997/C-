#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000000] = {};

int main()
{
	long long i, j, k, n, b[3], s = 0, x;
	bool f;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> b[0] >> b[1] >> b[2];
		sort(b, b + 3);
		a[i] = b[0] * 100 + b[1] * 10 + b[2];
	}
	sort(a, a + n);
	x = a[0];
	for (i = 1; i < n; i++)
	{
		k = 0;
		while (x == a[i])
		{
			i++;
			k++;
		}
		if (k == 0)
			s++;
		x = a[i];
	}
	if (a[n - 1] != a[n - 2])
		s++;
	cout << s << endl;
	return 0;
}