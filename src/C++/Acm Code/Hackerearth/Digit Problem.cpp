#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long x, l, v, c, p = 0;
	int k, j = 0, m = 0, b = 0, y = 0, h;
	cin >> x >> k;
	long long d = x;
	while (d != 0)
	{
		j++;
		d /= 10;
	}
L:long long *s = new long long[k];
	l = (pow(10, j - k));
	c = x / l;
	for (int i = 1; i <= k; i++)
	{
		s[i - 1] = c % 10;
		if (s[i - 1] == 9)
			m++;
		c /= 10;
	}
	if (y == m)
		goto l1;
	m = m - y;
	h = 0;
	delete[]s;
	while (m != 0)
	{
		l /= 10;
		m--;
		y++;
		k++;
		h++;
	}
	if (h != 0)
		goto L;
l1:v = x % l;
	s = new long long[k];
	for (int i = (k - 1); i >= 0; i--)
	{
		s[i] = 9;
		s[i] *= (pow(10, i));
		p += s[i];
	}
	delete[]s;
	p *= l;
	p += v;
	cout << p << endl;
}