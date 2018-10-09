#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long max = 0, count = 0, si;
	string s, s1, s2;
	cin >> s;
	si = s.size();
	for (int i = 0; i < si - 1; i++)
	{
		for (int j = (si - i) / 2; j > i; j--)
		{
			s1 = s.substr(i, j - i);
			s2 = s.substr(j, j - i);
			if (s2 == s1)
			{
				count = s1.size();
				break;
			}
			if (count >= max)
				max = count;
		}
	}
	printf("%lld\n", max);
	return 0;
}