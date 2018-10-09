#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <pair<long, int>> a;
	string s;
	int n, k, m;
	for (int i = 0; i <= 30; i++)
		a.push_back(make_pair(0, i));
	scanf("%d", &n);
	while (n--)
	{
		getline(cin >> ws, s);
		k = s.length();
		if (s[0] == 'G')
		{
			for (int i = 3; i < k;)
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					if (s[i + 1] >= '0' && s[i + 1] <= '9')
					{
						m = ((s[i] - '0') * 10) + (s[i + 1] - '0');
						a[m].first += 2;
						i += 2;
						continue;
					}
					a[s[i] - '0'].first += 2;
					i += 2;
					continue;
				}
				i++;
			}
		}
		else
		{
			for (int i = 3; i < k; )
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					if (s[i + 1] >= '0' && s[i + 1] <= '9')
					{
						m = ((s[i] - '0') * 10) + (s[i + 1] - '0');
						a[m].first++;
						i += 2;
						continue;
					}
					a[s[i] - '0'].first++;
					i += 2;
					continue;
				}
				i++;
			}
		}
	}
	sort(a.begin(), a.end());
	if (a[30].second == 19 || a[30].second == 20)
		cout << "Date" << endl;
	else
		cout << "No Date" << endl;
	return 0;
}