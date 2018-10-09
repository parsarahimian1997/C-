#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	char d;
	vector <int> p, t;
	long long n, k, i, j, out, te, l, r, sp, st;
	scanf("%lld", &te);
	while (te--)
	{
		out = 0;
		scanf("%lld %lld", &n, &k);
		if (k == n)
		{
			printf("0\n");
			continue;
		}
		for (i = 0; i < n; i++)
		{
			p.clear();
			t.clear();
			for (j = 0; j < n; j++)
			{
				cin >> d;
				assert(d == 'P' || d == 'T');
				if (d == 'P')
					p.push_back(j);
				else 
					t.push_back(j);
			}
			r = l = 0;
			sp = p.size();
			st = t.size();
			while (l < st && r < sp)
			{
				if (abs(t[l] - p[r]) <= k)
				{
					r++;
					l++;
					out++;
				}
				else if (t[l] < p[r])
					l++;
				else
					r++;
			}
		}
		printf("%lld\n", out);
	}
	return 0;
}