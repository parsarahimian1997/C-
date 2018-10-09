#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	long t, n, a[100000 + 7], d, m = 0;
	stack <long> q;
	scanf("%ld", &t);
	for (int i = 0; i < t; i++)
		scanf("%ld", a + i);
	q.push(0);
	for (int i = 0; i < t; i++)
	{
		if (a[i] > 0)
			q.push(i);
		else
		{
			d = q.top();
			q.pop();
			if (a[d] == -a[i])
			{
				if (!q.empty())
					m = max(m, i - q.top());
				else
					q.push(i);
			}
			else
				q.push(i);
		}
	}
	printf("%ld\n", m);
	return 0;
}