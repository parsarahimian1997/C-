#include <iostream>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
LL c[100000 + 127];
LL t[100000 + 127];
LL d[100000 + 127];


int main()
{
	LL n, sum = 0, time = 0;
	cin >> n;
	for (LL i = 1; i < n; i++)
		cin >> c[i];
	for (LL i = 0; i < n; i++)
		cin >> t[i];
	for (LL i = 0; i < n;)
	{
		i++;
		time++;
		sum += c[i];
		if (i == 1)
			d[i] = c[i];
		else
			d[i] = min(d[i - 1], c[i]);
		while (t[i] - time > 0)
		{
			sum += d[i] * 2;
			time += 2;
		}
	}
	cout << sum << endl;
	return 0;
}