#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	vector<pair<long long, long long> >f;
	long long i, j, n, t, a[100][100], sum;
	scanf("%lld", &t);
	while (t--)
	{
		sum = 0;
		vector<long long>v[100 + 7], s[100 + 7];
		scanf("%lld", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				scanf("%lld", &a[i][j]);
				s[j].push_back(a[i][j]);
				v[j].push_back(a[i][j]);
			}
		for (i = 0; i < n; i++)
			sort(v[i].begin(), v[i].end());
		for (i = 0; i < n; i++)
		{
			f.clear();
			if (s[i].empty())
				continue;
			for (j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				f.push_back(make_pair(s[i][j] - v[j][n - 1], j));
			}
			sort(f.begin(), f.end());
			j = f[f.size() - 1].second;
			sum += s[i][j];
			s[j].clear();
		}
		printf("%lld\n", sum);
	}
	return 0;
}