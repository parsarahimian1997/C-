#include <iostream>
#define ll long long
using namespace std;

int main()
{
	long long n, r, s, d;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ll *x = new ll[n];
		ll *y = new ll[n];
		for (ll i = 0; i < n; i++)
		{
			cin >> x[i];
			r = x[i];
			if (r == 0)
				d = 6;
			while (r > 0)
			{
				s = r % 10;
				switch (s)
				{
				case 0: d += 6; break;
				case 1: d += 2; break;
				case 2: d += 5; break;
				case 3: d += 5; break;
				case 4: d += 4; break;
				case 5: d += 5; break;
				case 6: d += 6; break;
				case 7: d += 3; break;
				case 8: d += 7; break;
				case 9: d += 6; break;
				}
				r /= 10;
			}
			y[i] = d;
			d = 0;
		}
		for (ll i = 0; i < n; i++)
		{
			r = y[i];
			ll j = 0;
			for (;r <= y[j];)
			{
				j++;
				if (j == n)
				{
					cout << x[i] << endl;
					break;
				}
			}
			if (j == n)
				break;
		}
	}
	return 0;
}