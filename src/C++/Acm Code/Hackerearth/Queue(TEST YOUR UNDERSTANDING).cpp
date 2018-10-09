#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue <int> a;
	int n, x;
	char s;
	scanf("%d", &n);
	while (n--)
	{
		cin >> s;
		if (s == 'E')
		{
			scanf("%d", &x);
			a.push(x);
			printf("%d\n", a.size());
		}
		else
		{
			if(a.empty())
				printf("-1 0\n");
			else
			{
				int d = a.front();
				a.pop();
				printf("%d %d\n", d, a.size());
			}
		}
	}
	return 0;
}