#include <iostream>
#include <cmath>
#include <string>
#define ll unsigned long long
using namespace std;

int main()
{
	string s;
	cin >> s;
	ll i, a, j, d = s.size();
	double b;
	if (d < 10)
	{
		i = 1;
		a = 1;
		while (1)
		{
			a *= i;
			if (a == stoi(s))
			{
				printf("%lld\n", i);
				break;
			}
			i++;
		}
	}
	else
	{
		j = 1;
		b = 1;
		while (1)
		{
			b += log10(j);
			if (floor(b) == d)
			{
				printf("%lld\n", j);
				break;
			}
			j++;
		}
	}
	return 0;
}