#include<iostream>
#include<algorithm>
#define lo long long
#define mod 1000000007
using namespace std;

lo v[100000 + 1];
bool prime[100000 + 10];
int np[100000 + 10];
int p = 100000 + 10;

void notprime()
{
	for (lo i = 2; i * i <= p; i++)
		if (!prime[i])
			for (lo j = i * i; j <= p; j += i)
				prime[j] = 1;
	for (int i = 2; i <= p; i++)
		np[i] += np[i - 1] + !prime[i];
}

int main()
{
	long long t, n, m, d = 1;
	notprime();
	cin >> t;
	while (t--)
	{
		d = 1;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v, v + n);
		reverse(v, v + n);
		for (int i = 0; i < n; i++)
		{
			long long s = np[m] - np[v[i] - 1];
			long long w = m - v[i] + 1 - s - i;
			if (w < 0)
			{
				d = 0;
				break;
			}
			d = (d * w) % mod;
		}
		cout << d << endl;
	}
	return 0;
}