#include <iostream>
#include <vector>
using namespace std;

int b[100000] = { 0 };

int main()
{
	vector <pair<int, int>> s;
	int n, q, c;
	scanf("%d %d", &n, &q);
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		s.push_back(make_pair(a[i], i));
	while (s.size() > 1)
	{
		vector <pair<int, int>> s1;
		for (int i = 0; i < s.size(); i += 2)
		{
			if (i + 1 == s.size())
			{
				s1.push_back(s[i]);
				continue;
			}
			b[s[i].second]++;
			b[s[i + 1].second]++;
			if (s[i].first > s[i + 1].first)
				s1.push_back(s[i]);
			else
				s1.push_back(s[i + 1]);
		}
		s = s1;
	}
	while (q--)
	{
		scanf("%d", &c);
		printf("%d\n", b[--c]);
	}
	return 0;
}