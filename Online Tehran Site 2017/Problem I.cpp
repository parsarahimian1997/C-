#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	bool flag;
	vector<long>d;
	vector<pair<long, pair<long, long> > >a;
	long n, m, k, t, i, x, y, j, f;
	scanf("%ld", &t);
	while (t--)
	{
		a.clear();
		d.clear();
		scanf("%ld %ld %ld", &n, &k, &m);
		for (i = 0; i < m; i++)
		{
			scanf("%ld %ld", &x, &y);
			a.push_back(make_pair(y - x + 1, make_pair(x, y)));
		}
		sort(a.begin(), a.end());
		for (i = m - 1; i > 0; i--)
		{
			flag = false;
			j = i;
			f = 1;
			while (a[i].second.first <= a[j - 1].second.first && a[i].second.second >= a[j - 1].second.second)
			{
				f++;
				if (f == k)
				{
					flag = true;
					break;
				}
				j--;
				if (j == 0)
					break;
			}
			if (flag)
				break;
		}
		printf("%ld\n", a[i].first);
		for (j = a[i].second.first; j != a[i].second.second; j++)
			printf("%ld ", j);
		printf("%ld\n", j);
	}
	return 0;
}