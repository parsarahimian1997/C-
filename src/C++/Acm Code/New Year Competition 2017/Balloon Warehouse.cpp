#include <iostream>
#include <vector>
#include <algorithm>
#define m 1000007
using namespace std;

vector<pair<int, int>> vi[m];
vector<int> v;

void operation(int s, int t)
{
	for (auto k : vi[s])
	{
		if (k.second <= t)
			break;
		v.push_back(k.first);
		if (v.size() > m)
			break;
		operation(k.first, k.second);
	}
}

int main() 
{
	int n, a, b, x, y;
	scanf_s("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) 
	{
		scanf_s("%d %d", &x, &y);
		vi[x].emplace_back(y, i);
	}
	for (int i = 0; i < m; i++)
		reverse(vi[i].begin(), vi[i].end());
	v.push_back(0);
	operation(0, -1);
	for (int i = a; i < b; i++) 
		printf("%d ", v[i % v.size()]);
	printf("\n");
	return 0;
}