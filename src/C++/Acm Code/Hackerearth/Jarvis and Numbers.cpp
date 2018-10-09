#include <iostream>
using namespace std;
#define parsa(i,n) for (int i = 2; i < n; i++)
typedef long long ll;

ll factor(ll sum, ll d)
{
	if (d != 0)
		return factor(d, sum%d);
	else
		return sum;
}

int main()
{
	int t, n;
	ll sum, j, d;
	cin >> t;
	while (t--)
	{
		cin >> n;
		d = n - 2;
		sum = 0;
		parsa(i, n)
		{
			j = n;
			while (j)
			{
				sum += (j%i);
				j /= i;
			}
		}
		ll irreducible = factor(sum, d);
		cout << d / irreducible << endl;
	}
	return 0;
}