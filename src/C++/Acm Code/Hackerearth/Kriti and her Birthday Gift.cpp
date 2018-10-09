#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	long q, n, i, l, r;
	vector<long>::iterator low, high;
	map < string, vector <long>>s;
	string s1;
	scanf("%ld", &n);
	for (i = 1; i <= n; i++)
	{
		cin >> s1;
		s[s1].push_back(i);
	}
	scanf("%ld", &q);
	while (q--)
	{
		scanf("%ld %ld", &l, &r);
		cin >> s1;
		if (s[s1].size() > 0)
		{
			high = upper_bound(s[s1].begin(), s[s1].end(), r);
			low = lower_bound(s[s1].begin(), s[s1].end(), l);
			printf("%ld\n", high - low);
		}
		else
			printf("0\n");
	}
	return 0;
}